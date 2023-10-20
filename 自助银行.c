/*p:菜单
  p1:存款金额小于零,重新输入金额！
  p2:密码错误！请重新输入！
  p3:是否返回菜单！
  p4:输入取款金额
  p5:重新输入密码
  p6:密码错误，重新输入
  p7:重新设置新密码
  p8:结束程序
  p9:重新输入开户金额
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int k=0; //业务编号
    char n=0;//用户姓名
    int id=0,id1=0;//id是账号，id1存放临时输入的账号
    int sid=0;//身份证号
    int psw=0,psw1=0,psw2=0;//psw是密码，psw1和psw2存放临时输入的密码
    int rpsw=0;//确认密码
    float money=0,money1=0;//开户金额，改变金额
    char  r;//是否返回菜单
    srand(time(0));//设置随机数种子
    printf("*************************************************************************************\n");
    printf("-------------------------------欢迎使用中国银行！------------------------------------\n");
    printf("*************************************************************************************\n");
p:  printf("----------1、开户 2、取款 3、存款  4、余额查询  5、修改密码 6、销户  7、退出--------------\n");
    printf("请选择要办理的业务：\n");
    scanf("%d",&k);//输入要办理的业务
    getchar();


     //程序无限循环
    while(1)
    {
        switch(k)
        {
            //开户
            case 1:
                    k=0;
                    printf("请输入姓名：\n");
                    scanf("%c",&n);
                    getchar();
                    //getchar();
                    printf("请输入身份证号：\n");
                    scanf("%d",&sid);
                    getchar();
p9:                 printf("请输入开户金额：\n");
                    scanf("%f",&money);
                    getchar();
                    if(money<0)
                    {
                        printf("开户金额不能小于零！重新输入！\n");
                        goto p9;
                    }
                    printf("请设置密码：\n");
                    scanf("%d",&psw);
                    getchar();
                    printf("请确认密码：\n");
                    scanf("%d",&rpsw);
                    getchar();
                    //两次密码对比，相同则开户成功，不同则开户失败！
                    if(rpsw==psw)
                    {
                        printf("开户成功！\n");
                        id=rand()%9000+1000;//生成4位随机账号
                        printf("你获得的账号是：%d\n",id);
                        printf("账户信息：\n");
                        printf("**************************************************************\n");
                        printf("**姓名:%c  账号：%d  身份证号：%d  密码：%d 开户金额：%.2f元**\n",n,id,sid,psw,money);
                        printf("**************************************************************\n");
p3:                     printf("是否返回菜单（y/n）：");
                        scanf("%c",&r);
                        getchar();
                        //判断是否返回菜单
                        if((r=='y')||(r=='Y'))
                        {
                            goto  p;//返回菜单
                        }
                        else
                        {
p8:                          printf("-------欢迎下次使用！------\n");
                             return 0;//结束程序
                        }
                    }
                    else
                    {
                        printf("两次密码不相同！开户失败！！！\n");
                        goto p3;
                    }
                    break;
            case 2:
                    k=0;
                    printf("请输入账号：\n");
                    scanf("%d",&id1);
                    getchar();
                    //账户存在
                    if(id1==id)
                    {
p2:                     printf("请输入密码：\n");
                        scanf("%d",&psw1);
                        getchar();
                        //密码正确
                        if(psw1==psw)
                        {
p4:                        printf("请输入取款金额：\n");
                           scanf("%f",&money1);
                           getchar();
                           //取款金额符合条件，成功取款
                           if(money>0&&money1<=money)
                           {
                               money-=money1;
                               printf("取款成功！余额为%.2f元\n",money);
                               goto p3;
                           }
                          //取款金额不符合条件，重新输入取款金额
                           else
                           {
                                if(money1<0)
                                {
                                     printf("取款金额不能小于零！重新输入取款金额！\n");
                                     goto p4;
                                }
                                else
                                {
                                    printf("取款金额超出余额！重新输入取款金额！\n");
                                    goto p4;
                                }
                           }
                        }
                        //密码错误，重新输入密码
                        else
                        {
                            printf("密码错误！请重新输入！\n");
                            goto p2;
                        }
                    }
                    //账户不存在
                    else
                    {
                        printf("当前账户不存在！\n");
                        goto p3;

                    }
                    break;
          case 3:
                    k=0;
                    printf("请输入账号：\n");
                    scanf("%d",&id1);
                    getchar();
                    //账号正确
                    if(id1==id)
                    {
p1:                    printf("请输入存款金额：\n");
                       scanf("%f",&money1);
                       getchar();
                       //判断存款金额是否大于零，大于零则存款小于零重新输入
                       if(money1>0)
                       {
                           money+=money1;
                           printf("存款成功！余额为%.2f元\n",money);
                           goto p3;
                       }
                       else
                       {
                           printf("存款金额小于零！\n");
                           goto p1;
                       }
                    }
                    //账户不存在
                    else
                    {
                        printf("当前账户不存在！\n");
                        goto p3;
                    }
                    break;
            case 4:
                    k=0;
                    printf("请输入账号：\n");
                    scanf("%d",&id1);
                    getchar();
                    //账号正确
                    if(id1==id)
                    {
                       //密码正确
p5:                     printf("请输入密码：\n");
                        scanf("%d",&psw1);
                        getchar();
                        //密码正确
                        if(psw1==psw)
                        {
                             printf("您的账户余额为%.2f元\n",money);
                             goto p3;
                        }
                        //密码错误
                        else
                        {
                            printf("密码错误！重新输入密码！\n");
                            goto p5;
                        }
                    }
                    //账户不存在
                    else
                    {
                        printf("当前账户不存在！\n");
                        goto p3;
                    }
                break;
            case 5:
                    k=0;
                    printf("请输入要修改密码的账号\n");
                    scanf("%d",&id1);
                    getchar();
                    //账号正确
                    if(id1==id)
                    {
                       //密码正确
p6:                     printf("请输入原密码：\n");
                        scanf("%d",&psw1);
                        getchar();
                        //密码正确
                        if(psw1==psw)
                        {
p7:                           printf("请设置新密码：\n");
                              scanf("%d",&psw1);
                              getchar();
                              printf("请确认新密码：\n");
                              scanf("%d",&psw2);
                              getchar();
                              //两次输入的新密码相同
                              if(psw2==psw1)
                              {
                                 psw=psw2; //修改原密码
                                 printf("修改密码成功！\n");
                                 goto p3;
                              }
                              //两次输入的新密码不相同
                              else
                              {
                                 printf("两次输入的新密码不相同，请重新输入！\n");
                                 goto p7;
                              }
                        }
                        //密码错误
                        else
                        {
                            printf("密码错误！重新输入密码！\n");
                            goto p6;
                        }
                    }
                    //账户不存在
                    else
                    {
                        printf("当前账户不存在！\n");
                        goto p3;
                    }
                break;
            case 6:
                k=0;
                printf("请输入账号\n");
                scanf("%d",&id1);
                getchar();
                //账号正确
                if(id1==id)
                {
                    //密码正确
                    printf("请输入密码：\n");
                    scanf("%d",&psw1);
                    getchar();
                    //密码正确
                    if(psw1==psw)
                    {
                        printf("销户成功！\n");
                        //信息初始化,销户
                        n=0;//用户姓名
                        id=0;//id是账号
                        sid=0;//身份证号
                        psw=0;//psw是密码
                        rpsw=0;//确认密码
                        money=0;//开户金额
                    }
                    //密码错误
                    else
                    {
                        printf("密码错误！\n");
                        goto p;//返回菜单
                    }
                }
                //账户不存在
                else
                {
                    printf("当前账户不存在！\n");
                    goto p;
                }
                break;
            case 7:
                goto p8;
                break;
            default:
                //输入的业务编号不合理
                printf("请输入1-7选择业务\n");
                goto p;
                break;
        }
    }
    return 0;
}





























//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct account
{
    char name[50];
    char address[100];
    int accno;
    float balance;
};

struct account account[MAX];
int count=0;

void create_account()
{
    char ch;
    int i;
    printf("Enter the name: ");
    scanf("%s",&account[count].name);

    printf("Enter the address: ");
    scanf("%s",&account[count].address);

    printf("Enter the account number: ");
    scanf("%d",&account[count].accno);

    printf("Enter the initial balance: ");
    scanf("%f",&account[count].balance);

    count++;
}

void deposit()
{
    char ch;
    int i,n;

    printf("Enter the account number to deposit: ");
    scanf("%d",&n);

    for(i=0;i<count;i++)
    {
        if(account[i].accno==n)
        {
            printf("Enter the amount to deposit: ");
            scanf("%f",&account[i].balance);
            printf("\nAmount deposited successfully!!");
            break;
        }
        else
        {
            printf("\nAccount not found!!");
        }
    }
}

void withdraw()
{
    char ch;
    int i,n;

    printf("Enter the account number to withdraw: ");
    scanf("%d",&n);

    for(i=0;i<count;i++)
    {
        if(account[i].accno==n)
        {
            printf("Enter the amount to withdraw: ");
            scanf("%f",&account[i].balance);
            printf("\nAmount withdrawn successfully!!");
            break;
        }
        else
        {
            printf("\nAccount not found!!");
        }
    }
}

void check_balance()
{
    char ch;
    int i,n;

    printf("Enter the account number to check balance: ");
    scanf("%d",&n);

    for(i=0;i<count;i++)
    {
        if(account[i].accno==n)
        {
            printf("\nCurrent balance: %.2f",account[i].balance);
            break;
        }
        else
        {
            printf("\nAccount not found!!");
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n\nBanking Record System\n");
        printf("1.Create account\n2.Deposit\n3.Withdraw\n4.Check balance\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                create_account();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                check_balance();
                break;

            case 5:
                printf("\nThank you for using our services!!");
                break;

            default:
                printf("\nInvalid choice!!");
        }
    }while(ch!=5);

    return 0;
}
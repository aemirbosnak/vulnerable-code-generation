//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct account
{
    char name[20];
    int account_number;
    float balance;
};

void create_account(struct account *a)
{
    printf("Enter name: ");
    scanf("%s",a->name);
    printf("Enter account number: ");
    scanf("%d",&a->account_number);
    printf("Enter initial balance: ");
    scanf("%f",&a->balance);
}

void deposit(struct account *a)
{
    printf("Enter amount to deposit: ");
    scanf("%f",&a->balance);
}

void withdraw(struct account *a)
{
    printf("Enter amount to withdraw: ");
    scanf("%f",&a->balance);
}

void check_balance(struct account *a)
{
    printf("Current balance: %.2f\n",a->balance);
}

void main()
{
    struct account a[MAX];
    int i,n=0,choice,flag=0;

    while(n<MAX)
    {
        printf("Enter 1 to create account, 0 to exit: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            if(n>=MAX)
            {
                printf("Cannot create more accounts\n");
            }
            else
            {
                create_account(&a[n]);
                n++;
            }
        }
        else if(choice==0)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    while(1)
    {
        system("clear");
        printf("Enter account number: ");
        scanf("%d",&choice);

        for(i=0;i<n;i++)
        {
            if(a[i].account_number==choice)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Account not found\n");
        }
        else
        {
            printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Back\n");

            scanf("%d",&choice);

            switch(choice)
            {
                case 1: deposit(&a[i]); break;
                case 2: withdraw(&a[i]); break;
                case 3: check_balance(&a[i]); break;
                case 4: system("clear"); break;
                default: printf("Invalid choice\n");
            }
        }
    }
}
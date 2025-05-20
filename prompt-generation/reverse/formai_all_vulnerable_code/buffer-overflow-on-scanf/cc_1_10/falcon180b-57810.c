//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct bank
{
    char name[50];
    char address[100];
    char account_number[10];
    float balance;
};

void deposit(struct bank *b)
{
    printf("\nEnter amount to deposit: ");
    scanf("%f",&b->balance);
}

void withdraw(struct bank *b)
{
    printf("\nEnter amount to withdraw: ");
    scanf("%f",&b->balance);
}

void display(struct bank b)
{
    printf("\nName: %s",b.name);
    printf("\nAddress: %s",b.address);
    printf("\nAccount Number: %s",b.account_number);
    printf("\nBalance: %.2f",b.balance);
}

void create_account(struct bank *b, int choice)
{
    char ch;
    printf("\nEnter 1 to deposit and 2 to withdraw: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            deposit(b);
            break;

        case 2:
            withdraw(b);
            break;

        default:
            printf("\nInvalid choice");
    }
}

int main()
{
    struct bank b[MAX];
    int i,j,choice;

    for(i=0;i<MAX;i++)
    {
        printf("\nEnter name: ");
        scanf("%s",b[i].name);

        printf("\nEnter address: ");
        scanf("%s",b[i].address);

        printf("\nEnter account number: ");
        scanf("%s",b[i].account_number);

        b[i].balance=0;
    }

    while(1)
    {
        printf("\n\nBanking System Menu:\n");
        printf("\n1. Create Account\n2. Display Account\n3. Exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter account number: ");
                scanf("%s",b[0].account_number);

                create_account(b,1);
                break;

            case 2:
                printf("\nEnter account number: ");
                scanf("%s",b[0].account_number);

                display(b[0]);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
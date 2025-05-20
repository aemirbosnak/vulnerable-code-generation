//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct account
{
    int accno;
    char name[50];
    char address[100];
    float balance;
};

struct account createAccount()
{
    struct account a;
    printf("Enter account number: ");
    scanf("%d",&a.accno);
    printf("Enter name: ");
    scanf("%s",a.name);
    printf("Enter address: ");
    scanf("%s",a.address);
    a.balance = 0;
    return a;
}

void deposit(struct account *a, float amt)
{
    a->balance += amt;
    printf("\nDeposit successful! New balance: %.2f",a->balance);
}

void withdraw(struct account *a, float amt)
{
    if(a->balance >= amt)
    {
        a->balance -= amt;
        printf("\nWithdrawal successful! New balance: %.2f",a->balance);
    }
    else
    {
        printf("\nInsufficient balance!");
    }
}

void display(struct account a)
{
    printf("\nAccount Number: %d",a.accno);
    printf("\nName: %s",a.name);
    printf("\nAddress: %s",a.address);
    printf("\nBalance: %.2f",a.balance);
}

int main()
{
    int choice, search;
    float amt;
    struct account a;

    a = createAccount();

    do
    {
        printf("\n\nBanking System\n");
        printf("1. Deposit\n2. Withdraw\n3. Display\n4. Search Account\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter amount to deposit: ");
                scanf("%f",&amt);
                deposit(&a,amt);
                break;

            case 2:
                printf("\nEnter amount to withdraw: ");
                scanf("%f",&amt);
                withdraw(&a,amt);
                break;

            case 3:
                display(a);
                break;

            case 4:
                printf("\nEnter account number to search: ");
                scanf("%d",&search);
                if(search == a.accno)
                {
                    printf("\nAccount found!");
                }
                else
                {
                    printf("\nAccount not found!");
                }
                break;

            case 5:
                printf("\nThank you for using our services!");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }

    }while(choice!= 5);

    return 0;
}
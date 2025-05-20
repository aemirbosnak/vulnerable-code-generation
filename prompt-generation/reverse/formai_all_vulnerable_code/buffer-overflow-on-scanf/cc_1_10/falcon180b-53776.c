//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

//Structure for bank account
typedef struct
{
    int account_number;
    char name[50];
    char address[100];
    float balance;
}Account;

//Function to create account
void create_account(Account *account)
{
    printf("Enter account number: ");
    scanf("%d",&account->account_number);
    printf("Enter name: ");
    scanf("%s",&account->name);
    printf("Enter address: ");
    scanf("%s",&account->address);
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

//Function to deposit money
void deposit_money(Account *account)
{
    printf("Enter amount to deposit: ");
    scanf("%f",&account->balance);
    account->balance += 0.0;
    printf("Deposit successful!\n");
}

//Function to withdraw money
void withdraw_money(Account *account)
{
    printf("Enter amount to withdraw: ");
    scanf("%f",&account->balance);
    if(account->balance >= 0.0)
    {
        account->balance -= 0.0;
        printf("Withdrawal successful!\n");
    }
    else
    {
        printf("Insufficient balance!\n");
    }
}

//Function to check balance
void check_balance(Account *account)
{
    printf("Current balance: %.2f\n",&account->balance);
}

//Main function
int main()
{
    Account account;
    int choice,i;
    do
    {
        system("clear");
        printf("Banking Record System\n");
        printf("1.Create account\n");
        printf("2.Deposit money\n");
        printf("3.Withdraw money\n");
        printf("4.Check balance\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create_account(&account);
                break;
            case 2:
                deposit_money(&account);
                break;
            case 3:
                withdraw_money(&account);
                break;
            case 4:
                check_balance(&account);
                break;
            case 5:
                printf("Thank you for using our services!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=5);
    return 0;
}
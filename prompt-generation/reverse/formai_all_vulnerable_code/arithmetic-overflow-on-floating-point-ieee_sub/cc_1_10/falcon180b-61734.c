//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Account
{
    int account_number;
    char name[50];
    char address[100];
    float balance;
};

void create_account(struct Account *account, int account_number, char name[50], char address[100], float balance)
{
    strcpy(account->name, name);
    strcpy(account->address, address);
    account->account_number = account_number;
    account->balance = balance;
}

void deposit_money(struct Account *account, float amount)
{
    account->balance += amount;
    printf("\nAmount deposited successfully! New balance: %.2f", account->balance);
}

void withdraw_money(struct Account *account, float amount)
{
    if(amount > account->balance)
    {
        printf("\nInsufficient balance!");
    }
    else
    {
        account->balance -= amount;
        printf("\nAmount withdrawn successfully! New balance: %.2f", account->balance);
    }
}

void display_account_details(struct Account account)
{
    printf("\nAccount Number: %d", account.account_number);
    printf("\nName: %s", account.name);
    printf("\nAddress: %s", account.address);
    printf("\nBalance: %.2f", account.balance);
}

int main()
{
    struct Account account;
    int choice, account_number;
    char name[50], address[100];
    float balance, amount;

    printf("\nWelcome to the Banking System!");
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("\nEnter your address: ");
    scanf("%s", address);
    printf("\nEnter initial balance: ");
    scanf("%f", &balance);

    create_account(&account, 12345, name, address, balance);
    display_account_details(account);

    do
    {
        printf("\nChoose an option:\n1. Deposit money\n2. Withdraw money\n3. Check balance\n4. Exit");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);
                deposit_money(&account, amount);
                break;

            case 2:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw_money(&account, amount);
                break;

            case 3:
                display_account_details(account);
                break;

            case 4:
                printf("\nThank you for using our services!");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!= 4);

    return 0;
}
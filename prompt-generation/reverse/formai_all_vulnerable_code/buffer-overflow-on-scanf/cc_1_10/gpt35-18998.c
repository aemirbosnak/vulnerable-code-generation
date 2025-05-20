//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000

// Struct for an account
typedef struct account
{
    int account_number;
    char owner_name[30];
    int balance;
} Account;

// Array for storing all accounts
Account accounts[MAX_ACCOUNTS];

// Variables for keeping track of the number of accounts and the next available account number
int total_accounts = 0;
int next_account_number = 1000;

// Function for creating a new account
void create_account()
{
    // Check if there is space for a new account
    if (total_accounts >= MAX_ACCOUNTS)
    {
        printf("Cannot create account. Maximum number of accounts reached.\n");
        return;
    }

    // Get owner name and initial balance
    char owner_name[30];
    printf("Enter owner name: ");
    scanf("%s", owner_name);

    int balance;
    printf("Enter initial balance: ");
    scanf("%d", &balance);

    // Create new account
    Account new_account;
    new_account.account_number = next_account_number++;
    strcpy(new_account.owner_name, owner_name);
    new_account.balance = balance;

    accounts[total_accounts++] = new_account;

    printf("Account created successfully. Account number is %d.\n", new_account.account_number);
}

// Function for checking the balance of an account
void check_balance()
{
    // Get account number
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Find account by account number
    int i;
    for (i = 0; i < total_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            printf("Balance of account %d is %d.\n", account_number, accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function for depositing money into an account
void deposit()
{
    // Get account number
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Find account by account number
    int i;
    for (i = 0; i < total_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            // Get deposit amount
            int deposit_amount;
            printf("Enter deposit amount: ");
            scanf("%d", &deposit_amount);

            // Update account balance
            accounts[i].balance += deposit_amount;

            printf("%d deposited into account %d.\n", deposit_amount, account_number);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function for withdrawing money from an account
void withdraw()
{
    // Get account number
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Find account by account number
    int i;
    for (i = 0; i < total_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            // Get withdrawal amount
            int withdrawal_amount;
            printf("Enter withdrawal amount: ");
            scanf("%d", &withdrawal_amount);

            // Check if account has enough balance for withdrawal
            if (accounts[i].balance >= withdrawal_amount)
            {
                // Update account balance
                accounts[i].balance -= withdrawal_amount;

                printf("%d withdrawn from account %d.\n", withdrawal_amount, account_number);
                return;
            }
            else
            {
                printf("Insufficient balance.\n");
                return;
            }
        }
    }

    printf("Account not found.\n");
}

// Function for displaying all accounts
void display_accounts()
{
    printf("Account Number\tOwner Name\tBalance\n");

    int i;
    for (i = 0; i < total_accounts; i++)
    {
        printf("%d\t\t%s\t\t%d\n", accounts[i].account_number, accounts[i].owner_name, accounts[i].balance);
    }
}

// Main function
int main()
{
    int option;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Display All Accounts\n");
        printf("0. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                create_account();
                break;

            case 2:
                check_balance();
                break;

            case 3:
                deposit();
                break;

            case 4:
                withdraw();
                break;

            case 5:
                display_accounts();
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
        }
    } while (option != 0);

    return 0;
}
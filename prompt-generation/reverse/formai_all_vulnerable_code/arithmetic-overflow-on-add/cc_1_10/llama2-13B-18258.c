//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALANCE 100000
#define INTEREST_RATE 0.05
#define MIN_DEPOSIT 100
#define MIN_WITHDRAW 50

typedef struct
{
    int balance;
    int interest_earned;
} account_t;

void deposit(account_t *account, int amount);
void withdraw(account_t *account, int amount);
void calculate_interest(account_t *account);

int main()
{
    account_t account;
    int choice;

    printf("Welcome to the banking system!\n");

    do
    {
        printf("Please select an option:\n");
        printf("1. Deposit money\n");
        printf("2. Withdraw money\n");
        printf("3. Calculate interest\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deposit(&account, 1000);
                break;

            case 2:
                withdraw(&account, 500);
                break;

            case 3:
                calculate_interest(&account);
                break;

            case 4:
                return 0;
                break;

            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void deposit(account_t *account, int amount)
{
    if (amount > 0 && account->balance + amount <= MAX_BALANCE)
    {
        account->balance += amount;
        account->interest_earned = 0;
    }
    else
    {
        printf("Insufficient balance or amount too large\n");
    }
}

void withdraw(account_t *account, int amount)
{
    if (amount > 0 && account->balance >= amount)
    {
        account->balance -= amount;
        account->interest_earned = 0;
    }
    else
    {
        printf("Insufficient balance\n");
    }
}

void calculate_interest(account_t *account)
{
    if (account->balance > 0)
    {
        account->interest_earned = account->balance * INTEREST_RATE;
    }
    else
    {
        account->interest_earned = 0;
    }
}
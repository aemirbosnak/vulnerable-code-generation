//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int account_number;
    char account_name[50];
    float balance;
} BankAccount;

int main()
{
    int size_of_array = 0;
    printf("Darling, how many bank accounts do we have?\n");
    scanf("%d", &size_of_array);

    BankAccount accounts[size_of_array];

    for (int i = 0; i < size_of_array; i++)
    {
        printf("Please tell me the account number and account name of our love account number %d:\n", i+1);
        scanf("%d %s", &accounts[i].account_number, accounts[i].account_name);
        accounts[i].balance = 0;
        printf("Thank you, my sweetie. I have recorded that.\n");
    }

    bool running = true;
    while (running)
    {
        int option;
        printf("What would you like to do now, my love?\n");
        printf("1. Deposit money to an account\n");
        printf("2. Withdraw money from an account\n");
        printf("3. View account balance\n");
        printf("4. Quit\n");

        scanf("%d", &option);

        if (option == 1)
        {
            int account_number;
            float deposit_amount;
            printf("Which account would like to deposit into?\n");
            scanf("%d", &account_number);
            printf("How much would you like to deposit, my love?\n");
            scanf("%f", &deposit_amount);

            bool account_found = false;
            for (int i = 0; i < size_of_array; i++)
            {
                if (accounts[i].account_number == account_number)
                {
                    accounts[i].balance += deposit_amount;
                    printf("Deposit successful, my darling. The new balance for account %d is %.2f.\n", account_number, accounts[i].balance);
                    account_found = true;
                    break;
                }
            }

            if (!account_found)
            {
                printf("I'm sorry, my love. That account does not exist.\n");
            }
        }
        else if (option == 2)
        {
            int account_number;
            float withdraw_amount;
            printf("Which account would like to withdraw from?\n");
            scanf("%d", &account_number);

            bool account_found = false;
            for (int i = 0; i < size_of_array; i++)
            {
                if (accounts[i].account_number == account_number)
                {
                    printf("How much would you like to withdraw, my love?\n");
                    scanf("%f", &withdraw_amount);

                    if (accounts[i].balance >= withdraw_amount)
                    {
                        accounts[i].balance -= withdraw_amount;
                        printf("Withdrawal successful, my darling. The new balance for account %d is %.2f.\n", account_number, accounts[i].balance);
                    }
                    else
                    {
                        printf("I'm sorry, my love. The account balance is not enough for the withdrawal.\n");
                    }

                    account_found = true;
                    break;
                }
            }

            if (!account_found)
            {
                printf("I'm sorry, my love. That account does not exist.\n");
            }
        }
        else if (option == 3)
        {
            int account_number;
            printf("Which account would you like to view the balance of?\n");
            scanf("%d", &account_number);

            bool account_found = false;
            for (int i = 0; i < size_of_array; i++)
            {
                if (accounts[i].account_number == account_number)
                {
                    printf("The account balance for account %d is %.2f.\n", account_number, accounts[i].balance);
                    account_found = true;
                    break;
                }
            }

            if (!account_found)
            {
                printf("I'm sorry, my love. That account does not exist.\n");
            }
        }
        else if (option == 4)
        {
            printf("Goodbye, my love. I'll always be here for you whenever you need me.\n");
            running = false;
        }
        else
        {
            printf("I'm sorry, my love. That is an invalid option.\n");
        }
    }

    return 0;
}
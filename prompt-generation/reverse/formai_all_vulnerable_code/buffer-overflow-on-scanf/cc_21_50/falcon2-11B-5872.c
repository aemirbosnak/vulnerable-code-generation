//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT 10
#define MAX_NAME 50
#define MAX_NUM 10

struct Account
{
    char name[MAX_NAME];
    int num;
};

struct Account accounts[MAX_ACCOUNT];

int main()
{
    int choice, account_num, amount, i;
    char name[MAX_NAME];

    printf("Welcome to the Bank!\n");
    printf("1. Create an account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Check balance\n");
    printf("5. Close an account\n");
    printf("6. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num < 0 || account_num >= MAX_ACCOUNT)
                {
                    printf("Invalid account number!\n");
                }
                else
                {
                    printf("Enter account holder name: ");
                    scanf("%s", name);

                    accounts[account_num].num = account_num;
                    strcpy(accounts[account_num].name, name);
                    printf("Account created successfully!\n");
                }
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num < 0 || account_num >= MAX_ACCOUNT)
                {
                    printf("Invalid account number!\n");
                }
                else
                {
                    printf("Enter deposit amount: ");
                    scanf("%d", &amount);

                    if (amount < 0 || amount > 9999)
                    {
                        printf("Invalid deposit amount!\n");
                    }
                    else
                    {
                        accounts[account_num].num = account_num;
                        accounts[account_num].num = accounts[account_num].num + amount;
                        printf("Deposit successful!\n");
                    }
                }
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num < 0 || account_num >= MAX_ACCOUNT)
                {
                    printf("Invalid account number!\n");
                }
                else
                {
                    printf("Enter withdrawal amount: ");
                    scanf("%d", &amount);

                    if (amount < 0 || amount > 9999)
                    {
                        printf("Invalid withdrawal amount!\n");
                    }
                    else if (amount > accounts[account_num].num)
                    {
                        printf("Insufficient balance!\n");
                    }
                    else
                    {
                        accounts[account_num].num = accounts[account_num].num - amount;
                        printf("Withdrawal successful!\n");
                    }
                }
                break;

            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num < 0 || account_num >= MAX_ACCOUNT)
                {
                    printf("Invalid account number!\n");
                }
                else
                {
                    printf("Account balance: %d\n", accounts[account_num].num);
                }
                break;

            case 5:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num < 0 || account_num >= MAX_ACCOUNT)
                {
                    printf("Invalid account number!\n");
                }
                else
                {
                    printf("Are you sure you want to close this account? (y/n): ");
                    char ch;
                    scanf("%c", &ch);

                    if (ch == 'y' || ch == 'Y')
                    {
                        for (i = 0; i < MAX_ACCOUNT; i++)
                        {
                            if (accounts[i].num == account_num)
                            {
                                strcpy(accounts[i].name, "");
                                accounts[i].num = -1;
                                printf("Account closed successfully!\n");
                                break;
                            }
                        }
                    }
                }
                break;

            case 6:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice!= 6);

    return 0;
}
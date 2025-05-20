//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct Account
{
    char name[20];
    int account_number;
    double balance;
    struct Account* next;
};

void createAccount(struct Account** head)
{
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    printf("Enter account name: ");
    scanf("%s", newAccount->name);
    printf("Enter account number: ");
    scanf("%d", &newAccount->account_number);
    printf("Enter initial deposit: ");
    scanf("%lf", &newAccount->balance);

    if (*head == NULL)
    {
        *head = newAccount;
    }
    else
    {
        (*head)->next = newAccount;
    }
}

void deposit(struct Account* head)
{
    struct Account* currentAccount = head;
    int depositAmount;

    printf("Enter account number: ");
    scanf("%d", &depositAmount);

    while (currentAccount)
    {
        if (currentAccount->account_number == depositAmount)
        {
            printf("Enter deposit amount: ");
            scanf("%lf", &depositAmount);
            currentAccount->balance += depositAmount;
            printf("Deposit successful!\n");
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (currentAccount == NULL)
    {
        printf("Account not found.\n");
    }
}

void withdraw(struct Account* head)
{
    struct Account* currentAccount = head;
    int withdrawAmount;

    printf("Enter account number: ");
    scanf("%d", &withdrawAmount);

    while (currentAccount)
    {
        if (currentAccount->account_number == withdrawAmount)
        {
            printf("Enter withdrawal amount: ");
            scanf("%lf", &withdrawAmount);
            currentAccount->balance -= withdrawAmount;
            printf("Withdrawal successful!\n");
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (currentAccount == NULL)
    {
        printf("Account not found.\n");
    }
}

int main()
{
    struct Account* head = NULL;

    while (1)
    {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount(&head);
                break;
            case 2:
                deposit(head);
                break;
            case 3:
                withdraw(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}
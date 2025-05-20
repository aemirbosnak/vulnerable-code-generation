//FormAI DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Account {
    int account_number;
    char name[MAX];
    float balance;
};

int size = 0;
struct Account account_list[MAX];

void insert_account(int account_number, char name[], float balance);
void view_all_accounts();
void view_account(int account_number);
void withdraw_amount(int account_number, float amount);
void deposit_amount(int account_number, float amount);
int search_account(int account_number);

int main()
{
    int choice, account_number;
    char name[MAX];
    float balance, amount;

    while (1) {
        printf("\n\n========= BANK RECORD SYSTEM =========");
        printf("\n1. Add Account");
        printf("\n2. View All Accounts");
        printf("\n3. View Account");
        printf("\n4. Withdraw Amount");
        printf("\n5. Deposit Amount");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                getchar();
                printf("Enter Name: ");
                fgets(name, MAX, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Balance: ");
                scanf("%f", &balance);
                insert_account(account_number, name, balance);
                break;
            case 2:
                view_all_accounts();
                break;
            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                view_account(account_number);
                break;
            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Withdraw: ");
                scanf("%f", &amount);
                withdraw_amount(account_number, amount);
                break;
            case 5:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Deposit: ");
                scanf("%f", &amount);
                deposit_amount(account_number, amount);
                break;
            case 6:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Try Again.\n");
                break;
        }
    }

    return 0;
}

void insert_account(int account_number, char name[], float balance)
{
    struct Account account;
    account.account_number = account_number;
    strcpy(account.name, name);
    account.balance = balance;
    account_list[size++] = account;
    printf("\nAccount added successfully.\n");
}

void view_all_accounts()
{
    int i;
    if (size == 0) {
        printf("\nNo Accounts Found.\n");
        return;
    }
    printf("\n=====================================");
    printf("\nAccount Number\tName\t\tBalance\n");
    printf("=====================================\n");
    for (i = 0; i < size; i++) {
        printf("%d\t\t%s\t\t%.2f\n", account_list[i].account_number, account_list[i].name, account_list[i].balance);
    }
    printf("=====================================\n");
}

void view_account(int account_number)
{
    int index = search_account(account_number);
    if (index == -1) {
        printf("\nAccount not found.\n");
        return;
    }
    printf("\n=====================================");
    printf("\nAccount Number: %d", account_list[index].account_number);
    printf("\nName: %s", account_list[index].name);
    printf("Balance: %.2f\n", account_list[index].balance);
    printf("=====================================\n");
}

void withdraw_amount(int account_number, float amount)
{
    int index = search_account(account_number);
    if (index == -1) {
        printf("\nAccount not found.\n");
        return;
    }
    if (account_list[index].balance < amount) {
        printf("\nInsufficient Balance.\n");
        return;
    }
    account_list[index].balance -= amount;
    printf("\nWithdrawn %.2f successfully.\n", amount);
}

void deposit_amount(int account_number, float amount)
{
    int index = search_account(account_number);
    if (index == -1) {
        printf("\nAccount not found.\n");
        return;
    }
    account_list[index].balance += amount;
    printf("\nDeposited %.2f successfully.\n", amount);
}

int search_account(int account_number)
{
    int i;
    for (i = 0; i < size; i++) {
        if (account_list[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}
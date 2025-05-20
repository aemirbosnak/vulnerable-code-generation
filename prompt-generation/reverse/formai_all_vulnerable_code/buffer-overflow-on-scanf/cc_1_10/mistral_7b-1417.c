//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NAME_SIZE 50
#define ACCOUNT_BALANCE_SIZE sizeof(float)

typedef struct Account {
    char name[ACCOUNT_NAME_SIZE];
    float balance;
    float interest_rate;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account();
void delete_account();
void display_accounts();

int main() {
    int choice;
    do {
        printf("1. Add account\n");
        printf("2. Delete account\n");
        printf("3. Display accounts\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                delete_account();
                break;
            case 3:
                display_accounts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);

    return 0;
}

void add_account() {
    Account new_account;

    printf("Enter account name: ");
    scanf("%s", new_account.name);
    printf("Enter account balance: ");
    scanf("%f", &new_account.balance);
    printf("Enter account interest rate: ");
    scanf("%f", &new_account.interest_rate);

    accounts[num_accounts++] = new_account;
}

void delete_account() {
    int index;
    char name[ACCOUNT_NAME_SIZE];

    printf("Enter account name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        for (int i = index; i < num_accounts - 1; i++) {
            accounts[i] = accounts[i+1];
        }
        num_accounts--;
    } else {
        printf("Account not found!\n");
    }
}

void display_accounts() {
    printf("Name\tBalance\tInterest Rate\n");

    for (int i = 0; i < num_accounts; i++) {
        printf("%s\t%.2f\t%.2f%%\n", accounts[i].name, accounts[i].balance, accounts[i].interest_rate * 100);
    }
}
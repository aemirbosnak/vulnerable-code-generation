//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ACCOUNTS 5
#define MAX_ACCOUNT_NAME_LENGTH 20
#define MAX_ACCOUNT_BALANCE_LENGTH 10

typedef struct {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    int balance;
} Account;

typedef struct {
    int num_accounts;
    Account accounts[MAX_NUM_ACCOUNTS];
} PersonalFinancePlanner;

void print_accounts(PersonalFinancePlanner* pfp) {
    int i;
    printf("Accounts:\n");
    for (i = 0; i < pfp->num_accounts; i++) {
        printf("Name: %s, Balance: %d\n", pfp->accounts[i].name, pfp->accounts[i].balance);
    }
}

void add_account(PersonalFinancePlanner* pfp, const char* name, int balance) {
    if (pfp->num_accounts >= MAX_NUM_ACCOUNTS) {
        printf("Cannot add account, too many accounts already added.\n");
        return;
    }
    strncpy(pfp->accounts[pfp->num_accounts].name, name, MAX_ACCOUNT_NAME_LENGTH);
    pfp->accounts[pfp->num_accounts].balance = balance;
    pfp->num_accounts++;
}

int main() {
    PersonalFinancePlanner pfp;
    int choice, account_num, balance;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please select an option:\n");
    printf("1. Add an account\n");
    printf("2. Print all accounts\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter the name of the account: ");
                scanf("%s", pfp.accounts[pfp.num_accounts].name);
                printf("Enter the initial balance: ");
                scanf("%d", &balance);
                add_account(&pfp, pfp.accounts[pfp.num_accounts].name, balance);
                break;
            case 2:
                print_accounts(&pfp);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Please select an option:\n");
        printf("1. Add an account\n");
        printf("2. Print all accounts\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("Bye!\n");
    return 0;
}
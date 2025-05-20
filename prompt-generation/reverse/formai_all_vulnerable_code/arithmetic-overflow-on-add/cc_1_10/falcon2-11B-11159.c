//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT 100
#define MAX_ACCOUNT_NAME 20
#define MAX_ACCOUNT_BALANCE 10

struct Account {
    char name[MAX_ACCOUNT_NAME];
    int balance;
};

struct Account account[MAX_ACCOUNT];
int account_count = 0;

void createAccount(struct Account* account, int balance, char* name) {
    if (account_count >= MAX_ACCOUNT) {
        printf("Maximum account limit reached.\n");
        return;
    }

    strcpy(account[account_count].name, name);
    account[account_count].balance = balance;
    account_count++;
}

int deposit(struct Account* account, int amount) {
    if (amount < 0) {
        printf("Invalid amount to deposit.\n");
        return -1;
    }

    account[account_count - 1].balance += amount;
    printf("Deposit successful. New balance: %d\n", account[account_count - 1].balance);
    return 0;
}

int withdraw(struct Account* account, int amount) {
    if (amount < 0) {
        printf("Invalid amount to withdraw.\n");
        return -1;
    }

    if (account[account_count - 1].balance < amount) {
        printf("Insufficient funds.\n");
        return -1;
    }

    account[account_count - 1].balance -= amount;
    printf("Withdrawal successful. New balance: %d\n", account[account_count - 1].balance);
    return 0;
}

int main() {
    int choice;
    struct Account account1, account2;

    while (1) {
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. List Accounts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account name: ");
                fgets(account1.name, sizeof(account1.name), stdin);
                printf("Enter initial balance: ");
                scanf("%d", &account1.balance);
                createAccount(&account1, account1.balance, account1.name);
                break;
            case 2:
                printf("Enter account name: ");
                fgets(account1.name, sizeof(account1.name), stdin);
                deposit(&account1, 100);
                break;
            case 3:
                printf("Enter account name: ");
                fgets(account1.name, sizeof(account1.name), stdin);
                withdraw(&account1, 50);
                break;
            case 4:
                printf("Accounts:\n");
                for (int i = 0; i < account_count; i++) {
                    printf("Account %d: %s\n", i + 1, account[i].name);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
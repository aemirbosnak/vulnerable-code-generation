//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANSACTION_LIMIT 100

typedef struct {
    char name[NAME_LENGTH];
    float balance;
    char transactions[TRANSACTION_LIMIT][50]; // Store transactions as strings
    int transaction_count;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts.\n");
        return;
    }
    Account new_account;
    new_account.balance = 0;
    new_account.transaction_count = 0;
    printf("Enter your name: ");
    scanf("%s", new_account.name);
    accounts[account_count++] = new_account;
    printf("Account created for %s successfully!\n", new_account.name);
}

void deposit() {
    char name[NAME_LENGTH];
    float amount;
    printf("Enter account name to deposit: ");
    scanf("%s", name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid deposit amount.\n");
                return;
            }
            accounts[i].balance += amount;
            sprintf(accounts[i].transactions[accounts[i].transaction_count++], "Deposited: %.2f", amount);
            printf("Successfully deposited %.2f in %s's account.\n", amount, name);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    char name[NAME_LENGTH];
    float amount;
    printf("Enter account name to withdraw: ");
    scanf("%s", name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0 || amount > accounts[i].balance) {
                printf("Invalid withdrawal amount.\n");
                return;
            }
            accounts[i].balance -= amount;
            sprintf(accounts[i].transactions[accounts[i].transaction_count++], "Withdrew: %.2f", amount);
            printf("Successfully withdrew %.2f from %s's account.\n", amount, name);
            return;
        }
    }
    printf("Account not found.\n");
}

void check_balance() {
    char name[NAME_LENGTH];
    printf("Enter account name to check balance: ");
    scanf("%s", name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("%s's balance: %.2f\n", name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void transaction_history() {
    char name[NAME_LENGTH];
    printf("Enter account name to view transactions: ");
    scanf("%s", name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Transaction history for %s:\n", name);
            for (int j = 0; j < accounts[i].transaction_count; j++) {
                printf("%s\n", accounts[i].transactions[j]);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                transaction_history();
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option, please select a valid one.\n");
        }
    } while (choice != 6);
    
    return 0;
}
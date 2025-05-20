//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANS_COUNT 10

typedef struct Transaction {
    char type[10]; // e.g., "Deposit" or "Withdraw"
    float amount;
} Transaction;

typedef struct Account {
    char name[NAME_LENGTH];
    float balance;
    Transaction transactions[TRANS_COUNT];
    int trans_count;
} Account;

Account bankAccounts[MAX_ACCOUNTS];
int accountCount = 0;

void surrealGreeting() {
    printf("Welcome to the Bank of Surreal Dreams!\n");
    printf("Here, the numbers dance and the money sings.\n");
    printf("Let's embark on a whimsical adventure in finance!\n");
}

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("The cosmos has limits, no more accounts can be created!\n");
        return;
    }

    Account newAccount;
    printf("Enter the name of the dreamer (account holder): ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;
    newAccount.trans_count = 0;
    
    bankAccounts[accountCount++] = newAccount;
    printf("Ah! A new star has been born in our vast financial universe!\n");
}

void deposit(Account *acc) {
    float amount;
    printf("How much will you sprinkle into the ethereal crystals of your account? ");
    scanf("%f", &amount);
    acc->balance += amount;
    
    Transaction trans = { "Deposit", amount };
    acc->transactions[acc->trans_count++] = trans;
    printf("The shimmering coins have been added to your dreams, balance: %.2f\n", acc->balance);
}

void withdraw(Account *acc) {
    float amount;
    printf("How much of your dreams will you release into the universe? ");
    scanf("%f", &amount);
    
    if (amount > acc->balance) {
        printf("Alas! You cannot withdraw more than you possess, the spirit of balance forbids it!\n");
    } else {
        acc->balance -= amount;
        
        Transaction trans = { "Withdraw", amount };
        acc->transactions[acc->trans_count++] = trans;
        printf("The dreams have flown away, balance left: %.2f\n", acc->balance);
    }
}

void viewAccount(Account *acc) {
    printf("\nAccount Holder: %s\n", acc->name);
    printf("Current Balance: %.2f\n", acc->balance);
    printf("Transactions:\n");
    for (int i = 0; i < acc->trans_count; i++) {
        printf("  %s of %.2f\n", acc->transactions[i].type, acc->transactions[i].amount);
    }
}

void surrealExperience() {
    int choice, accountId;

    while (1) {
        printf("\n---- Dream Menu ----\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account\n");
        printf("5. Exit the Dream\n");
        printf("Choose your path: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAccount();
                break;
            case 2:
                printf("Enter account number (0 to %d): ", accountCount - 1);
                scanf("%d", &accountId);
                if (accountId < 0 || accountId >= accountCount) {
                    printf("An uncharted territory! Please choose a valid account.\n");
                } else {
                    deposit(&bankAccounts[accountId]);
                }
                break;
            case 3:
                printf("Enter account number (0 to %d): ", accountCount - 1);
                scanf("%d", &accountId);
                if (accountId < 0 || accountId >= accountCount) {
                    printf("An uncharted territory! Please choose a valid account.\n");
                } else {
                    withdraw(&bankAccounts[accountId]);
                }
                break;
            case 4:
                printf("Enter account number (0 to %d): ", accountCount - 1);
                scanf("%d", &accountId);
                if (accountId < 0 || accountId >= accountCount) {
                    printf("An uncharted territory! Please choose a valid account.\n");
                } else {
                    viewAccount(&bankAccounts[accountId]);
                }
                break;
            case 5:
                printf("The dream ends, and the curtain falls. Until next time!\n");
                exit(0);
            default:
                printf("A fork in the path! Please choose a valid option.\n");
        }
    }
}

int main() {
    surrealGreeting();
    surrealExperience();
    return 0;
}
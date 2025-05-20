//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayAccounts() {
    if (accountCount == 0) {
        printf("Whaat! No accounts found. Are you living under a rock?\n");
        return;
    }
    printf("Current Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Oh no! Maximum accounts reached! Can't create new account!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // simple account number assignment
    
    printf("Enter account holder's name: ");
    getchar(); // clear newline character from buffer
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // remove newline
    
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    
    accounts[accountCount++] = newAccount;
    printf("Account created! Number: %d, Next time it might explode!\n", newAccount.accountNumber);
}

void deleteAccount() {
    if (accountCount == 0) {
        printf("No accounts to delete! Is this a prank?\n");
        return;
    }
    
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Whoa! Invalid account number. It seems to vanish into thin air!\n");
        return;
    }
    
    for (int i = accountNumber - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    
    accountCount--;
    printf("Account number %d deleted! Hope nothing shady was going on...\n", accountNumber);
}

void viewAccount() {
    if (accountCount == 0) {
        printf("Whaat! No accounts to view! Is the universe playing tricks on us?\n");
        return;
    }

    int accountNumber;
    printf("Enter account number to view: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Tsk tsk! Invalid account number!\n");
        return;
    }

    printf("Account Number: %d\nHolder: %s\nBalance: %.2f\n", 
           accounts[accountNumber - 1].accountNumber, 
           accounts[accountNumber - 1].name, 
           accounts[accountNumber - 1].balance);
           
    printf("And guess what? This balance might just disappear!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. View Specific Account\n");
        printf("4. Delete Account\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            viewAccount();
            break;
        case 4:
            deleteAccount();
            break;
        case 5:
            printf("You’ve chosen to exit. May chaos reign unchecked!\n");
            exit(0);
        default:
            printf("Unexpected choice! Surprised you didn’t blow up the system!\n");
            break;
        }
    }

    return 0;
}
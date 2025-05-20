//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 30
#define PASSWORD_LENGTH 20
#define OPTION_LENGTH 10

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
    char password[PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void viewAccount();
void deposit();
void withdraw();
void displayAllAccounts();

int main() {
    int choice;

    printf("** Welcome to the C Banking Record System! **\n");
    printf("============================================\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: displayAllAccounts(); break;
            case 6: printf("Thank you for using our Banking System! Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts, limit reached!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = 0.0f;

    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    
    printf("Set a password: ");
    scanf("%s", newAccount.password);

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void viewAccount() {
    int accountNumber;
    char password[PASSWORD_LENGTH];

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    printf("Enter your password: ");
    scanf("%s", password);

    if (accountNumber <= accountCount && strcmp(accounts[accountNumber - 1].password, password) == 0) {
        printf("\nAccount Details:\n");
        printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
        printf("Name: %s\n", accounts[accountNumber - 1].name);
        printf("Balance: $%.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number or password!\n");
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        
        if (amount > 0) {
            accounts[accountNumber - 1].balance += amount;
            printf("Successfully deposited $%.2f into account %d. New balance is $%.2f.\n",
                   amount, accountNumber, accounts[accountNumber - 1].balance);
        } else {
            printf("Invalid deposit amount!\n");
        }
    } else {
        printf("Invalid account number!\n");
    }
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        
        if (amount > 0 && amount <= accounts[accountNumber - 1].balance) {
            accounts[accountNumber - 1].balance -= amount;
            printf("Successfully withdrew $%.2f from account %d. New balance is $%.2f.\n",
                   amount, accountNumber, accounts[accountNumber - 1].balance);
        } else {
            printf("Invalid or insufficient funds for withdrawal!\n");
        }
    } else {
        printf("Invalid account number!\n");
    }
}

void displayAllAccounts() {
    printf("\n** List of All Accounts **\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", 
                accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}
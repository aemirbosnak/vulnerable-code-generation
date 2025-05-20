//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char accountHolderName[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function declarations
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAccounts();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while(1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccounts();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

void createAccount() {
    if(accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.accountHolderName);
    newAccount.balance = 0.0;
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n",
           amount, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if(amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds! Current balance: %.2f\n",
               accounts[accountNumber - 1].balance);
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Successfully withdrew %.2f. New balance: %.2f\n",
               amount, accounts[accountNumber - 1].balance);
    }
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Current balance for account %d (%s): %.2f\n",
           accounts[accountNumber - 1].accountNumber,
           accounts[accountNumber - 1].accountHolderName,
           accounts[accountNumber - 1].balance);
}

void displayAccounts() {
    if(accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- Account List ---\n");
    for(int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder Name: %s\n", accounts[i].accountHolderName);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}
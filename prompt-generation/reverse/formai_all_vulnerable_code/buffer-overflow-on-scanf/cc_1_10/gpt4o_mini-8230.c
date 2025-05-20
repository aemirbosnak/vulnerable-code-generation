//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

struct Account {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum account limit reached.\n");
        return;
    }
    
    struct Account newAccount;
    printf("Enter Account Holder's Name: ");
    scanf("%s", newAccount.name);
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = 0.0f;

    accounts[accountCount++] = newAccount;
    printf("Account created! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to Account Number %d. New Balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Error: Insufficient balance.\n");
        return;
    }
    
    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrawn %.2f from Account Number %d. New Balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void viewAccount() {
    int accountNumber;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }
    
    struct Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder's Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("List of All Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        struct Account acc = accounts[i];
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               acc.accountNumber, acc.name, acc.balance);
    }
}

void menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            viewAccount();
            break;
        case 5:
            displayAllAccounts();
            break;
        case 6:
            printf("Exiting the system. Thank you!\n");
            break;
        default:
            printf("Error: Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold account details
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount(struct Account *accounts, int *accountCount);
void viewAccounts(struct Account *accounts, int accountCount);
void deposit(struct Account *accounts, int accountCount);
void withdraw(struct Account *accounts, int accountCount);

int main() {
    struct Account accounts[100]; // Array to hold up to 100 accounts
    int accountCount = 0;          // Keep track of the number of accounts
    int choice;

    printf("🎉 Welcome to the Happy Banking Record System! 🎉\n");
    while (1) {
        printf("\n🤔 What would you like to do?\n");
        printf("1. Create a new account\n");
        printf("2. View all accounts\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                viewAccounts(accounts, accountCount);
                break;
            case 3:
                deposit(accounts, accountCount);
                break;
            case 4:
                withdraw(accounts, accountCount);
                break;
            case 5:
                printf("🚪 Thank you for using our banking system! Goodbye! 👋\n");
                exit(0);
            default:
                printf("❗ Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new account
void createAccount(struct Account *accounts, int *accountCount) {
    printf("🎈 Creating a new account 🎈\n");
    struct Account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter your name: ");
    scanf("%s", newAccount.name); // Use %s for string input
    newAccount.balance = 0; // Initial balance set to 0

    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    printf("🎊 Account created successfully! 🎊\n");
}

// Function to view all accounts
void viewAccounts(struct Account *accounts, int accountCount) {
    if (accountCount == 0) {
        printf("😢 No accounts available to view!\n");
        return;
    }
    printf("📜 List of all accounts 📜\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

// Function to deposit money
void deposit(struct Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("💰 Deposit Money 💰\n");
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    // Search for account
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount; // Increase balance
            printf("✅ $%.2f deposited to account number %d. New balance: $%.2f\n", amount, accountNumber, accounts[i].balance);
            return;
        }
    }
    printf("❌ Account number not found! Please try again.\n");
}

// Function to withdraw money
void withdraw(struct Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("💵 Withdraw Money 💵\n");
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    // Search for account
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("❗ Insufficient balance! Current balance: $%.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount; // Decrease balance
                printf("✅ $%.2f withdrawn from account number %d. New balance: $%.2f\n", amount, accountNumber, accounts[i].balance);
            }
            return;
        }
    }
    printf("❌ Account number not found! Please try again.\n");
}
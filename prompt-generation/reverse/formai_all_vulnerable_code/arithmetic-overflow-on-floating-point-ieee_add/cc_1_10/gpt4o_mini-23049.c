//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer details
struct Customer {
    int accountNumber;
    char name[100];
    float balance;
};

// Function prototypes
void createAccount(struct Customer *, int);
void viewAccount(struct Customer *, int);
void deposit(struct Customer *, int, float);
void withdraw(struct Customer *, int, float);
void viewAllAccounts(struct Customer *, int);

int main() {
    int maxCustomers = 100;
    struct Customer customers[maxCustomers];
    int choice, currentCustomers = 0;

    while (1) {
        printf("\n*** Banking Record System ***\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentCustomers < maxCustomers) {
                    createAccount(customers, currentCustomers);
                    currentCustomers++;
                } else {
                    printf("Maximum customers reached.\n");
                }
                break;

            case 2:
                printf("Enter account number to view: ");
                int accountNumberView;
                scanf("%d", &accountNumberView);
                viewAccount(customers, currentCustomers);
                break;

            case 3:
                printf("Enter account number to deposit money: ");
                int accountNumberDeposit;
                scanf("%d", &accountNumberDeposit);
                printf("Enter amount to deposit: ");
                float depositAmount;
                scanf("%f", &depositAmount);
                deposit(customers, accountNumberDeposit, depositAmount);
                break;

            case 4:
                printf("Enter account number to withdraw money: ");
                int accountNumberWithdraw;
                scanf("%d", &accountNumberWithdraw);
                printf("Enter amount to withdraw: ");
                float withdrawAmount;
                scanf("%f", &withdrawAmount);
                withdraw(customers, accountNumberWithdraw, withdrawAmount);
                break;

            case 5:
                viewAllAccounts(customers, currentCustomers);
                break;

            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create an account
void createAccount(struct Customer *customers, int index) {
    customers[index].accountNumber = index + 1; // Simple account number logic
    printf("Enter customer name: ");
    scanf(" %[^\n]s", customers[index].name);
    customers[index].balance = 0.0;
    printf("Account created successfully! Account number: %d\n", customers[index].accountNumber);
}

// Function to view account details
void viewAccount(struct Customer *customers, int currentCustomers) {
    int accountNumber;
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= currentCustomers) {
        printf("Account Number: %d\n", customers[accountNumber - 1].accountNumber);
        printf("Name: %s\n", customers[accountNumber - 1].name);
        printf("Balance: $%.2f\n", customers[accountNumber - 1].balance);
    } else {
        printf("Account not found.\n");
    }
}

// Function to deposit money into an account
void deposit(struct Customer *customers, int accountNumber, float amount) {
    if (accountNumber > 0 && accountNumber <= 100) {
        customers[accountNumber - 1].balance += amount;
        printf("Deposited $%.2f to account number %d. New balance: $%.2f\n", amount, accountNumber, customers[accountNumber - 1].balance);
    } else {
        printf("Account not found.\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct Customer *customers, int accountNumber, float amount) {
    if (accountNumber > 0 && accountNumber <= 100) {
        if (customers[accountNumber - 1].balance >= amount) {
            customers[accountNumber - 1].balance -= amount;
            printf("Withdrawn $%.2f from account number %d. New balance: $%.2f\n", amount, accountNumber, customers[accountNumber - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

// Function to view all accounts
void viewAllAccounts(struct Customer *customers, int currentCustomers) {
    printf("\n--- List of all Accounts ---\n");
    for (int i = 0; i < currentCustomers; i++) {
        printf("Account Number: %d | Name: %s | Balance: $%.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}
//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
    float totalDeposits;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Error: Maximum customer limit reached.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &customers[customerCount].accountNumber);
    printf("Enter name: ");
    scanf(" %[^\n]s", customers[customerCount].name);
    customers[customerCount].balance = 0.0f;
    customers[customerCount].totalDeposits = 0.0f;

    customerCount++;
    printf("Customer added successfully!\n");
}

void deposit(int accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            customers[i].balance += amount;
            customers[i].totalDeposits += amount;
            printf("Deposited $%.2f to account %d.\n", amount, accountNumber);
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void withdraw(int accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrew $%.2f from account %d.\n", amount, accountNumber);
                return;
            } else {
                printf("Error: Insufficient balance.\n");
                return;
            }
        }
    }
    printf("Error: Account not found.\n");
}

void viewCustomer(int accountNumber) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: $%.2f\n", customers[i].balance);
            printf("Total Deposits: $%.2f\n", customers[i].totalDeposits);
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void calculateStatistics() {
    float totalBalance = 0.0f;
    float highestBalance = -1.0f;
    float lowestBalance = 1e9;
    int countAboveAverage = 0;

    for (int i = 0; i < customerCount; i++) {
        totalBalance += customers[i].balance;

        if (customers[i].balance > highestBalance) {
            highestBalance = customers[i].balance;
        }

        if (customers[i].balance < lowestBalance) {
            lowestBalance = customers[i].balance;
        }
    }

    float averageBalance = totalBalance / customerCount;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].balance > averageBalance) {
            countAboveAverage++;
        }
    }

    printf("Total Balance of all customers: $%.2f\n", totalBalance);
    printf("Average Balance: $%.2f\n", averageBalance);
    printf("Highest Balance: $%.2f\n", highestBalance);
    printf("Lowest Balance: $%.2f\n", lowestBalance);
    printf("Number of customers above average balance: %d\n", countAboveAverage);
}

void displayMenu() {
    printf("\nBanking Record System Menu:\n");
    printf("1. Add Customer\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Customer\n");
    printf("5. View Statistics\n");
    printf("6. Exit\n");
}

int main() {
    int choice, accountNumber;
    float amount;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewCustomer(accountNumber);
                break;
            case 5:
                calculateStatistics();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
    int transactionsCount;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer(int accountNumber, const char *name, float initialBalance) {
    if (customerCount < MAX_CUSTOMERS) {
        customers[customerCount].accountNumber = accountNumber;
        strncpy(customers[customerCount].name, name, MAX_NAME_LENGTH);
        customers[customerCount].balance = initialBalance;
        customers[customerCount].transactionsCount = 0;
        customerCount++;
        printf("Customer added successfully!\n");
    } else {
        printf("Maximum customer limit reached!\n");
    }
}

void deposit(int accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            customers[i].balance += amount;
            customers[i].transactionsCount++;
            printf("Deposited %.2f to account %d. New balance: %.2f\n",
                   amount, accountNumber, customers[i].balance);
            return;
        }
    }
    printf("Account number %d not found!\n", accountNumber);
}

void withdraw(int accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                customers[i].transactionsCount++;
                printf("Withdrew %.2f from account %d. New balance: %.2f\n",
                       amount, accountNumber, customers[i].balance);
            } else {
                printf("Insufficient funds for account %d!\n", accountNumber);
            }
            return;
        }
    }
    printf("Account number %d not found!\n", accountNumber);
}

void displayBalance(int accountNumber) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Balance for account %d: %.2f\n", accountNumber, customers[i].balance);
            return;
        }
    }
    printf("Account number %d not found!\n", accountNumber);
}

void displayCustomerStatistics() {
    printf("\n--- Customer Statistics ---\n");
    printf("Total Customers: %d\n", customerCount);
    
    float totalBalance = 0;
    for (int i = 0; i < customerCount; i++) {
        totalBalance += customers[i].balance;
    }
    printf("Total Bank Balance: %.2f\n", totalBalance);

    float averageBalance = (customerCount > 0) ? (totalBalance / customerCount) : 0;
    printf("Average Balance: %.2f\n", averageBalance);
    
    int maxTransactions = 0;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].transactionsCount > maxTransactions) {
            maxTransactions = customers[i].transactionsCount;
        }
    }
    printf("Maximum Transactions by a Customer: %d\n", maxTransactions);
}

void menu() {
    int choice;
    do {
        printf("\n--- Banking Record System Menu ---\n");
        printf("1. Add Customer\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Balance\n");
        printf("5. Display Customer Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int accountNumber;
            char name[MAX_NAME_LENGTH];
            float initialBalance;
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            printf("Enter customer name: ");
            scanf("%s", name);
            printf("Enter initial balance: ");
            scanf("%f", &initialBalance);
            addCustomer(accountNumber, name, initialBalance);
        } else if (choice == 2) {
            int accountNumber;
            float amount;
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            deposit(accountNumber, amount);
        } else if (choice == 3) {
            int accountNumber;
            float amount;
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            withdraw(accountNumber, amount);
        } else if (choice == 4) {
            int accountNumber;
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            displayBalance(accountNumber);
        } else if (choice == 5) {
            displayCustomerStatistics();
        } else if (choice == 6) {
            printf("Exiting the Banking Record System. Goodbye!\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
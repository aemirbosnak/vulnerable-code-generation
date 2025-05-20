//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Maximum customer limit reached.\n");
        return;
    }

    Customer newCustomer;
    printf("Enter account number: ");
    scanf("%d", &newCustomer.accountNumber);
    clearInputBuffer();

    printf("Enter customer name: ");
    fgets(newCustomer.name, NAME_LENGTH, stdin);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = '\0'; // Remove newline

    printf("Enter initial balance: ");
    scanf("%f", &newCustomer.balance);
    clearInputBuffer();

    customers[customerCount++] = newCustomer;
    printf("Customer added successfully!\n");
}

void viewCustomers() {
    if (customerCount == 0) {
        printf("No customers to display.\n");
        return;
    }

    printf("Number of Customers: %d\n", customerCount);
    printf("AccountNo\tName\t\tBalance\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < customerCount; i++) {
        printf("%d\t\t%s\t%.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    clearInputBuffer();

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            clearInputBuffer();
            if (amount > 0) {
                customers[i].balance += amount;
                printf("Deposit successful! New balance: %.2f\n", customers[i].balance);
            } else {
                printf("Invalid deposit amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    clearInputBuffer();

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            clearInputBuffer();
            if (amount > 0 && amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Withdraw successful! New balance: %.2f\n", customers[i].balance);
            } else {
                printf("Invalid withdraw amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void deleteCustomer() {
    int accountNumber;

    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    clearInputBuffer();

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            printf("Customer deleted successfully!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void displayMenu() {
    printf("\n--- C Banking Record System ---\n");
    printf("1. Add Customer\n");
    printf("2. View Customers\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Delete Customer\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: deleteCustomer(); break;
            case 6: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 6);

    return 0;
}
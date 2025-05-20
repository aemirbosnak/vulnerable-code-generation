//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer(char *name, char *accountNumber, float initialBalance) {
    if (customerCount < MAX_CUSTOMERS) {
        strcpy(customers[customerCount].name, name);
        strcpy(customers[customerCount].accountNumber, accountNumber);
        customers[customerCount].balance = initialBalance;
        customerCount++;
        printf("Customer %s added successfully.\n", name);
    } else {
        printf("Error: Maximum customer limit reached.\n");
    }
}

void deposit(char *accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            customers[i].balance += amount;
            printf("Deposited %.2f to account %s. New balance: %.2f\n", amount, accountNumber, customers[i].balance);
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void withdraw(char *accountNumber, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrawn %.2f from account %s. New balance: %.2f\n", amount, accountNumber, customers[i].balance);
            } else {
                printf("Error: Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void displayCustomerInfo(char *accountNumber) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Customer Name: %s\n", customers[i].name);
            printf("Account Number: %s\n", customers[i].accountNumber);
            printf("Account Balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void displayAllCustomers() {
    printf("\nList of Customers:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Name: %s, Account Number: %s, Balance: %.2f\n",
               customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
    printf("---------------------------------------------------\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    while (1) {
        printf("\nC Banking Record System\n");
        printf("1. Add Customer\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Customer Info\n");
        printf("5. List All Customers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%s", accountNumber);
                printf("Enter initial deposit: ");
                scanf("%f", &amount);
                addCustomer(name, accountNumber, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%s", accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%s", accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%s", accountNumber);
                displayCustomerInfo(accountNumber);
                break;
            case 5:
                displayAllCustomers();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
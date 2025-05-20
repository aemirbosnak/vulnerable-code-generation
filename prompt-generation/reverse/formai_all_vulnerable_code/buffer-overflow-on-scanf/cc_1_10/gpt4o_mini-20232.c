//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50
#define ACCOUNT_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_LENGTH];
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }
    Customer newCustomer;
    printf("Enter customer's name: ");
    scanf(" %[^\n]", newCustomer.name);
    printf("Enter account number: ");
    scanf(" %s", newCustomer.accountNumber);
    newCustomer.balance = 0.0;
    customers[customerCount++] = newCustomer;
    printf("Customer added successfully!\n");
}

void viewCustomers() {
    printf("\nList of Customers:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Name: %s, Account Number: %s, Balance: %.2f\n", 
                customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
    printf("\n");
}

void deposit() {
    char accountNumber[ACCOUNT_LENGTH];
    double amount;
    printf("Enter account number to deposit into: ");
    scanf(" %s", accountNumber);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            if (amount > 0) {
                customers[i].balance += amount;
                printf("Successfully deposited %.2f into %s's account.\n", amount, customers[i].name);
            } else {
                printf("Invalid amount. Please enter a positive number.\n");
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_LENGTH];
    double amount;
    printf("Enter account number to withdraw from: ");
    scanf(" %s", accountNumber);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > 0 && amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Successfully withdrew %.2f from %s's account.\n", amount, customers[i].name);
            } else {
                printf("Invalid amount. Ensure it is positive and does not exceed your balance.\n");
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

void showMenu() {
    printf("\n********* Banking Record System *********\n");
    printf("1. Add Customer\n");
    printf("2. View Customers\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("******************************************\n");
}

int main() {
    int choice;

    do {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting the banking system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}
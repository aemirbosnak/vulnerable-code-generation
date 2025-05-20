//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 100
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void welcomeMessage() {
    printf("****************************************\n");
    printf("*   Welcome to the Imaginative Bank!   *\n");
    printf("****************************************\n");
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached! Cannot add more customers.\n");
        return;
    }
    Customer newCustomer;
    printf("Enter account number: ");
    scanf("%s", newCustomer.accountNumber);
    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", newCustomer.name);
    newCustomer.balance = 0.0;

    customers[customerCount++] = newCustomer;
    printf("Customer %s with account number %s added successfully!\n", newCustomer.name, newCustomer.accountNumber);
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter account number: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid amount! Please enter a positive amount.\n");
            } else {
                customers[i].balance += amount;
                printf("Successfully deposited %.2f to %s's account. New balance: %.2f\n", amount, customers[i].name, customers[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter account number: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid amount! Please enter a positive amount.\n");
            } else if (amount > customers[i].balance) {
                printf("Insufficient funds! Current balance: %.2f\n", customers[i].balance);
            } else {
                customers[i].balance -= amount;
                printf("Successfully withdrew %.2f from %s's account. New balance: %.2f\n", amount, customers[i].name, customers[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayBalance() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Account holder: %s, Current balance: %.2f\n", customers[i].name, customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAllCustomers() {
    printf("\n--- All Customers ---\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
    printf("---------------------\n");
}

int main() {
    int choice;
    welcomeMessage();
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add Customer\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Balance\n");
        printf("5. Display All Customers\n");
        printf("6. Exit\n");
        
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayBalance();
                break;
            case 5:
                displayAllCustomers();
                break;
            case 6:
                printf("Thank you for using Imaginative Bank. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
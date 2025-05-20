//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LEN 50
#define ACC_NO_LEN 20

typedef struct {
    char name[NAME_LEN];
    char accountNumber[ACC_NO_LEN];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void displayMenu() {
    printf("\n=== Retro Bank System ===\n");
    printf("1. Add New Customer\n");
    printf("2. Deposit Amount\n");
    printf("3. Withdraw Amount\n");
    printf("4. Display All Customers\n");
    printf("5. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Error: Maximum customer limit reached!\n");
        return;
    }
    
    Customer newCustomer;
    printf("Enter Customer Name: ");
    getchar(); // Clear newline from buffer
    fgets(newCustomer.name, NAME_LEN, stdin);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = 0; // Remove newline
    
    printf("Enter Account Number: ");
    fgets(newCustomer.accountNumber, ACC_NO_LEN, stdin);
    newCustomer.accountNumber[strcspn(newCustomer.accountNumber, "\n")] = 0; // Remove newline
    
    newCustomer.balance = 0.0;
    customers[customerCount++] = newCustomer;
    
    printf("Customer added successfully!\n");
}

void depositAmount() {
    char accNumber[ACC_NO_LEN];
    float amount;
    printf("Enter Account Number: ");
    getchar(); // Clear newline from buffer
    fgets(accNumber, ACC_NO_LEN, stdin);
    accNumber[strcspn(accNumber, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                customers[i].balance += amount;
                printf("Successfully deposited $%.2f to %s's account.\n", amount, customers[i].name);
            } else {
                printf("Error: Invalid deposit amount!\n");
            }
            return;
        }
    }
    printf("Error: Account number not found.\n");
}

void withdrawAmount() {
    char accNumber[ACC_NO_LEN];
    float amount;
    printf("Enter Account Number: ");
    getchar(); // Clear newline from buffer
    fgets(accNumber, ACC_NO_LEN, stdin);
    accNumber[strcspn(accNumber, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].accountNumber, accNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Successfully withdrew $%.2f from %s's account.\n", amount, customers[i].name);
            } else {
                printf("Error: Invalid withdrawal amount!\n");
            }
            return;
        }
    }
    printf("Error: Account number not found.\n");
}

void displayCustomers() {
    if (customerCount == 0) {
        printf("No customers found!\n");
        return;
    }
    
    printf("\n=== Customers List ===\n");
    printf("%-30s %-20s %s\n", "Name", "Account Number", "Balance");
    for (int i = 0; i < customerCount; i++) {
        printf("%-30s %-20s $%.2f\n", customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                depositAmount();
                break;
            case 3:
                withdrawAmount();
                break;
            case 4:
                displayCustomers();
                break;
            case 5:
                printf("Thank you for using Retro Bank System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}
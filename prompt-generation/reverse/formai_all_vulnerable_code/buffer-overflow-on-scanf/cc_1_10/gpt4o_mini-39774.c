//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void createAccount() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Maximum customer limit reached!\n");
        return;
    }
    
    Customer newCustomer;
    
    printf("Enter customer name: ");
    scanf(" %[^\n]", newCustomer.name); // Read string with spaces
    newCustomer.balance = 0.0;
    
    customers[customerCount] = newCustomer;
    customerCount++;
    
    printf("Account created for %s.\n", newCustomer.name);
}

void deposit() {
    char name[MAX_NAME_LENGTH];
    float amount;
    
    printf("Enter customer name for deposit: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                customers[i].balance += amount;
                printf("Successfully deposited $%.2f to %s's account.\n", amount, customers[i].name);
            } else {
                printf("Deposit amount must be positive.\n");
            }
            return;
        }
    }
    
    printf("Customer not found!\n");
}

void withdraw() {
    char name[MAX_NAME_LENGTH];
    float amount;
    
    printf("Enter customer name for withdrawal: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Successfully withdrew $%.2f from %s's account.\n", amount, customers[i].name);
            } else {
                printf("Withdrawal amount must be positive and less than or equal to balance.\n");
            }
            return;
        }
    }
    
    printf("Customer not found!\n");
}

void displayBalance() {
    char name[MAX_NAME_LENGTH];
    
    printf("Enter customer name to display balance: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printf("%s's balance: $%.2f\n", customers[i].name, customers[i].balance);
            return;
        }
    }
    
    printf("Customer not found!\n");
}

void listAllAccounts() {
    if (customerCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("Customer Accounts:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Name: %s, Balance: $%.2f\n", customers[i].name, customers[i].balance);
    }
}

int main() {
    int choice;
    
    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Balance\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                displayBalance();
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);
    
    return 0;
}
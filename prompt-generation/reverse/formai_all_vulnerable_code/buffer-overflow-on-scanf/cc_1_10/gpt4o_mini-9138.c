//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a customer in the banking system
typedef struct {
    int accountNumber;
    char name[50];
    char address[100];
    float balance;
} Customer;

// Max number of customers
#define MAX_CUSTOMERS 100

// Global array to hold all customers
Customer customers[MAX_CUSTOMERS];
int numCustomers = 0; // Number of customers in the system

// Function to check for paranoia in user input
void paranoidCheck(const char *input) {
    if (strpbrk(input, "0123456789") == NULL) {
        printf("Warning: Input seems suspicious, does it contain any digits?\n");
        exit(1);
    }
}

// Function to add a new customer
void addCustomer() {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Warning: Unable to add more customers, the system is full!\n");
        return;
    }

    // Input customer details
    Customer newCustomer;
    printf("Enter account number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Enter name: ");
    getchar(); // Consume newline after account number
    fgets(newCustomer.name, sizeof(newCustomer.name), stdin);
    paranoidCheck(newCustomer.name);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = 0; // Remove newline

    printf("Enter address: ");
    fgets(newCustomer.address, sizeof(newCustomer.address), stdin);
    paranoidCheck(newCustomer.address);
    newCustomer.address[strcspn(newCustomer.address, "\n")] = 0; // Remove newline

    printf("Enter initial balance: ");
    scanf("%f", &newCustomer.balance);
    if (newCustomer.balance < 0) {
        printf("Warning: Balance cannot be negative!\n");
        return;
    }

    customers[numCustomers++] = newCustomer;
    printf("Customer added successfully with account number: %d\n", newCustomer.accountNumber);
}

// Function to view all customers
void viewCustomers() {
    printf("Listing all customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("Account Number: %d\n", customers[i].accountNumber);
        printf("Name: %s\n", customers[i].name);
        printf("Address: %s\n", customers[i].address);
        printf("Balance: %.2f\n", customers[i].balance);
        printf("-------------------------\n");
    }
}

// Function to deposit money into a specific account
void depositMoney() {
    int accountNumber;
    printf("Enter account number to deposit into: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Warning: Deposit amount cannot be negative!\n");
                return;
            }
            customers[i].balance += amount;
            printf("Successfully deposited %.2f into account number: %d\n", amount, accountNumber);
            return;
        }
    }
    printf("Warning: Account number %d not found!\n", accountNumber);
}

// Function to withdraw money from a specific account
void withdrawMoney() {
    int accountNumber;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Warning: Withdrawal amount cannot be negative!\n");
                return;
            }
            if (amount > customers[i].balance) {
                printf("Warning: Insufficient funds in account number: %d\n", accountNumber);
                return;
            }
            customers[i].balance -= amount;
            printf("Successfully withdrew %.2f from account number: %d\n", amount, accountNumber);
            return;
        }
    }
    printf("Warning: Account number %d not found!\n", accountNumber);
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Paranoid Banking System!\n");
    printf("1. Add Customer\n");
    printf("2. View All Customers\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Exiting the system. Stay safe!\n");
                return 0;
            default:
                printf("Warning: Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdbool.h>

// Define a structure for customer data
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Customer;

// Define an array to store customer data
Customer customers[100];
int numCustomers = 0;

// Helper function to find a customer by account number
int findCustomerIndex(int accountNumber) {
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

// Helper function to print customer data
void printCustomer(int index) {
    printf("Account Number: %d\n", customers[index].accountNumber);
    printf("Name: %s\n", customers[index].name);
    printf("Balance: $%.2lf\n", customers[index].balance);
}

// Function to add a new customer
void addCustomer(int accountNumber, char name[], double balance) {
    // Check if customer already exists
    int index = findCustomerIndex(accountNumber);
    if (index >= 0) {
        printf("Error: customer already exists with account number %d\n", accountNumber);
        return;
    }
    // Add customer to array
    Customer customer = {accountNumber, name, balance};
    customers[numCustomers++] = customer;
    printf("Customer added successfully\n");
}

// Function to update customer balance
void updateBalance(int accountNumber, double amount) {
    // Find customer
    int index = findCustomerIndex(accountNumber);
    if (index == -1) {
        printf("Error: customer not found with account number %d\n", accountNumber);
        return;
    }
    // Update balance
    customers[index].balance += amount;
    printf("Balance updated successfully\n");
}

// Function to delete a customer
void deleteCustomer(int accountNumber) {
    // Find customer
    int index = findCustomerIndex(accountNumber);
    if (index == -1) {
        printf("Error: customer not found with account number %d\n", accountNumber);
        return;
    }
    // Shift array elements to remove customer
    for (int i = index; i < numCustomers - 1; i++) {
        customers[i] = customers[i + 1];
    }
    numCustomers--;
    printf("Customer deleted successfully\n");
}

int main() {
    // Add some initial customers
    addCustomer(1001, "Alice", 5000);
    addCustomer(1002, "Bob", 7500);
    addCustomer(1003, "Charlie", 10000);

    while (true) {
        printf("\nBanking Record System\n");
        printf("======================\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Update Balance\n");
        printf("4. Delete Customer\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter account number: ");
            int accountNumber;
            scanf("%d", &accountNumber);
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            printf("Enter balance: ");
            double balance;
            scanf("%lf", &balance);
            addCustomer(accountNumber, name, balance);
            break;
        case 2:
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            int index = findCustomerIndex(accountNumber);
            if (index == -1) {
                printf("Error: customer not found with account number %d\n", accountNumber);
            } else {
                printCustomer(index);
            }
            break;
        case 3:
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            printf("Enter amount to add/subtract: ");
            double amount;
            scanf("%lf", &amount);
            updateBalance(accountNumber, amount);
            break;
        case 4:
            printf("Enter account number: ");
            scanf("%d", &accountNumber);
            deleteCustomer(accountNumber);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Error: invalid choice\n");
        }
    }
}
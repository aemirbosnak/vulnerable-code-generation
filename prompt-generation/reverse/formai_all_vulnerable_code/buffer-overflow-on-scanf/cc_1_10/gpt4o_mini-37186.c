//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold customer details
struct Customer {
    int id;
    char name[100];
    float balance;
};

// Function prototypes
void addCustomer(struct Customer *customers, int *count);
void displayCustomers(struct Customer *customers, int count);
void deposit(struct Customer *customers, int count);
void withdraw(struct Customer *customers, int count);
void menu();

int main() {
    struct Customer customers[100];
    int customerCount = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, &customerCount);
                break;
            case 2:
                displayCustomers(customers, customerCount);
                break;
            case 3:
                deposit(customers, customerCount);
                break;
            case 4:
                withdraw(customers, customerCount);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void menu() {
    printf("\n***** C Banking Record System *****\n");
    printf("1. Add Customer\n");
    printf("2. Display Customers\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

void addCustomer(struct Customer *customers, int *count) {
    struct Customer newCustomer;
    newCustomer.id = *count + 1; // Assign a ID based on current count
    printf("Enter customer name: ");
    scanf("%s", newCustomer.name); 
    newCustomer.balance = 0.0; // Initialize balance to 0

    customers[*count] = newCustomer; // Add the new customer to the array
    (*count)++; // Increment the customer count

    printf("Customer added successfully! ID: %d\n", newCustomer.id);
}

void displayCustomers(struct Customer *customers, int count) {
    if (count == 0) {
        printf("No customers found.\n");
        return;
    }

    printf("\nCustomers List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Balance: %.2f\n", customers[i].id, customers[i].name, customers[i].balance);
    }
}

void deposit(struct Customer *customers, int count) {
    int id;
    float amount;

    printf("Enter customer ID for deposit: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > count) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        return;
    }

    customers[id - 1].balance += amount; // Update balance
    printf("Deposit successful! New balance: %.2f\n", customers[id - 1].balance);
}

void withdraw(struct Customer *customers, int count) {
    int id;
    float amount;

    printf("Enter customer ID for withdrawal: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > count) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        return;
    }

    if (amount > customers[id - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    customers[id - 1].balance -= amount; // Update balance
    printf("Withdrawal successful! New balance: %.2f\n", customers[id - 1].balance);
}
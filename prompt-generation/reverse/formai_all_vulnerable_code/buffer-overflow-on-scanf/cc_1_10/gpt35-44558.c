//FormAI DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Define the customer structure to hold customer information
typedef struct {
    int id;
    char name[50];
    double balance;
} Customer;

// Define the global array of customers
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

// Function to add a new customer
void add_customer() {
    Customer c;

    // Assign a unique id to the new customer
    c.id = num_customers + 1;

    // Prompt the user for customer information
    printf("Enter customer name: ");
    scanf("%s", c.name);
    printf("Enter initial balance: ");
    scanf("%lf", &c.balance);

    // Add the new customer to the array
    customers[num_customers] = c;
    num_customers++;
}

// Function to find a customer by id
int find_customer(int id) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Function to display customer information
void display_customer(int id) {
    int index = find_customer(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("ID: %d\n", customers[index].id);
    printf("Name: %s\n", customers[index].name);
    printf("Balance: %.2f\n", customers[index].balance);
}

// Function to deposit money into a customer's account
void deposit(int id, double amount) {
    int index = find_customer(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    customers[index].balance += amount;

    printf("Deposit successful.\n");
    printf("New balance: %.2f\n", customers[index].balance);
}

// Function to withdraw money from a customer's account
void withdraw(int id, double amount) {
    int index = find_customer(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    if (customers[index].balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }

    customers[index].balance -= amount;

    printf("Withdrawal successful.\n");
    printf("New balance: %.2f\n", customers[index].balance);
}

int main() {
    int choice = 0;
    int id = 0;
    double amount = 0.0;

    printf("Welcome to the Banking Record System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add customer\n");
        printf("2. Display customer information\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;

            case 2:
                printf("Enter customer id: ");
                scanf("%d", &id);
                display_customer(id);
                break;

            case 3:
                printf("Enter customer id: ");
                scanf("%d", &id);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(id, amount);
                break;

            case 4:
                printf("Enter customer id: ");
                scanf("%d", &id);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(id, amount);
                break;

            case 5:
                printf("Thank you for using the Banking Record System\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
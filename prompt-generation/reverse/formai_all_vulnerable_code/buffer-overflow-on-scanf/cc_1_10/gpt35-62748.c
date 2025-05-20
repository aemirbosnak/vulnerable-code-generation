//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100

// Structure to store customer information
typedef struct {
    char name[50];
    int account_number;
    double balance;
} Customer;

// Array to store multiple customers
Customer customers[MAX_CUSTOMERS];

// Function to add a new customer to the system
void add_customer() {
    Customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    printf("Enter starting balance: ");
    scanf("%lf", &new_customer.balance);
    // Add new customer to next available index in `customers` array
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (strcmp(customers[i].name, "") == 0) {
            customers[i] = new_customer;
            printf("New customer added successfully.\n");
            return;
        }
    }
    printf("Maximum number of customers reached.\n");
}

// Function to find a customer by account number
int find_customer(int account_number) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}

// Function to deposit money into a customer's account
void deposit() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int customer_index = find_customer(account_number);
    if (customer_index == -1) {
        printf("Customer not found.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    customers[customer_index].balance += amount;
    printf("New balance for %s: %.2lf\n", customers[customer_index].name, customers[customer_index].balance);
}

// Function to withdraw money from a customer's account
void withdraw() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int customer_index = find_customer(account_number);
    if (customer_index == -1) {
        printf("Customer not found.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (customers[customer_index].balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }
    customers[customer_index].balance -= amount;
    printf("New balance for %s: %.2lf\n", customers[customer_index].name, customers[customer_index].balance);
}

// Function to display information for all customers
void display_customers() {
    printf("%-20s %-20s %s\n", "Name", "Account Number", "Balance");
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (strcmp(customers[i].name, "") != 0) {
            printf("%-20s %-20d $%.2lf\n", customers[i].name, customers[i].account_number, customers[i].balance);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add customer\n2. Deposit\n3. Withdraw\n4. Display customers\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display_customers();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

// Structure to represent a customer
typedef struct {
    char name[50];
    int id;
    float balance;
} Customer;

// Structure to represent a transaction
typedef struct {
    char type[50];
    float amount;
    int customer_id;
} Transaction;

// Array to store customers
Customer customers[MAX_CUSTOMERS];

// Array to store transactions
Transaction transactions[MAX_TRANSACTIONS];

// Function to create a new customer
void create_customer(Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer ID: ");
    scanf("%d", &customer->id);
    printf("Enter initial balance: ");
    scanf("%f", &customer->balance);
}

// Function to display all customers
void display_all_customers() {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        printf("%s - %d - %f\n", customers[i].name, customers[i].id, customers[i].balance);
    }
}

// Function to add a transaction
void add_transaction(Transaction *transaction) {
    printf("Enter transaction type: ");
    scanf("%s", transaction->type);
    printf("Enter transaction amount: ");
    scanf("%f", &transaction->amount);
    printf("Enter customer ID: ");
    scanf("%d", &transaction->customer_id);
}

// Function to display all transactions
void display_all_transactions() {
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        printf("%s - %f - %d\n", transactions[i].type, transactions[i].amount, transactions[i].customer_id);
    }
}

int main() {
    // Initialize customers and transactions
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        create_customer(&customers[i]);
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        add_transaction(&transactions[i]);
    }

    // Display all customers
    display_all_customers();

    // Display all transactions
    display_all_transactions();

    return 0;
}
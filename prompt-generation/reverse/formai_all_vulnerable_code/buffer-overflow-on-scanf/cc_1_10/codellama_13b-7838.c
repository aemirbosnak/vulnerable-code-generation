//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: protected
/*
 * Medical Store Management System
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Define the structure for a customer
typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
} Customer;

// Define the structure for a transaction
typedef struct transaction {
    char id[10];
    Customer customer;
    Medicine medicine;
    float amount;
    char date[20];
} Transaction;

// Function to create a new customer
void createCustomer(Customer *c) {
    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter customer address: ");
    scanf("%s", c->address);
    printf("Enter customer phone: ");
    scanf("%s", c->phone);
}

// Function to create a new medicine
void createMedicine(Medicine *m) {
    printf("Enter medicine name: ");
    scanf("%s", m->name);
    printf("Enter medicine price: ");
    scanf("%f", &m->price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m->quantity);
}

// Function to add a new transaction
void addTransaction(Transaction *t) {
    printf("Enter transaction id: ");
    scanf("%s", t->id);
    printf("Enter customer name: ");
    scanf("%s", t->customer.name);
    printf("Enter medicine name: ");
    scanf("%s", t->medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &t->medicine.quantity);
    printf("Enter amount: ");
    scanf("%f", &t->amount);
    printf("Enter date: ");
    scanf("%s", t->date);
}

// Function to display all transactions
void displayTransactions(Transaction *t) {
    printf("Transaction id: %s\n", t->id);
    printf("Customer name: %s\n", t->customer.name);
    printf("Medicine name: %s\n", t->medicine.name);
    printf("Quantity: %d\n", t->medicine.quantity);
    printf("Amount: %.2f\n", t->amount);
    printf("Date: %s\n", t->date);
}

int main() {
    Customer customer;
    Medicine medicine;
    Transaction transaction;

    // Create a new customer
    createCustomer(&customer);

    // Create a new medicine
    createMedicine(&medicine);

    // Add a new transaction
    addTransaction(&transaction);

    // Display all transactions
    displayTransactions(&transaction);

    return 0;
}
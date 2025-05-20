//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
// Banking Record System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct {
    int id;
    char name[50];
    char address[50];
    char phone[50];
    double balance;
} Customer;

typedef struct {
    int id;
    char name[50];
    double amount;
} Transaction;

// Function prototypes
void create_customer(Customer *c);
void deposit(Customer *c, double amount);
void withdraw(Customer *c, double amount);
void display_customer(Customer *c);

// Main function
int main() {
    // Declare variables
    Customer c;
    Transaction t;
    int choice;
    double amount;

    // Initialize customer information
    create_customer(&c);

    // Display menu
    printf("Banking Record System\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Display Customer\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process user choice
    switch (choice) {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            deposit(&c, amount);
            break;
        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            withdraw(&c, amount);
            break;
        case 3:
            display_customer(&c);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

// Function definitions
void create_customer(Customer *c) {
    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter customer address: ");
    scanf("%s", c->address);
    printf("Enter customer phone number: ");
    scanf("%s", c->phone);
    c->balance = 0.0;
}

void deposit(Customer *c, double amount) {
    c->balance += amount;
    printf("Deposited %lf into account.\n", amount);
}

void withdraw(Customer *c, double amount) {
    if (amount > c->balance) {
        printf("Insufficient balance\n");
    } else {
        c->balance -= amount;
        printf("Withdrawn %lf from account.\n", amount);
    }
}

void display_customer(Customer *c) {
    printf("Customer information:\n");
    printf("Name: %s\n", c->name);
    printf("Address: %s\n", c->address);
    printf("Phone: %s\n", c->phone);
    printf("Balance: %lf\n", c->balance);
}
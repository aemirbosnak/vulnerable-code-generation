//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
} Customer;

void create_customer(Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);

    printf("Enter account number: ");
    scanf("%d", &customer->account_number);

    printf("Enter initial balance: ");
    scanf("%lf", &customer->balance);
}

void deposit(Customer *customer) {
    double amount;

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    customer->balance += amount;
}

void withdraw(Customer *customer) {
    double amount;

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

void transfer(Customer *customer1, Customer *customer2) {
    double amount;

    printf("Enter transfer amount: ");
    scanf("%lf", &amount);

    if (amount <= customer1->balance) {
        customer1->balance -= amount;
        customer2->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    // Create a new customer
    printf("Create a new customer? (Y/N): ");
    char create_customer_yn;
    scanf("%c", &create_customer_yn);

    if (create_customer_yn == 'Y') {
        create_customer(&customers[num_customers]);
        num_customers++;
    }

    // Perform banking operations
    printf("Select an operation:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Transfer\n");
    int operation_choice;
    scanf("%d", &operation_choice);

    switch (operation_choice) {
        case 1:
            deposit(&customers[num_customers - 1]);
            break;
        case 2:
            withdraw(&customers[num_customers - 1]);
            break;
        case 3:
            transfer(&customers[num_customers - 1], &customers[num_customers - 1]);
            break;
        default:
            printf("Invalid operation choice\n");
            break;
    }

    // Print customer information
    printf("Customer information:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Name: %s\n", customers[i].name);
        printf("Account number: %d\n", customers[i].account_number);
        printf("Balance: %.2lf\n", customers[i].balance);
        printf("\n");
    }

    return 0;
}
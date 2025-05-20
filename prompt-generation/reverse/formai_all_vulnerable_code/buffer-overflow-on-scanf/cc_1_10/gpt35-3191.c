//FormAI DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // Maximum number of customers in the bank

typedef struct {
    int accNumber;
    char name[50];
    float balance;
} Customer;

void addCustomer(Customer *customers, int *count);

void viewCustomer(Customer *customers, int count);

void findCustomer(Customer *customers, int count);

int main() {
    int choice, count = 0;
    Customer customers[MAX_CUSTOMERS];

    while (1) {
        printf("Welcome to Retro Bank\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Find Customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, &count);
                break;

            case 2:
                viewCustomer(customers, count);
                break;

            case 3:
                findCustomer(customers, count);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void addCustomer(Customer *customers, int *count) {
    if (*count >= MAX_CUSTOMERS) {
        printf("Bank is full\n");
        return;
    }

    Customer customer;

    printf("Enter account number: ");
    scanf("%d", &customer.accNumber);

    printf("Enter name: ");
    scanf("%s", customer.name);

    printf("Enter balance: ");
    scanf("%f", &customer.balance);

    customers[*count] = customer;

    (*count)++;

    printf("Customer added successfully\n");
}

void viewCustomer(Customer *customers, int count) {
    if (count == 0) {
        printf("No customers in the bank\n");
        return;
    }

    printf("Total customers: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("\nAccount number: %d\n", customers[i].accNumber);
        printf("Customer name: %s\n", customers[i].name);
        printf("Balance: %.2f\n", customers[i].balance);
    }
}

void findCustomer(Customer *customers, int count) {
    if (count == 0) {
        printf("No customers in the bank\n");
        return;
    }

    int accNumber, found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < count; i++) {
        if (customers[i].accNumber == accNumber) {
            printf("\nAccount number: %d\n", customers[i].accNumber);
            printf("Customer name: %s\n", customers[i].name);
            printf("Balance: %.2f\n", customers[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Customer with account number %d not found\n", accNumber);
    }
}
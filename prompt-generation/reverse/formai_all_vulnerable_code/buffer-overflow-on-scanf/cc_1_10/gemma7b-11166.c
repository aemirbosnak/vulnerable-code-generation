//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];

void deposit(int account_number, double amount) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            break;
        }
    }
}

void withdraw(int account_number, double amount) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            if (amount <= customers[i].balance) {
                customers[i].balance -= amount;
                break;
            } else {
                printf("Insufficient funds.\n");
            }
        }
    }
}

int main() {
    int choice, account_number, amount;
    double balance;

    // Initialize customers
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i].account_number = -1;
    }

    // Main loop
    while (1) {
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount: ");
                scanf("%lf", &amount);
                deposit(account_number, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount: ");
                scanf("%lf", &amount);
                withdraw(account_number, amount);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
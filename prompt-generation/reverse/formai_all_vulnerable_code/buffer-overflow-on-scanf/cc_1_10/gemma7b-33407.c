//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[20];
    int account_number;
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];

void deposit(int account_number, double amount) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(int account_number, double amount) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            if (amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient funds.\n");
            }
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    int account_number;
    double amount;

    printf("Welcome to the C Banking Record System!\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the account number: ");
            scanf("%d", &account_number);
            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);
            deposit(account_number, amount);
            break;
        case 2:
            printf("Enter the account number: ");
            scanf("%d", &account_number);
            printf("Enter the amount to withdraw: ");
            scanf("%lf", &amount);
            withdraw(account_number, amount);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
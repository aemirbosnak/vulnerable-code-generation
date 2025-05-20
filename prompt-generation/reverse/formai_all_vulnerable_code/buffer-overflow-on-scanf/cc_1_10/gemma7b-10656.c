//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[20];
    int account_number;
    double balance;
};

struct customer customers[MAX_CUSTOMERS];

void deposit(int account_number, double amount) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account number not found.\n");
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

    printf("Account number not found.\n");
}

int main() {
    int choice, account_number, amount;

    printf("Welcome to the Banking System!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number:");
                scanf("%d", &account_number);
                printf("Enter amount:");
                scanf("%lf", &amount);
                deposit(account_number, amount);
                break;
            case 2:
                printf("Enter account number:");
                scanf("%d", &account_number);
                printf("Enter amount:");
                scanf("%lf", &amount);
                withdraw(account_number, amount);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
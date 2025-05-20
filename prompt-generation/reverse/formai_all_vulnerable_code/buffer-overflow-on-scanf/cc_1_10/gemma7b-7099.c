//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <string.h>

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
    int choice, account_number, amount;

    // Initialize customers
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i].account_number = 0;
        customers[i].balance = 0.0;
    }

    // Main loop
    while (1) {
        printf("Enter 1 to deposit, 2 to withdraw, 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(account_number, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(account_number, amount);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}
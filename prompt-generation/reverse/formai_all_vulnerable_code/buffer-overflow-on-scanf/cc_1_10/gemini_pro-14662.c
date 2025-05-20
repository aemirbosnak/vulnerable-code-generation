//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    int account_number;
    char name[50];
    double balance;
} customer;

void create_account(customer *customers, int *num_customers) {
    printf("Enter account number: ");
    scanf("%d", &customers[*num_customers].account_number);
    printf("Enter name: ");
    scanf("%s", customers[*num_customers].name);
    printf("Enter balance: ");
    scanf("%lf", &customers[*num_customers].balance);
    (*num_customers)++;
}

void deposit(customer *customers, int num_customers) {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(customer *customers, int num_customers) {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void print_records(customer *customers, int num_customers) {
    printf("Account Records:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Account Number: %d\n", customers[i].account_number);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: %.2lf\n\n", customers[i].balance);
    }
}

int main() {
    customer customers[100];
    int num_customers = 0;
    int choice;
    do {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(customers, &num_customers);
                break;
            case 2:
                deposit(customers, num_customers);
                break;
            case 3:
                withdraw(customers, num_customers);
                break;
            case 4:
                print_records(customers, num_customers);
                break;
            case 5:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
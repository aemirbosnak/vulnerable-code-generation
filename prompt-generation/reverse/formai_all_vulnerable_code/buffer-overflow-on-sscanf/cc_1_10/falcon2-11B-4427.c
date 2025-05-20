//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int account_number;
    double balance;
};

struct Bank {
    struct Customer customers[100];
    int num_customers;
};

void create_customer(struct Bank *bank, char *name, int account_number) {
    struct Customer customer;
    strcpy(customer.name, name);
    customer.account_number = account_number;
    customer.balance = 0.0;

    bank->customers[bank->num_customers] = customer;
    bank->num_customers++;
}

void deposit(struct Bank *bank, char *name, double amount) {
    int i;
    for (i = 0; i < bank->num_customers; i++) {
        if (strcmp(bank->customers[i].name, name) == 0) {
            bank->customers[i].balance += amount;
            break;
        }
    }
}

void withdraw(struct Bank *bank, char *name, double amount) {
    int i;
    for (i = 0; i < bank->num_customers; i++) {
        if (strcmp(bank->customers[i].name, name) == 0) {
            if (bank->customers[i].balance >= amount) {
                bank->customers[i].balance -= amount;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            break;
        }
    }
}

int main() {
    struct Bank bank;
    bank.num_customers = 0;

    char name[50];
    int account_number;
    double amount;

    while (1) {
        printf("Welcome to the C Banking Record System!\n");
        printf("Please enter your name:\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %d", name, &account_number);

        if (strlen(name) == 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        create_customer(&bank, name, account_number);
        printf("Account created successfully.\n");

        printf("Enter your account number:\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %d", name, &account_number);

        if (strlen(name) == 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Enter the amount to deposit:\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%lf", &amount);

        deposit(&bank, name, amount);
        printf("Deposit successful.\n");

        printf("Enter your account number:\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %d", name, &account_number);

        if (strlen(name) == 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Enter the amount to withdraw:\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%lf", &amount);

        withdraw(&bank, name, amount);
        printf("Withdrawal successful.\n");

        printf("Do you want to continue (y/n)?\n");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s", name);

        if (strcmp(name, "n") == 0) {
            break;
        }
    }

    return 0;
}
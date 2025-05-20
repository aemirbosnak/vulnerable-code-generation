//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int account_number;
    float balance;
} customer;

int menu(void);
void add_customer(customer* database, int* num_customers);
void display_customers(customer* database, int num_customers);
void deposit(customer* database, int num_customers);
void withdraw(customer* database, int num_customers);

int main() {
    customer database[MAX_CUSTOMERS];
    int num_customers = 0, choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_customer(database, &num_customers);
                break;
            case 2:
                display_customers(database, num_customers);
                break;
            case 3:
                deposit(database, num_customers);
                break;
            case 4:
                withdraw(database, num_customers);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

int menu() {
    int choice;

    printf("Bank Record System\n");
    printf("-------------------\n");
    printf("1. Add customer\n");
    printf("2. Display all customers\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Quit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

void add_customer(customer* database, int* num_customers) {
    if (*num_customers == MAX_CUSTOMERS) {
        printf("Database is full. Cannot add another customer.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[*num_customers].name);

    printf("Enter account number: ");
    scanf("%d", &database[*num_customers].account_number);

    printf("Enter balance: ");
    scanf("%f", &database[*num_customers].balance);

    (*num_customers)++;
}

void display_customers(customer* database, int num_customers) {
    if (num_customers == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Name\tAccount Number\tBalance\n");
    printf("----\t--------------\t-------\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].account_number, database[i].balance);
    }
}

void deposit(customer* database, int num_customers) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (database[i].account_number == account_number) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            database[i].balance += amount;
            printf("New balance for account %d: %.2f\n", account_number, database[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(customer* database, int num_customers) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (database[i].account_number == account_number) {
            printf("Enter withdraw amount: ");
            scanf("%f", &amount);
            if (amount > database[i].balance) {
                printf("Insufficient balance.\n");
                return;
            }
            database[i].balance -= amount;
            printf("New balance for account %d: %.2f\n", account_number, database[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}
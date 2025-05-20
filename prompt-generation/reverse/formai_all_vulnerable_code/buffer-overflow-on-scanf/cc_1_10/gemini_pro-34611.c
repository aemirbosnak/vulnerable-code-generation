//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    char address[100];
    int account_number;
    double balance;
};

struct transaction {
    int account_number;
    char type[20];
    double amount;
};

void create_customer(struct customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer address: ");
    scanf("%s", customer->address);
    printf("Enter customer account number: ");
    scanf("%d", &customer->account_number);
    printf("Enter customer balance: ");
    scanf("%lf", &customer->balance);
}

void display_customer(struct customer *customer) {
    printf("Customer name: %s\n", customer->name);
    printf("Customer address: %s\n", customer->address);
    printf("Customer account number: %d\n", customer->account_number);
    printf("Customer balance: %lf\n", customer->balance);
}

void create_transaction(struct transaction *transaction) {
    printf("Enter account number: ");
    scanf("%d", &transaction->account_number);
    printf("Enter transaction type (deposit/withdrawal): ");
    scanf("%s", transaction->type);
    printf("Enter transaction amount: ");
    scanf("%lf", &transaction->amount);
}

void display_transaction(struct transaction *transaction) {
    printf("Account number: %d\n", transaction->account_number);
    printf("Transaction type: %s\n", transaction->type);
    printf("Transaction amount: %lf\n", transaction->amount);
}

void process_transaction(struct customer *customer, struct transaction *transaction) {
    if (strcmp(transaction->type, "deposit") == 0) {
        customer->balance += transaction->amount;
    } else if (strcmp(transaction->type, "withdrawal") == 0) {
        customer->balance -= transaction->amount;
    } else {
        printf("Invalid transaction type.\n");
    }
}

int main() {
    struct customer customer;
    struct transaction transaction;

    create_customer(&customer);
    display_customer(&customer);

    create_transaction(&transaction);
    display_transaction(&transaction);

    process_transaction(&customer, &transaction);
    display_customer(&customer);

    return 0;
}
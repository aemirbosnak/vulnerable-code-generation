//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
} customer;

typedef struct transaction {
    int transaction_id;
    char description[50];
    double amount;
    struct transaction* next;
} transaction;

customer* insert_customer(customer* head) {
    customer* new_customer = (customer*)malloc(sizeof(customer));
    printf("Enter customer name: ");
    scanf("%s", new_customer->name);
    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);
    printf("Enter initial balance: ");
    scanf("%lf", &new_customer->balance);
    new_customer->next = head;
    head = new_customer;
    return head;
}

transaction* insert_transaction(transaction* head) {
    transaction* new_transaction = (transaction*)malloc(sizeof(transaction));
    printf("Enter transaction description: ");
    scanf("%s", new_transaction->description);
    printf("Enter transaction amount: ");
    scanf("%lf", &new_transaction->amount);
    new_transaction->next = head;
    head = new_transaction;
    return head;
}

void print_customers(customer* head) {
    customer* current = head;
    while (current) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current->name, current->account_number, current->balance);
        current = current->next;
    }
}

void print_transactions(transaction* head) {
    transaction* current = head;
    while (current) {
        printf("Transaction ID: %d, Description: %s, Amount: %.2lf\n", current->transaction_id, current->description, current->amount);
        current = current->next;
    }
}

int main() {
    customer* customers = NULL;
    transaction* transactions = NULL;

    // Insert some customers
    customers = insert_customer(customers);
    insert_customer(customers);

    // Insert some transactions
    transactions = insert_transaction(transactions);
    insert_transaction(transactions);

    // Print customers
    print_customers(customers);

    // Print transactions
    print_transactions(transactions);

    return 0;
}
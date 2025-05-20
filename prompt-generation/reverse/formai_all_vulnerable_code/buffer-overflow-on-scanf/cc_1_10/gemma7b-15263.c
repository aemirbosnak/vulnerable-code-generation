//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

typedef struct Transaction {
    int transaction_id;
    char description[200];
    double amount;
    struct Transaction* next;
} Transaction;

Customer* insert_customer(Customer* head) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
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

Transaction* insert_transaction(Transaction* head) {
    Transaction* new_transaction = (Transaction*)malloc(sizeof(Transaction));
    printf("Enter transaction description: ");
    scanf("%s", new_transaction->description);
    printf("Enter transaction amount: ");
    scanf("%lf", &new_transaction->amount);
    new_transaction->next = head;
    head = new_transaction;
    return head;
}

void print_customer_list(Customer* head) {
    Customer* current_customer = head;
    while (current_customer) {
        printf("Name: %s\n", current_customer->name);
        printf("Account Number: %d\n", current_customer->account_number);
        printf("Balance: %.2lf\n", current_customer->balance);
        printf("\n");
        current_customer = current_customer->next;
    }
}

void print_transaction_list(Transaction* head) {
    Transaction* current_transaction = head;
    while (current_transaction) {
        printf("Transaction ID: %d\n", current_transaction->transaction_id);
        printf("Description: %s\n", current_transaction->description);
        printf("Amount: %.2lf\n", current_transaction->amount);
        printf("\n");
        current_transaction = current_transaction->next;
    }
}

int main() {
    Customer* head = NULL;
    Transaction* head_trans = NULL;

    // Insert some customers and transactions
    insert_customer(head);
    insert_customer(head);
    insert_transaction(head_trans);
    insert_transaction(head_trans);

    // Print customer list
    print_customer_list(head);

    // Print transaction list
    print_transaction_list(head_trans);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

void add_customer(Customer**, int*);

void deposit(Customer*, double);

void withdraw(Customer*, double);

void transfer(Customer*, Customer*, double);

int main() {

    Customer* head = NULL;
    int customer_count = 0;

    // Add a few customers
    add_customer(&head, &customer_count);
    add_customer(&head, &customer_count);
    add_customer(&head, &customer_count);

    // Deposit and withdraw money
    deposit(head, 100);
    withdraw(head, 50);

    // Transfer money between customers
    transfer(head, head->next, 20);

    // Print customer information
    for (Customer* customer = head; customer; customer = customer->next) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", customer->name, customer->account_number, customer->balance);
    }

    return 0;
}

void add_customer(Customer** head, int* customer_count) {

    // Allocate memory for a new customer
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));

    // Get the customer's name, account number, and balance
    printf("Enter customer name: ");
    scanf("%s", new_customer->name);

    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);

    printf("Enter initial deposit: ");
    scanf("%lf", &new_customer->balance);

    // Add the new customer to the list
    new_customer->next = *head;
    *head = new_customer;

    // Increment the customer count
    (*customer_count)++;
}

void deposit(Customer* customer, double amount) {

    // Add the amount to the customer's balance
    customer->balance += amount;
}

void withdraw(Customer* customer, double amount) {

    // Check if the amount is less than the customer's balance
    if (amount <= customer->balance) {
        // Subtract the amount from the customer's balance
        customer->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

void transfer(Customer* customer_from, Customer* customer_to, double amount) {

    // Check if the amount is less than the customer's balance
    if (amount <= customer_from->balance) {
        // Subtract the amount from the customer's balance
        customer_from->balance -= amount;

        // Add the amount to the customer's balance
        customer_to->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}
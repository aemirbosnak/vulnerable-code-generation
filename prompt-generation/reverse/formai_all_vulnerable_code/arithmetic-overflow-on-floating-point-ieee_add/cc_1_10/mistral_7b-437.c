//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the magical structures for our banking entities
typedef struct {
    char name[50];
    int account_number;
    float balance;
    time_t last_transaction;
} Customer;

typedef struct {
    int id;
    Customer customer;
    float amount;
    char transaction_type[10];
} Transaction;

// Create a mystical array to store our customers
Customer *customers = NULL;
int num_customers = 0;

// Create a magical function to add new customers to our array
void add_customer(char *name, int account_number) {
    Customer new_customer;
    strcpy(new_customer.name, name);
    new_customer.account_number = account_number;
    new_customer.balance = 0.0;
    new_customer.last_transaction = time(NULL);

    // Allocate memory for new customer
    customers = realloc(customers, sizeof(Customer) * (num_customers + 1));

    // Store new customer in the array
    customers[num_customers] = new_customer;
    num_customers++;
}

// Create a wondrous function to perform transactions for our customers
void perform_transaction(Customer *customer, float amount, char *transaction_type) {
    Transaction new_transaction;
    new_transaction.id = rand() % 10000;
    strcpy(new_transaction.transaction_type, transaction_type);
    new_transaction.customer = *customer;
    new_transaction.amount = amount;

    // Update the customer's balance
    customer->balance += amount;
    customer->last_transaction = time(NULL);

    // Store the new transaction in our array
    // (Assume we have a separate array for transactions)
}

// Create a mesmerizing main function to start our banking adventure
int main(void) {
    srand(time(NULL)); // Seed the random number generator

    add_customer("Merlin the Magician", 12345);
    add_customer("Gandalf the Grey", 23456);
    add_customer("Elrond Half-elven", 34567);

    printf("The great adventure begins!\n");

    Customer *merlin = &customers[0];
    perform_transaction(merlin, 100.0, "Deposit Gold Coins");

    Customer *gandalf = &customers[1];
    perform_transaction(gandalf, -50.0, "Withdraw Silver Coins");

    Customer *elrond = &customers[2];
    perform_transaction(elrond, 200.0, "Borrow Precious Gems");

    for (int i = 0; i < num_customers; i++) {
        printf("\nCustomer %d:\n", i + 1);
        printf("Name: %s\n", customers[i].name);
        printf("Account Number: %d\n", customers[i].account_number);
        printf("Balance: %.2f\n", customers[i].balance);
        printf("Last Transaction: %s", ctime(&customers[i].last_transaction));
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000
#define MAX_ACCOUNTS 10000
#define MAX_TRANSACTIONS 100000

typedef struct {
    int id;
    char name[50];
    char address[100];
    float balance;
} Customer;

typedef struct {
    int id;
    int customerId;
    char type[10];
    float amount;
    char status[10];
    int date;
} Transaction;

Customer customers[MAX_CUSTOMERS];
Transaction transactions[MAX_TRANSACTIONS];

int numCustomers = 0;
int numTransactions = 0;

void addCustomer() {
    numCustomers++;
    printf("Enter customer name: ");
    scanf("%s", customers[numCustomers - 1].name);
    printf("Enter customer address: ");
    scanf("%s", customers[numCustomers - 1].address);
    customers[numCustomers - 1].id = numCustomers;
    customers[numCustomers - 1].balance = 0.0;
}

void addTransaction() {
    numTransactions++;
    printf("Enter transaction type (deposit/withdrawal): ");
    scanf("%s", transactions[numTransactions - 1].type);
    printf("Enter transaction amount: ");
    scanf("%f", &transactions[numTransactions - 1].amount);
    printf("Enter transaction status (pending/completed): ");
    scanf("%s", transactions[numTransactions - 1].status);
    transactions[numTransactions - 1].date = time(NULL);
}

void printCustomer(int id) {
    printf("Customer id: %d\n", id);
    printf("Customer name: %s\n", customers[id].name);
    printf("Customer address: %s\n", customers[id].address);
    printf("Customer balance: $%.2f\n", customers[id].balance);
}

void printTransaction(int id) {
    printf("Transaction id: %d\n", id);
    printf("Transaction type: %s\n", transactions[id].type);
    printf("Transaction amount: $%.2f\n", transactions[id].amount);
    printf("Transaction status: %s\n", transactions[id].status);
    printf("Transaction date: %s\n", ctime(&transactions[id].date));
}

void printAllCustomers() {
    for (int i = 0; i < numCustomers; i++) {
        printf("Customer id: %d\n", i + 1);
        printCustomer(i);
    }
}

void printAllTransactions() {
    for (int i = 0; i < numTransactions; i++) {
        printf("Transaction id: %d\n", i + 1);
        printTransaction(i);
    }
}

int main() {
    int choice;

    do {
        printf("\nBanking Record System\n");
        printf("1. Add customer\n");
        printf("2. Add transaction\n");
        printf("3. Print all customers\n");
        printf("4. Print all transactions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            addTransaction();
            break;
        case 3:
            printAllCustomers();
            break;
        case 4:
            printAllTransactions();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}
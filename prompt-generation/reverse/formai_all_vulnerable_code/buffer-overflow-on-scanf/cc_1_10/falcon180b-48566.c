//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000
#define MAX_TRANSACTION_SIZE 100
#define MAX_CUSTOMER_NAME 50
#define MAX_ACCOUNT_NUMBER 20

typedef struct {
    char name[MAX_CUSTOMER_NAME];
    int accountNumber;
    float balance;
} Customer;

typedef struct {
    int accountNumber;
    char type;
    float amount;
    char description[MAX_TRANSACTION_SIZE];
} Transaction;

Customer customers[MAX_ACCOUNTS];
Transaction transactions[MAX_TRANSACTIONS];
int numCustomers = 0;
int numTransactions = 0;

void addCustomer(char* name, int accountNumber, float balance) {
    strcpy(customers[numCustomers].name, name);
    customers[numCustomers].accountNumber = accountNumber;
    customers[numCustomers].balance = balance;
    numCustomers++;
}

void addTransaction(int accountNumber, char* type, float amount, char* description) {
    strcpy(transactions[numTransactions].description, description);
    transactions[numTransactions].accountNumber = accountNumber;
    transactions[numTransactions].type = type[0];
    transactions[numTransactions].amount = amount;
    numTransactions++;
}

void displayCustomers() {
    printf("\nCustomers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s (%d) - Balance: $%.2f\n", i+1, customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
}

void displayTransactions(int accountNumber) {
    printf("\nTransactions for account %d:\n", accountNumber);
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].accountNumber == accountNumber) {
            printf("%s - $%.2f - %c\n", transactions[i].description, transactions[i].amount, transactions[i].type);
        }
    }
}

int main() {
    addCustomer("John Doe", 12345, 1000.00);
    addCustomer("Jane Doe", 67890, 5000.00);
    addTransaction(12345, "D", 200.00, "Deposit");
    addTransaction(12345, "W", 50.00, "Withdrawal");
    addTransaction(67890, "D", 1000.00, "Deposit");

    displayCustomers();

    int accountNumber;
    printf("\nEnter account number to view transactions: ");
    scanf("%d", &accountNumber);

    displayTransactions(accountNumber);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_CUSTOMERS 1000
#define MAX_TRANSACTIONS 10000

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

typedef struct {
    int customer_id;
    char name[50];
} Customer;

typedef struct {
    int account_number;
    int customer_id;
    char type[10];
    float amount;
    char date[20];
} Transaction;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

int num_customers = 0;
Customer customers[MAX_CUSTOMERS];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    printf("Enter account number: ");
    scanf("%d", &accounts[num_accounts].account_number);
    printf("Enter name: ");
    scanf("%s", accounts[num_accounts].name);
    accounts[num_accounts].balance = 0;
    num_accounts++;
}

void add_customer() {
    printf("Enter customer ID: ");
    scanf("%d", &customers[num_customers].customer_id);
    printf("Enter name: ");
    scanf("%s", customers[num_customers].name);
    num_customers++;
}

void add_transaction() {
    printf("Enter account number: ");
    scanf("%d", &transactions[num_transactions].account_number);
    printf("Enter customer ID: ");
    scanf("%d", &transactions[num_transactions].customer_id);
    printf("Enter type (deposit/withdrawal): ");
    scanf("%s", transactions[num_transactions].type);
    printf("Enter amount: ");
    scanf("%f", &transactions[num_transactions].amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", transactions[num_transactions].date);
    num_transactions++;
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d - %s - $%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

void print_customers() {
    printf("Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d - %s\n", customers[i].customer_id, customers[i].name);
    }
}

void print_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d - %d - %s - $%.2f - %s\n", transactions[i].account_number, transactions[i].customer_id, transactions[i].type, transactions[i].amount, transactions[i].date);
    }
}

int main() {
    add_account();
    add_customer();
    add_transaction();

    print_accounts();
    print_customers();
    print_transactions();

    return 0;
}
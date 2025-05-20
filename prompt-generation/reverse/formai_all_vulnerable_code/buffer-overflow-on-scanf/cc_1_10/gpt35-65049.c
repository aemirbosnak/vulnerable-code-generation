//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char account[MAX_ACCOUNT_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer() {
    if (num_customers == MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }

    Customer new_customer;
    printf("Enter customer name: ");
    fgets(new_customer.name, MAX_NAME_LENGTH, stdin);
    strtok(new_customer.name, "\n"); // Remove newline character
    printf("Enter account number for %s: ", new_customer.name);
    scanf("%s", new_customer.account);
    printf("Enter initial balance for account %s: ", new_customer.account);
    scanf("%f", &new_customer.balance);
    getchar(); // Remove newline character from input buffer

    customers[num_customers++] = new_customer;
    printf("Customer %s added successfully.\n", new_customer.name);
}

void display_customer_info() {
    char account[MAX_ACCOUNT_LENGTH];
    printf("Enter customer account number: ");
    scanf("%s", account);

    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account, account) == 0) {
            printf("Customer name: %s\n", customers[i].name);
            printf("Account number: %s\n", customers[i].account);
            printf("Balance: $%.2f\n", customers[i].balance);
            return;
        }
    }

    printf("Error: Account number '%s' not found.\n", account);
}

int main() {
    printf("Welcome to the Banking Record System.\n");
    char input;

    do {
        printf("Enter 'a' to add a customer, 'd' to display customer information, or 'q' to quit: ");
        scanf("%c", &input);
        getchar(); // Remove newline character from input buffer

        switch (input) {
            case 'a':
                add_customer();
                break;
            case 'd':
                display_customer_info();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid input.\n");
        }
    } while (input != 'q');

    return 0;
}
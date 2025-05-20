//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000 // Maximum number of customers
#define MAX_NAME_LENGTH 50 // Maximum length of name
#define MAX_ACCOUNT_LENGTH 20 // Maximum length of account number

struct customer {
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_LENGTH];
    double balance;
};

int num_customers = 0; // Number of customers in the system
struct customer customers[MAX_CUSTOMERS]; // Array of customers

void add_customer() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }

    struct customer cust;

    printf("Enter customer name: ");
    scanf("%s", cust.name);

    printf("Enter account number: ");
    scanf("%s", cust.account_number);

    printf("Enter initial balance: ");
    scanf("%lf", &cust.balance);

    customers[num_customers++] = cust;

    printf("Customer added successfully.\n");
}

void print_customer(struct customer cust) {
    printf("Name: %s\n", cust.name);
    printf("Account Number: %s\n", cust.account_number);
    printf("Balance: %.2lf\n", cust.balance);
}

void list_customers() {
    if (num_customers == 0) {
        printf("No customers in the system.\n");
        return;
    }

    printf("List of customers:\n");

    for (int i = 0; i < num_customers; i++) {
        print_customer(customers[i]);
    }
}

void search_customer() {
    char account_number[MAX_ACCOUNT_LENGTH];
    printf("Enter account number to search for: ");
    scanf("%s", account_number);

    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_number, account_number) == 0) {
            print_customer(customers[i]);
            return;
        }
    }

    printf("Customer with account number %s does not exist.\n", account_number);
}

void deposit() {
    char account_number[MAX_ACCOUNT_LENGTH];
    double amount;

    printf("Enter account number: ");
    scanf("%s", account_number);

    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_number, account_number) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            customers[i].balance += amount;
            printf("Deposit completed. New balance for account number %s is %.2lf.\n", customers[i].account_number, customers[i].balance);
            return;
        }
    }

    printf("Customer with account number %s does not exist.\n", account_number);
}

void withdraw() {
    char account_number[MAX_ACCOUNT_LENGTH];
    double amount;

    printf("Enter account number: ");
    scanf("%s", account_number);

    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_number, account_number) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (customers[i].balance < amount) {
                printf("Error: Insufficient funds.\n");
            } else {
                customers[i].balance -= amount;
                printf("Withdrawal completed. New balance for account number %s is %.2lf.\n", customers[i].account_number, customers[i].balance);
            }
            return;
        }
    }

    printf("Customer with account number %s does not exist.\n", account_number);
}

void menu() {
    printf("\n");
    printf("Banking Record System\n");
    printf("1. Add customer\n");
    printf("2. List customers\n");
    printf("3. Search customer\n");
    printf("4. Deposit\n");
    printf("5. Withdraw\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice = 0;

    while (choice != 6) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                list_customers();
                break;
            case 3:
                search_customer();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
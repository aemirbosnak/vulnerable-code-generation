//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // Max customers allowed in the system

struct Customer {
    char name[100];
    int account_number;
    float balance;
    int loans; // Number of loans taken
    float loan_amount; // Amount of loans taken
};

struct Customer customers[MAX_CUSTOMERS];
int num_of_customers = 0;

void add_customer() {
    if (num_of_customers == MAX_CUSTOMERS) {
        printf("Error: Maximum customers reached\n");
        return;
    }

    struct Customer new_customer;

    printf("Enter customer name: ");
    scanf("%s", new_customer.name);

    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);

    printf("Enter initial balance: ");
    scanf("%f", &new_customer.balance);

    new_customer.loans = 0; // No loans taken initially
    new_customer.loan_amount = 0.0;

    customers[num_of_customers++] = new_customer;

    printf("\nNew customer added!\n");
}

void remove_customer(int account_number) {
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            for (int j = i; j < num_of_customers-1; j++) {
                customers[j] = customers[j+1];
            }
            num_of_customers--;
            printf("Customer removed!\n");
            return;
        }
    }
    printf("Error: Customer not found\n");
}

void deposit_amount(int account_number, float amount) {
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Amount deposited!\n");
            return;
        }
    }
    printf("Error: Customer not found\n");
}

void withdraw_amount(int account_number, float amount) {
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance < amount) {
                printf("Error: Insufficient balance\n");
                return;
            }
            customers[i].balance -= amount;
            printf("Amount withdrawn!\n");
            return;
        }
    }
    printf("Error: Customer not found\n");
}

void take_loan(int account_number, float amount) {
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].loans++; // Increment number of loans taken
            customers[i].loan_amount += amount; // Add loan amount to total loan amount
            customers[i].balance += amount; // Add loan amount to balance
            printf("Loan taken!\n");
            return;
        }
    }
    printf("Error: Customer not found\n");
}

void print_customer_info(int account_number) {
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Customer name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].account_number);
            printf("Balance: %.2f\n", customers[i].balance);
            printf("Loans taken: %d\n", customers[i].loans);
            printf("Total loan amount: %.2f\n", customers[i].loan_amount);
            return;
        }
    }
    printf("Error: Customer not found\n");
}

int main() {
    printf("Welcome to the C Banking Record System.\n");
    printf("--------------------------------------\n");

    while (1) {
        printf("\nType 'add' to add a customer\n");
        printf("Type 'remove' to remove a customer\n");
        printf("Type 'deposit' to deposit an amount\n");
        printf("Type 'withdraw' to withdraw an amount\n");
        printf("Type 'loan' to take a loan\n");
        printf("Type 'info' to get customer information\n");
        printf("Type 'exit' to exit the program\n");
        printf(">> ");

        char input[10];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            add_customer();
        } else if (strcmp(input, "remove") == 0) {
            int account_number;
            printf("Enter account number: ");
            scanf("%d", &account_number);
            remove_customer(account_number);
        } else if (strcmp(input, "deposit") == 0) {
            int account_number;
            float amount;
            printf("Enter account number: ");
            scanf("%d", &account_number);
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            deposit_amount(account_number, amount);
        } else if (strcmp(input, "withdraw") == 0) {
            int account_number;
            float amount;
            printf("Enter account number: ");
            scanf("%d", &account_number);
            printf("Enter withdraw amount: ");
            scanf("%f", &amount);
            withdraw_amount(account_number, amount);
        } else if (strcmp(input, "loan") == 0) {
            int account_number;
            float amount;
            printf("Enter account number: ");
            scanf("%d", &account_number);
            printf("Enter loan amount: ");
            scanf("%f", &amount);
            take_loan(account_number, amount);
        } else if (strcmp(input, "info") == 0) {
            int account_number;
            printf("Enter account number: ");
            scanf("%d", &account_number);
            print_customer_info(account_number);
        } else if (strcmp(input, "exit") == 0) {
            printf("\nThank you for using C Banking Record System!\n");
            break;
        } else {
            printf("Error: Invalid input\n");
        }
    }

    return 0;
}
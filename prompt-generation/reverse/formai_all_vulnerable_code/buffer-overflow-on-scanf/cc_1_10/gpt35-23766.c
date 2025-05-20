//FormAI DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for customer records
typedef struct {
    char name[50];
    int account_number;
    float balance;
} Customer;

// function to add new customer to the record
void add_customer(Customer* customers, int* num_of_customers) {
    // increment number of customers by 1
    (*num_of_customers)++;

    // resize the memory block for customers
    customers = (Customer*) realloc(customers, (*num_of_customers) * sizeof(Customer));

    // get customer details
    printf("Enter customer name: ");
    scanf("%s", customers[*num_of_customers - 1].name);
    printf("Enter account number: ");
    scanf("%d", &customers[*num_of_customers - 1].account_number);
    printf("Enter initial balance: ");
    scanf("%f", &customers[*num_of_customers - 1].balance);

    printf("\nCustomer added successfully!");
}

// function to deposit money for a specific customer
void deposit(Customer* customers, int num_of_customers) {
    int account_number;
    float deposit_amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    // find the customer with the given account number
    int customer_index = -1;
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            customer_index = i;
            break;
        }
    }

    if (customer_index != -1) {
        // deposit money and update balance
        printf("Enter deposit amount: ");
        scanf("%f", &deposit_amount);
        customers[customer_index].balance += deposit_amount;

        printf("\nMoney deposited successfully! Current balance: %.2f", customers[customer_index].balance);
    } else {
        printf("\nCustomer not found!");
    }
}

// function to withdraw money for a specific customer
void withdraw(Customer* customers, int num_of_customers) {
    int account_number;
    float withdraw_amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    // find the customer with the given account number
    int customer_index = -1;
    for (int i = 0; i < num_of_customers; i++) {
        if (customers[i].account_number == account_number) {
            customer_index = i;
            break;
        }
    }

    if (customer_index != -1) {
        // withdraw money if balance is sufficient
        printf("Enter withdraw amount: ");
        scanf("%f", &withdraw_amount);

        if (customers[customer_index].balance >= withdraw_amount) {
            customers[customer_index].balance -= withdraw_amount;
            printf("\nMoney withdrawn successfully! Current balance: %.2f", customers[customer_index].balance);
        } else {
            printf("\nInsufficient balance!");
        }
    } else {
        printf("\nCustomer not found!");
    }
}

// function to display all customer records
void display_records(Customer* customers, int num_of_customers) {
    printf("\nName \tAccount Number \tBalance\n");
    for (int i = 0; i < num_of_customers; i++) {
        printf("%s \t%d \t\t%.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
    }
}

int main() {
    int choice, num_of_customers = 0;
    Customer* customers = NULL;

    do {
        printf("\n\nBanking Record System");
        printf("\n1. Add Customer");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Records");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(customers, &num_of_customers);
                break;
            case 2:
                deposit(customers, num_of_customers);
                break;
            case 3:
                withdraw(customers, num_of_customers);
                break;
            case 4:
                display_records(customers, num_of_customers);
                break;
            case 5:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 5);

    // free allocated memory
    free(customers);
    return 0;
}
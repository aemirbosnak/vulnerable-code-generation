//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // maximum number of customers that can be stored in the bank record system

// define a struct to store customer details
typedef struct {
    char name[50];
    int account_no;
    float balance;
} customer;

// function prototypes
void add_customer(customer *bank, int *num_customers);
void search_customer(customer *bank, int num_customers);
void display_all_customers(customer *bank, int num_customers);
void update_balance(customer *bank, int num_customers);

int main() {
    customer bank[MAX_CUSTOMERS]; // an array of customers
    int num_customers = 0; // number of customers stored in the array

    int option; // variable to store user input

    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("Please select an option:\n");
        printf("1. Add a new customer\n");
        printf("2. Search for a customer\n");
        printf("3. Display all customers\n");
        printf("4. Update customer balance\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                add_customer(bank, &num_customers);
                break;
            case 2:
                search_customer(bank, num_customers);
                break;
            case 3:
                display_all_customers(bank, num_customers);
                break;
            case 4:
                update_balance(bank, num_customers);
                break;
            case 5:
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (1);

    return 0;
}

void add_customer(customer *bank, int *num_customers) {
    if (*num_customers >= MAX_CUSTOMERS) {
        printf("The bank record system is full.\n");
        return;
    }

    customer new_customer;

    printf("Please enter the name of the customer:\n");
    scanf("%s", new_customer.name);

    printf("Please enter the account number assigned to the customer:\n");
    scanf("%d", &new_customer.account_no);

    printf("Please enter the initial balance in the customer's account:\n");
    scanf("%f", &new_customer.balance);

    bank[*num_customers] = new_customer;

    printf("\nCustomer added successfully!\n");

    (*num_customers)++;
}

void search_customer(customer *bank, int num_customers) {
    if (num_customers == 0) {
        printf("There are no customers in the bank record system.\n");
        return;
    }

    int account_no;

    printf("Please enter the account number of the customer you wish to search for:\n");
    scanf("%d", &account_no);

    for (int i = 0; i < num_customers; i++) {
        if (bank[i].account_no == account_no) {
            printf("\nCustomer found!\n");
            printf("Name: %s\n", bank[i].name);
            printf("Account number: %d\n", bank[i].account_no);
            printf("Balance: %.2f\n", bank[i].balance);
            return;
        }
    }

    printf("The customer with account number %d was not found.\n", account_no);
}

void display_all_customers(customer *bank, int num_customers) {
    if (num_customers == 0) {
        printf("There are no customers in the bank record system.\n");
        return;
    }

    printf("\nList of all customers:\n");

    for (int i = 0; i < num_customers; i++) {
        printf("Name: %s\n", bank[i].name);
        printf("Account number: %d\n", bank[i].account_no);
        printf("Balance: %.2f\n", bank[i].balance);
        printf("\n");
    }
}

void update_balance(customer *bank, int num_customers) {
    if (num_customers == 0) {
        printf("There are no customers in the bank record system.\n");
        return;
    }

    int account_no;
    float new_balance;

    printf("Please enter the account number of the customer whose balance you wish to update:\n");
    scanf("%d", &account_no);

    for (int i = 0; i < num_customers; i++) {
        if (bank[i].account_no == account_no) {
            printf("Please enter the new balance in the customer's account:\n");
            scanf("%f", &new_balance);

            bank[i].balance = new_balance;

            printf("\nBalance updated successfully!\n");
            printf("Name: %s\n", bank[i].name);
            printf("Account number: %d\n", bank[i].account_no);
            printf("New balance: %.2f\n", bank[i].balance);

            return;
        }
    }

    printf("The customer with account number %d was not found.\n", account_no);
}
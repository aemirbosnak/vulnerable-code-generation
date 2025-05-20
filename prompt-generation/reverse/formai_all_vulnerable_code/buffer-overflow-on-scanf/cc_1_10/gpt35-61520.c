//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct customer {
    char name[50];
    int account_number;
    float balance;
};

// Function to display the options menu
void display_menu() {
    printf("\nWelcome to the Banking Record System!\n\n");
    printf("1. Add a new customer\n");
    printf("2. Edit customer's information\n");
    printf("3. Delete customer\n");
    printf("4. Display all customers\n");
    printf("5. Search for a customer\n");
    printf("6. Exit\n\n");
}

// Function to add a new customer
void add_customer(struct customer *customers, int *num_customers) {
    if (*num_customers < MAX_CUSTOMERS) {
        printf("\nEnter customer name: ");
        scanf("%s", customers[*num_customers].name);

        printf("Enter customer account number: ");
        scanf("%d", &customers[*num_customers].account_number);

        printf("Enter customer balance: ");
        scanf("%f", &customers[*num_customers].balance);

        (*num_customers)++;
        printf("\nCustomer added successfully!\n");
    }
    else {
        printf("\nSorry, the maximum number of customers has been reached.\n");
    }
}

// Function to edit a customer's information
void edit_customer(struct customer *customers, int num_customers) {
    int account_num, choice;
    printf("\nEnter account number of customer to edit: ");
    scanf("%d", &account_num);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_num) {
            found = 1;
            printf("\nWhat would you like to edit?\n");
            printf("1. Name\n");
            printf("2. Balance\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nEnter new name: ");
                    scanf("%s", customers[i].name);
                    break;
                case 2:
                    printf("\nEnter new balance: ");
                    scanf("%f", &customers[i].balance);
                    break;
                default:
                    printf("\nInvalid choice.\n");
                    break;
            }

            printf("\nCustomer information updated successfully!\n");
        }
    }

    if (!found) {
        printf("\nAccount number not found.\n");
    }
}

// Function to delete a customer
void delete_customer(struct customer *customers, int *num_customers) {
    int account_num, found = 0;
    printf("\nEnter account number of customer to delete: ");
    scanf("%d", &account_num);

    for (int i = 0; i < *num_customers; i++) {
        if (customers[i].account_number == account_num) {
            found = 1;
            *num_customers--;
            for (int j = i; j < *num_customers; j++) {
                customers[j] = customers[j + 1];
            }

            printf("\nCustomer deleted successfully!\n");
        }
    }

    if (!found) {
        printf("\nAccount number not found.\n");
    }
}

// Function to display all customers
void display_customers(struct customer *customers, int num_customers) {
    printf("\n%-20s %-20s %-20s\n", "NAME", "ACCOUNT NUMBER", "BALANCE");
    for (int i = 0; i < num_customers; i++) {
        printf("%-20s %-20d %-20.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
    }
}

// Function to search for a customer
void search_customer(struct customer *customers, int num_customers) {
    char search_name[50];
    printf("\nEnter name of customer to search for: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].name, search_name) == 0) {
            found = 1;
            printf("\n%-20s %-20s %-20s\n", "NAME", "ACCOUNT NUMBER", "BALANCE");
            printf("%-20s %-20d %-20.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
        }
    }

    if (!found) {
        printf("\nCustomer not found.\n");
    }
}

int main() {
    struct customer customers[MAX_CUSTOMERS];
    int num_customers = 0, choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(customers, &num_customers);
                break;
            case 2:
                edit_customer(customers, num_customers);
                break;
            case 3:
                delete_customer(customers, &num_customers);
                break;
            case 4:
                display_customers(customers, num_customers);
                break;
            case 5:
                search_customer(customers, num_customers);
                break;
            case 6:
                printf("\nThank you for using the Banking Record System.\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (1);

    return 0;
}
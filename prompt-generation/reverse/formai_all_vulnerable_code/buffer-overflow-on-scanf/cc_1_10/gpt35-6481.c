//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Structure for storing customer information
struct customer {
    char name[100];
    int account_no;
    float account_balance;
};

// Function to add a new customer to the record
void add_customer(struct customer bank_record[], int *num_customers) {
    if (*num_customers == MAX_CUSTOMERS) {
        printf("Cannot add more customers - maximum capacity reached!\n");
        return;
    }

    printf("Enter customer name: ");
    scanf("%s", bank_record[*num_customers].name);

    printf("Enter account number: ");
    scanf("%d", &bank_record[*num_customers].account_no);

    printf("Enter account balance: ");
    scanf("%f", &bank_record[*num_customers].account_balance);

    (*num_customers)++;
}

// Function to search for a customer in the record by account number
void search_customer(struct customer bank_record[], int num_customers) {
    int account_no;

    printf("Enter account number: ");
    scanf("%d", &account_no);

    for (int i = 0; i < num_customers; i++) {
        if (bank_record[i].account_no == account_no) {
            printf("Customer found:\n");
            printf("Name: %s\n", bank_record[i].name);
            printf("Account number: %d\n", bank_record[i].account_no);
            printf("Account balance: %f\n", bank_record[i].account_balance);
            return;
        }
    }

    printf("Customer not found!\n");
}

int main() {
    struct customer bank_record[MAX_CUSTOMERS];
    int num_customers = 0;
    int choice;

    printf("Welcome to the bank record system!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a new customer\n");
        printf("2. Search for a customer\n");
        printf("3. Exit\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(bank_record, &num_customers);
                break;
            case 2:
                search_customer(bank_record, num_customers);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
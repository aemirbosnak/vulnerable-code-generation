//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    char name[100];
    int acc_no;
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer() {
    if (num_customers == MAX_CUSTOMERS) {
        printf("Maximum number of customers reached.\n");
        return;
    }

    Customer new_customer;

    printf("Enter customer name: ");
    scanf("%s", new_customer.name);

    printf("Enter customer account number: ");
    scanf("%d", &new_customer.acc_no);

    printf("Enter customer balance: ");
    scanf("%f", &new_customer.balance);

    customers[num_customers] = new_customer;
    num_customers++;

    printf("Customer added successfully.\n");
}

void get_customer_details() {
    int acc_no;
    printf("Enter customer account number: ");
    scanf("%d", &acc_no);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].acc_no == acc_no) {
            printf("Name: %s\n", customers[i].name);
            printf("Account Number: %d\n", customers[i].acc_no);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }

    printf("Customer not found.\n");
}

void list_all_customers() {
    printf("Customer List:\n");

    for (int i = 0; i < num_customers; i++) {
        printf("%d) Name: %s\tAccount Number: %d\tBalance: %.2f\n",
            i+1, customers[i].name, customers[i].acc_no, customers[i].balance);
    }
}

int main() {
    int running = 1;

    while (running) {
        int option;
        printf("Options:\n");
        printf("1) Add new customer\n");
        printf("2) Get customer details\n");
        printf("3) List all customers\n");
        printf("4) Exit\n");

        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_customer();
                break;
            case 2:
                get_customer_details();
                break;
            case 3:
                list_all_customers();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
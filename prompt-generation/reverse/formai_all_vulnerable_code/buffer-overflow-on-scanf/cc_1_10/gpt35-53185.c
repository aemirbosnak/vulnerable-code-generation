//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    char account_no[20];
    char address[100];
    char phone[15];
    float balance;
} customers[100];

int num_customers = 0;

void add_customer() {
    struct customer new_customer;
    printf("Enter customer name: ");
    fgets(new_customer.name, 50, stdin);
    printf("Enter account number: ");
    fgets(new_customer.account_no, 20, stdin);
    printf("Enter customer address: ");
    fgets(new_customer.address, 100, stdin);
    printf("Enter customer phone number: ");
    fgets(new_customer.phone, 15, stdin);
    printf("Enter account balance: ");
    scanf("%f", &new_customer.balance);
    getchar();
    customers[num_customers++] = new_customer;
    printf("Customer added successfully!\n");
}

void search_customer() {
    char account_no[20];
    printf("Enter account number: ");
    fgets(account_no, 20, stdin);
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_no, account_no) == 0) {
            printf("Customer found!\n");
            printf("Name: %s", customers[i].name);
            printf("Address: %s", customers[i].address);
            printf("Phone number: %s", customers[i].phone);
            printf("Account balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Customer not found!\n");
}

void print_customers() {
    printf("List of customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Name: %s", customers[i].name);
        printf("Account number: %s", customers[i].account_no);
        printf("Address: %s", customers[i].address);
        printf("Phone number: %s", customers[i].phone);
        printf("Account balance: %.2f\n", customers[i].balance);
    }
}

int main() {
    int choice;
    while (1) {
        printf("C Banking Record System\n");
        printf("1. Add customer\n");
        printf("2. Search customer\n");
        printf("3. Print all customers\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                search_customer();
                break;
            case 3:
                print_customers();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input!\n");
                break;
        }
    }
    return 0;
}
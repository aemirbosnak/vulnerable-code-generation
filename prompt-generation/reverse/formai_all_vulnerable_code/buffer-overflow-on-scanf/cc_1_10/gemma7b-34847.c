//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

Customer* insert_customer(Customer* head) {
    Customer* new_customer = malloc(sizeof(Customer));
    printf("Enter name: ");
    scanf("%s", new_customer->name);
    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_customer->balance);

    new_customer->next = head;
    head = new_customer;

    return head;
}

void print_customers(Customer* head) {
    Customer* current = head;
    while (current) {
        printf("Name: %s, Account Number: %d, Balance: %lf\n", current->name, current->account_number, current->balance);
        current = current->next;
    }
}

int main() {
    Customer* head = NULL;

    while (1) {
        printf("1. Insert customer\n");
        printf("2. Print customers\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert_customer(head);
                break;
            case 2:
                print_customers(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}
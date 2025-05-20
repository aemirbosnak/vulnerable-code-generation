//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a customer's information
struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
};

// Function to insert a customer at the end of the linked list
void insert_customer(struct customer** head) {
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));

    // Get the customer's name, account number, and balance
    printf("Enter customer name: ");
    scanf("%s", new_customer->name);

    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_customer->balance);

    // If the list is empty, make the new customer the first customer
    if (*head == NULL) {
        *head = new_customer;
    } else {
        // Traverse the list until the last customer is reached
        struct customer* current_customer = *head;
        while (current_customer->next != NULL) {
            current_customer = current_customer->next;
        }

        // Insert the new customer at the end of the list
        current_customer->next = new_customer;
    }
}

// Function to print the customers in the linked list
void print_customers(struct customer* head) {
    // Traverse the list and print each customer's information
    struct customer* current_customer = head;
    while (current_customer) {
        printf("Name: %s\n", current_customer->name);
        printf("Account Number: %d\n", current_customer->account_number);
        printf("Balance: %.2lf\n", current_customer->balance);
        printf("\n");
        current_customer = current_customer->next;
    }
}

int main() {
    // Create a linked list of customers
    struct customer* head = NULL;

    // Insert some customers
    insert_customer(&head);
    insert_customer(&head);
    insert_customer(&head);

    // Print the customers
    print_customers(head);

    return 0;
}
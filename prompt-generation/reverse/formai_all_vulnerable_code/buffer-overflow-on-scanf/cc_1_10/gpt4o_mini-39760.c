//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Customer;

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void add_customer();
void view_customers();
void search_customer();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                add_customer();
                break;
            case 2: 
                view_customers();
                break;
            case 3: 
                search_customer();
                break;
            case 4: 
                printf("Exiting program.\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Customer Database Menu ---\n");
    printf("1. Add Customer\n");
    printf("2. View Customers\n");
    printf("3. Search Customer\n");
    printf("4. Exit\n");
}

void add_customer() {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("Customer database is full!\n");
        return;
    }

    Customer new_customer;
    new_customer.id = customer_count + 1;

    printf("Enter customer name: ");
    getchar(); // to clear the newline after the last input
    fgets(new_customer.name, NAME_LENGTH, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = '\0'; // remove newline

    printf("Enter customer email: ");
    fgets(new_customer.email, EMAIL_LENGTH, stdin);
    new_customer.email[strcspn(new_customer.email, "\n")] = '\0'; // remove newline

    customers[customer_count] = new_customer;
    customer_count++;

    printf("Customer added successfully!\n");
}

void view_customers() {
    if (customer_count == 0) {
        printf("No customers to display.\n");
        return;
    }

    printf("\n--- Customer List ---\n");
    for (int i = 0; i < customer_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", customers[i].id, customers[i].name, customers[i].email);
    }
}

void search_customer() {
    if (customer_count == 0) {
        printf("No customers in the database.\n");
        return;
    }

    char search_name[NAME_LENGTH];
    printf("Enter the name of the customer to search: ");
    getchar(); // to clear the newline after the last input
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // remove newline

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < customer_count; i++) {
        if (strcasecmp(customers[i].name, search_name) == 0) {
            printf("ID: %d, Name: %s, Email: %s\n", customers[i].id, customers[i].name, customers[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No customer found with the name '%s'.\n", search_name);
    }
}
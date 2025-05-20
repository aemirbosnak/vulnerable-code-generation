//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 100
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
void delete_customer();
void display_menu();

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                delete_customer();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n=== Customer Database ===\n");
    printf("1. Add Customer\n");
    printf("2. View Customers\n");
    printf("3. Delete Customer\n");
    printf("4. Exit\n");
}

void add_customer() {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("Database is full. Cannot add more customers.\n");
        return;
    }

    Customer new_customer;
    new_customer.id = customer_count + 1; // ID starts from 1

    printf("Enter customer name: ");
    getchar(); // To consume the newline character left by previous input
    fgets(new_customer.name, NAME_LENGTH, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = 0; // Remove newline

    printf("Enter customer email: ");
    fgets(new_customer.email, EMAIL_LENGTH, stdin);
    new_customer.email[strcspn(new_customer.email, "\n")] = 0; // Remove newline

    customers[customer_count] = new_customer;
    customer_count++;
    printf("Customer added successfully! ID: %d\n", new_customer.id);
}

void view_customers() {
    if (customer_count == 0) {
        printf("There are no customers in the database.\n");
        return;
    }

    printf("\n=== Customer List ===\n");
    for (int i = 0; i < customer_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", customers[i].id, customers[i].name, customers[i].email);
    }
}

void delete_customer() {
    if (customer_count == 0) {
        printf("There are no customers to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the customer to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > customer_count) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    // Shift customers down to fill the gap
    for (int i = id - 1; i < customer_count - 1; i++) {
        customers[i] = customers[i + 1];
    }
    customer_count--;
    printf("Customer with ID %d deleted successfully!\n", id);
}
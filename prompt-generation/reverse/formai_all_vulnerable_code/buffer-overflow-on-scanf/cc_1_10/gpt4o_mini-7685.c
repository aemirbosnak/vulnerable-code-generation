//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50
#define DOB_LENGTH 11

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char dateOfBirth[DOB_LENGTH];
} Customer;

Customer *customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Database is full! Cannot add more customers.\n");
        return;
    }

    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->id = customerCount + 1;

    printf("Enter customer name: ");
    fgets(newCustomer->name, NAME_LENGTH, stdin);
    newCustomer->name[strcspn(newCustomer->name, "\n")] = 0; // Remove newline character

    printf("Enter date of birth (YYYY-MM-DD): ");
    fgets(newCustomer->dateOfBirth, DOB_LENGTH, stdin);
    newCustomer->dateOfBirth[strcspn(newCustomer->dateOfBirth, "\n")] = 0; // Remove newline character

    customers[customerCount++] = newCustomer;
    printf("Customer %d added successfully!\n", newCustomer->id);
}

void displayCustomers() {
    printf("\n--- Customer Database ---\n");
    if (customerCount == 0) {
        printf("No customers found!\n");
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        printf("ID: %d, Name: %s, Date of Birth: %s\n", customers[i]->id, customers[i]->name, customers[i]->dateOfBirth);
    }
}

void searchCustomer() {
    int id;
    printf("Enter Customer ID to search: ");
    scanf("%d", &id);
    getchar(); // consume newline

    if (id < 1 || id > customerCount) {
        printf("Customer with ID %d not found!\n", id);
        return;
    }

    Customer *customer = customers[id - 1];
    printf("ID: %d, Name: %s, Date of Birth: %s\n", customer->id, customer->name, customer->dateOfBirth);
}

void deleteCustomer() {
    int id;
    printf("Enter Customer ID to delete: ");
    scanf("%d", &id);
    getchar(); // consume newline

    if (id < 1 || id > customerCount) {
        printf("Customer with ID %d not found!\n", id);
        return;
    }

    free(customers[id - 1]);

    for (int i = id - 1; i < customerCount - 1; i++) {
        customers[i] = customers[i + 1];
    }
    customerCount--;
    printf("Customer with ID %d has been deleted successfully!\n", id);
}

void showMenu() {
    printf("\n--- Customer Database Menu ---\n");
    printf("1. Add Customer\n");
    printf("2. Display Customers\n");
    printf("3. Search Customer\n");
    printf("4. Delete Customer\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomers();
                break;
            case 3:
                searchCustomer();
                break;
            case 4:
                deleteCustomer();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                // Freeing memory
                for (int i = 0; i < customerCount; i++) {
                    free(customers[i]);
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
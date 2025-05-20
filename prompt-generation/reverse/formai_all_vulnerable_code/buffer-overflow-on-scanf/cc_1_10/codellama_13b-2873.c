//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Structure to store details of a customer
struct customer {
    char name[50];
    int age;
    char gender;
    char phone_number[15];
    char email[50];
    int table_number;
};

// Function to add a new customer to the system
void add_customer(struct customer* customers, int* total_customers) {
    printf("Enter customer details:\n");
    printf("Name: ");
    scanf("%s", customers[*total_customers].name);
    printf("Age: ");
    scanf("%d", &customers[*total_customers].age);
    printf("Gender: ");
    scanf(" %c", &customers[*total_customers].gender);
    printf("Phone Number: ");
    scanf("%s", customers[*total_customers].phone_number);
    printf("Email: ");
    scanf("%s", customers[*total_customers].email);
    printf("Table Number: ");
    scanf("%d", &customers[*total_customers].table_number);
    *total_customers += 1;
}

// Function to display all customers in the system
void display_customers(struct customer* customers, int total_customers) {
    int i;
    for (i = 0; i < total_customers; i++) {
        printf("Customer %d:\n", i + 1);
        printf("Name: %s\n", customers[i].name);
        printf("Age: %d\n", customers[i].age);
        printf("Gender: %c\n", customers[i].gender);
        printf("Phone Number: %s\n", customers[i].phone_number);
        printf("Email: %s\n", customers[i].email);
        printf("Table Number: %d\n", customers[i].table_number);
        printf("\n");
    }
}

// Function to search for a customer in the system
void search_customer(struct customer* customers, int total_customers) {
    char search_name[50];
    printf("Enter customer name to search: ");
    scanf("%s", search_name);
    int i;
    for (i = 0; i < total_customers; i++) {
        if (strcmp(search_name, customers[i].name) == 0) {
            printf("Customer found:\n");
            printf("Name: %s\n", customers[i].name);
            printf("Age: %d\n", customers[i].age);
            printf("Gender: %c\n", customers[i].gender);
            printf("Phone Number: %s\n", customers[i].phone_number);
            printf("Email: %s\n", customers[i].email);
            printf("Table Number: %d\n", customers[i].table_number);
            break;
        }
    }
    if (i == total_customers) {
        printf("Customer not found.\n");
    }
}

// Function to update a customer's details in the system
void update_customer(struct customer* customers, int total_customers) {
    char update_name[50];
    printf("Enter customer name to update: ");
    scanf("%s", update_name);
    int i;
    for (i = 0; i < total_customers; i++) {
        if (strcmp(update_name, customers[i].name) == 0) {
            printf("Enter updated details:\n");
            printf("Name: ");
            scanf("%s", customers[i].name);
            printf("Age: ");
            scanf("%d", &customers[i].age);
            printf("Gender: ");
            scanf(" %c", &customers[i].gender);
            printf("Phone Number: ");
            scanf("%s", customers[i].phone_number);
            printf("Email: ");
            scanf("%s", customers[i].email);
            printf("Table Number: ");
            scanf("%d", &customers[i].table_number);
            break;
        }
    }
    if (i == total_customers) {
        printf("Customer not found.\n");
    }
}

// Function to delete a customer from the system
void delete_customer(struct customer* customers, int* total_customers) {
    char delete_name[50];
    printf("Enter customer name to delete: ");
    scanf("%s", delete_name);
    int i;
    for (i = 0; i < *total_customers; i++) {
        if (strcmp(delete_name, customers[i].name) == 0) {
            customers[i] = customers[*total_customers - 1];
            *total_customers -= 1;
            break;
        }
    }
    if (i == *total_customers) {
        printf("Customer not found.\n");
    }
}

int main() {
    // Declare and initialize variables
    struct customer customers[100];
    int total_customers = 0;
    int choice;

    // Main menu
    printf("Café Billing System\n");
    printf("1. Add customer\n");
    printf("2. Display all customers\n");
    printf("3. Search customer\n");
    printf("4. Update customer\n");
    printf("5. Delete customer\n");
    printf("6. Exit\n");

    // Loop until user chooses to exit
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_customer(customers, &total_customers);
            break;
        case 2:
            display_customers(customers, total_customers);
            break;
        case 3:
            search_customer(customers, total_customers);
            break;
        case 4:
            update_customer(customers, total_customers);
            break;
        case 5:
            delete_customer(customers, &total_customers);
            break;
        case 6:
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
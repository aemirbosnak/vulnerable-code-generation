//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers
#define MAX_CUSTOMERS 100

// Define the structure of a customer record
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    double balance;
} customer_record;

// Define the array of customer records
customer_record customers[MAX_CUSTOMERS];

// Define the number of customers
int num_customers = 0;

// Function to add a new customer record
void add_customer(char *name, char *address, char *phone, double balance) {
    // Check if the array of customer records is full
    if (num_customers == MAX_CUSTOMERS) {
        printf("Error: The array of customer records is full.\n");
        return;
    }

    // Copy the customer information into the array of customer records
    strcpy(customers[num_customers].name, name);
    strcpy(customers[num_customers].address, address);
    strcpy(customers[num_customers].phone, phone);
    customers[num_customers].balance = balance;

    // Increment the number of customers
    num_customers++;
}

// Function to search for a customer record by name
int search_customer(char *name) {
    // Linear search through the array of customer records
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            return i;
        }
    }

    // Return -1 if the customer record was not found
    return -1;
}

// Function to delete a customer record by name
void delete_customer(char *name) {
    // Search for the customer record by name
    int index = search_customer(name);

    // Check if the customer record was found
    if (index == -1) {
        printf("Error: The customer record was not found.\n");
        return;
    }

    // Shift the remaining customer records down one position
    for (int i = index; i < num_customers - 1; i++) {
        customers[i] = customers[i + 1];
    }

    // Decrement the number of customers
    num_customers--;
}

// Function to print the customer records
void print_customers() {
    // Print the header
    printf("%-20s %-20s %-20s %-10s\n", "Name", "Address", "Phone", "Balance");

    // Print the customer records
    for (int i = 0; i < num_customers; i++) {
        printf("%-20s %-20s %-20s $%.2f\n", customers[i].name, customers[i].address, customers[i].phone, customers[i].balance);
    }
}

// Function to get a double from the user
double get_double() {
    double input;
    while (scanf("%lf", &input) != 1) {
        printf("Error: Invalid input. Please enter a double.\n");
        while (getchar() != '\n'); // Clear the input buffer
    }
    return input;
}

// Main function
int main() {
    // Add some sample customer records
    add_customer("John Doe", "123 Main Street", "555-1212", 1000.00);
    add_customer("Jane Doe", "456 Elm Street", "555-1213", 2000.00);
    add_customer("John Smith", "789 Oak Street", "555-1214", 3000.00);

    // Print the customer records
    print_customers();

    // Get the name of the customer to search for
    char name[50];
    printf("Enter the name of the customer to search for: ");
    scanf("%s", name);

    // Search for the customer record
    int index = search_customer(name);

    // Check if the customer record was found
    if (index == -1) {
        printf("Error: The customer record was not found.\n");
    } else {
        // Print the customer record
        printf("Customer record:\n");
        printf("%-20s %-20s %-20s %-10s\n", "Name", "Address", "Phone", "Balance");
        printf("%-20s %-20s %-20s $%.2f\n", customers[index].name, customers[index].address, customers[index].phone, customers[index].balance);
    }

    // Get the name of the customer to delete
    printf("Enter the name of the customer to delete: ");
    scanf("%s", name);

    // Delete the customer record
    delete_customer(name);

    // Print the customer records
    print_customers();

    return 0;
}
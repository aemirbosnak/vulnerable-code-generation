//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
typedef struct {
    char name[20];
    char address[40];
    int age;
} customer_t;

// Function to read customer data from a file
customer_t* read_customer_data(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");

    // Check if the file is empty
    if (feof(file)) {
        return NULL;
    }

    // Read the customer data
    customer_t* customer = (customer_t*) malloc(sizeof(customer_t));
    fscanf(file, "%19s %39s %d", customer->name, customer->address, &customer->age);

    // Return the customer data
    return customer;
}

// Function to write customer data to a file
void write_customer_data(const char* file_name, customer_t* customer) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");

    // Write the customer data
    fprintf(file, "%19s %39s %d", customer->name, customer->address, customer->age);

    // Close the file
    fclose(file);
}

int main() {
    // Create a list of customers
    customer_t* customers = (customer_t*) malloc(sizeof(customer_t));

    // Read customer data from a file
    customers = read_customer_data("customers.dat");

    // Add a new customer
    customer_t new_customer = {
        .name = "John Doe",
        .address = "123 Main St",
        .age = 35
    };
    customers = realloc(customers, (sizeof(customer_t) * (1 + sizeof(customers) / sizeof(customer_t))));
    memcpy(&customers[0], &new_customer, sizeof(customer_t));

    // Write the updated customer data to a file
    write_customer_data("customers.dat", customers);

    // Free the memory
    free(customers);

    return 0;
}
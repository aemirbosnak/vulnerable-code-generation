//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int age;
} customer_t;

// Function to read customer information from a file
customer_t *read_customer_file(char *file_name) {
    customer_t *customers = NULL;
    int i = 0;
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    while (i < 10) {
        // Read a customer record from the file
        fscanf(file, "%s %s %d", customers[i].name, customers[i].address, &customers[i].age);

        // Check for end of file
        if (feof(file)) {
            break;
        }

        // Increment the index
        i++;
    }

    fclose(file);

    return customers;
}

// Function to write customer information to a file
void write_customer_file(char *file_name, customer_t *customers) {
    int i = 0;
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (i = 0; i < 10; i++) {
        fprintf(file, "%s %s %d", customers[i].name, customers[i].address, customers[i].age);
        if (i != 9) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

int main() {
    // Create a list of customers
    customer_t customers[10] = {
        {"Alice", "123 Main St", 30},
        {"Bob", "456 Elm St", 40},
        {"Charlie", "789 Oak St", 50},
        {"David", "901 Maple St", 25},
        {"Eve", "234 Sycamore St", 35},
        {"Frank", "345 Pine St", 45},
        {"Grace", "567 Cedar St", 20},
        {"Helen", "678 Ash St", 55},
        {"Ivy", "789 Oak St", 60},
        {"Jane", "901 Maple St", 40}
    };

    // Read the customer information from a file
    customer_t *customers_from_file = read_customer_file("customers.dat");

    // Write the customer information to a file
    write_customer_file("new_customers.dat", customers);

    // Print the customer information
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s %d\n", i + 1, customers[i].name, customers[i].address, customers[i].age);
    }

    return 0;
}
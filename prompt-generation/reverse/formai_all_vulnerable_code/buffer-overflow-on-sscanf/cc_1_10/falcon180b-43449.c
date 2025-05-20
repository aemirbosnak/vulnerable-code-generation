//Falcon-180B DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a customer
typedef struct {
    char name[50];
    int age;
    int income;
} Customer;

// Function to compare two customers based on their income
int compare_customers(const void *a, const void *b) {
    Customer *customer_a = (Customer *)a;
    Customer *customer_b = (Customer *)b;

    if (customer_a->income > customer_b->income) {
        return 1;
    } else if (customer_a->income < customer_b->income) {
        return -1;
    } else {
        return 0;
    }
}

// Function to read customer data from a file
void read_customer_data(Customer *customers, int num_customers, FILE *file) {
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %d %d", customers[num_customers - 1].name, &customers[num_customers - 1].age, &customers[num_customers - 1].income);
        num_customers++;
    }
}

int main() {
    int num_customers = 0;
    Customer *customers = NULL;

    // Read customer data from a file
    FILE *file = fopen("customer_data.txt", "r");
    if (file!= NULL) {
        read_customer_data(customers, num_customers, file);
        fclose(file);
    } else {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Sort customers by income
    qsort(customers, num_customers, sizeof(Customer), compare_customers);

    // Print customer data
    printf("Customer Data:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s %d %d\n", customers[i].name, customers[i].age, customers[i].income);
    }

    // Free memory
    free(customers);

    return 0;
}
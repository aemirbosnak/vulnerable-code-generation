//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50
#define FILENAME "purchases.txt"

// Struct to hold customer data
typedef struct {
    char name[MAX_NAME_LENGTH];
    double total_spent;
} Customer;

// Function to read data from a file and populate the customer array
int readData(Customer customers[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return -1;
    }

    char name[MAX_NAME_LENGTH];
    double amount;
    int customer_count = 0;

    while (fscanf(file, "%49s %lf", name, &amount) != EOF) {
        int found = 0;
        for (int i = 0; i < customer_count; i++) {
            if (strcmp(customers[i].name, name) == 0) {
                customers[i].total_spent += amount;
                found = 1;
                break;
            }
        }
        if (!found && customer_count < MAX_CUSTOMERS) {
            strcpy(customers[customer_count].name, name);
            customers[customer_count].total_spent = amount;
            customer_count++;
        }
    }

    fclose(file);
    return customer_count;
}

// Function to find the highest spending customer
Customer findHighestSpender(Customer customers[], int customer_count) {
    Customer highest_spender = customers[0];

    for (int i = 1; i < customer_count; i++) {
        if (customers[i].total_spent > highest_spender.total_spent) {
            highest_spender = customers[i];
        }
    }
    return highest_spender;
}

// Function to print all customers and their total spent
void printCustomerData(Customer customers[], int customer_count) {
    printf("Customer Spending Data:\n");
    for (int i = 0; i < customer_count; i++) {
        printf("Name: %s, Total Spent: $%.2f\n", customers[i].name, customers[i].total_spent);
    }
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int customer_count;

    customer_count = readData(customers, FILENAME);
    if (customer_count < 0) {
        return 1; // Exit on file read error
    }

    printCustomerData(customers, customer_count);

    if (customer_count > 0) {
        Customer highest_spender = findHighestSpender(customers, customer_count);
        printf("\nHighest Spender:\n");
        printf("Name: %s, Total Spent: $%.2f\n", highest_spender.name, highest_spender.total_spent);
    } else {
        printf("No customer data found.\n");
    }

    return 0;
}
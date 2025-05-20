//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: systematic
// Program to perform data mining on a dataset of customer information

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store customer information
struct Customer {
    char name[100];
    char address[100];
    char phone[10];
    char email[100];
    int age;
    int account_balance;
};

// Function to read customer information from a file
void read_customer_data(struct Customer *customers, int *num_customers, char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }
    *num_customers = 0;
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        sscanf(line, "%s %s %s %s %d %d", customers[*num_customers].name, customers[*num_customers].address, customers[*num_customers].phone, customers[*num_customers].email, &customers[*num_customers].age, &customers[*num_customers].account_balance);
        *num_customers += 1;
    }
    fclose(file);
}

// Function to perform data mining on the customer information
void perform_data_mining(struct Customer *customers, int num_customers) {
    // Find the customer with the highest account balance
    int max_balance = 0;
    int max_balance_customer = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_balance > max_balance) {
            max_balance = customers[i].account_balance;
            max_balance_customer = i;
        }
    }
    printf("Customer with highest account balance: %s (balance: %d)\n", customers[max_balance_customer].name, max_balance);

    // Find the customer with the lowest account balance
    int min_balance = 10000;
    int min_balance_customer = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_balance < min_balance) {
            min_balance = customers[i].account_balance;
            min_balance_customer = i;
        }
    }
    printf("Customer with lowest account balance: %s (balance: %d)\n", customers[min_balance_customer].name, min_balance);

    // Find the customer with the highest age
    int max_age = 0;
    int max_age_customer = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].age > max_age) {
            max_age = customers[i].age;
            max_age_customer = i;
        }
    }
    printf("Customer with highest age: %s (age: %d)\n", customers[max_age_customer].name, max_age);

    // Find the customer with the lowest age
    int min_age = 100;
    int min_age_customer = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].age < min_age) {
            min_age = customers[i].age;
            min_age_customer = i;
        }
    }
    printf("Customer with lowest age: %s (age: %d)\n", customers[min_age_customer].name, min_age);
}

int main() {
    // Read customer information from a file
    struct Customer customers[100];
    int num_customers;
    char file_name[] = "customers.txt";
    read_customer_data(customers, &num_customers, file_name);

    // Perform data mining on the customer information
    perform_data_mining(customers, num_customers);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold customer data
struct customer {
    char name[50];
    int age;
    float income;
};

// Function to create a new customer record
void create_customer(struct customer *cust) {
    printf("Enter customer name: ");
    scanf("%s", cust->name);

    printf("Enter customer age: ");
    scanf("%d", &cust->age);

    printf("Enter customer income: ");
    scanf("%f", &cust->income);
}

// Function to display customer records
void display_customers(struct customer *cust, int num_customers) {
    printf("\nCustomer records:\n");

    for (int i = 0; i < num_customers; i++) {
        printf("Name: %s\n", cust[i].name);
        printf("Age: %d\n", cust[i].age);
        printf("Income: $%.2f\n\n", cust[i].income);
    }
}

// Function to sort customer records by income
void sort_customers(struct customer *cust, int num_customers) {
    for (int i = 0; i < num_customers - 1; i++) {
        for (int j = i + 1; j < num_customers; j++) {
            if (cust[i].income < cust[j].income) {
                struct customer temp = cust[i];
                cust[i] = cust[j];
                cust[j] = temp;
            }
        }
    }
}

// Function to find the average income of all customers
float find_average_income(struct customer *cust, int num_customers) {
    float sum = 0;

    for (int i = 0; i < num_customers; i++) {
        sum += cust[i].income;
    }

    return sum / num_customers;
}

int main() {
    int num_customers;
    printf("Enter number of customers: ");
    scanf("%d", &num_customers);

    struct customer cust[num_customers];

    // Create new customer records
    for (int i = 0; i < num_customers; i++) {
        create_customer(&cust[i]);
    }

    // Sort customer records by income
    sort_customers(cust, num_customers);

    // Display sorted customer records
    printf("\nSorted customer records:\n");
    display_customers(cust, num_customers);

    // Find average income of all customers
    float avg_income = find_average_income(cust, num_customers);
    printf("\nAverage income: $%.2f\n", avg_income);

    return 0;
}
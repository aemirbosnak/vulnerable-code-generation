//Gemma-7B DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store customer data
typedef struct Customer {
    char name[50];
    int age;
    char gender[20];
    float income;
    char occupation[50];
} Customer;

// Function to read customer data from a file
void readCustomerData(Customer *customer, FILE *file) {
    fscanf(file, "%s %d %s %f %s", customer->name, &customer->age, customer->gender, &customer->income, customer->occupation);
}

// Function to calculate customer's credit score
int calculateCreditScore(Customer customer) {
    int creditScore = 0;
    if (customer.income >= 50000) {
        creditScore += 100;
    } else if (customer.income >= 25000) {
        creditScore += 75;
    } else if (customer.income >= 12000) {
        creditScore += 50;
    } else {
        creditScore += 25;
    }

    return creditScore;
}

// Function to print customer data
void printCustomerData(Customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Age: %d\n", customer.age);
    printf("Gender: %s\n", customer.gender);
    printf("Income: %.2f\n", customer.income);
    printf("Occupation: %s\n", customer.occupation);
    printf("Credit Score: %d\n", calculateCreditScore(customer));
}

int main() {
    // Define an array of customers
    Customer customers[100];

    // Open a file containing customer data
    FILE *file = fopen("customer_data.txt", "r");

    // Read customer data from the file
    readCustomerData(&customers[0], file);
    readCustomerData(&customers[1], file);
    readCustomerData(&customers[2], file);

    // Print customer data
    printCustomerData(customers[0]);
    printCustomerData(customers[1]);
    printCustomerData(customers[2]);

    // Close the file
    fclose(file);

    return 0;
}
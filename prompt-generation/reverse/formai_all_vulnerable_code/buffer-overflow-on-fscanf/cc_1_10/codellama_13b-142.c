//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: complete
// Data Mining Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for customer data
typedef struct {
  char name[50];
  int age;
  char gender;
  float income;
} Customer;

// Function to read customer data from file
void readCustomerData(char *filePath, Customer *customers, int numCustomers) {
  FILE *fp = fopen(filePath, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  for (int i = 0; i < numCustomers; i++) {
    fscanf(fp, "%s %d %c %f", customers[i].name, &customers[i].age, &customers[i].gender, &customers[i].income);
  }

  fclose(fp);
}

// Function to print customer data
void printCustomerData(Customer *customers, int numCustomers) {
  for (int i = 0; i < numCustomers; i++) {
    printf("%s, %d, %c, %f\n", customers[i].name, customers[i].age, customers[i].gender, customers[i].income);
  }
}

// Function to find the customer with the highest income
Customer findHighestIncome(Customer *customers, int numCustomers) {
  Customer highestIncomeCustomer = { "", 0, '\0', 0.0 };

  for (int i = 0; i < numCustomers; i++) {
    if (customers[i].income > highestIncomeCustomer.income) {
      highestIncomeCustomer = customers[i];
    }
  }

  return highestIncomeCustomer;
}

int main() {
  // Declare variables
  Customer customers[10];
  int numCustomers = 10;
  char filePath[] = "customers.txt";

  // Read customer data from file
  readCustomerData(filePath, customers, numCustomers);

  // Print customer data
  printCustomerData(customers, numCustomers);

  // Find the customer with the highest income
  Customer highestIncomeCustomer = findHighestIncome(customers, numCustomers);

  // Print the customer with the highest income
  printf("Customer with highest income: %s, %d, %c, %f\n", highestIncomeCustomer.name, highestIncomeCustomer.age, highestIncomeCustomer.gender, highestIncomeCustomer.income);

  return 0;
}
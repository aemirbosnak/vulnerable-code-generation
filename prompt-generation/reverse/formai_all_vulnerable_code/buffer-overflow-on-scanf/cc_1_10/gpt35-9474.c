//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for storing customer data */
typedef struct {
  int customerID;
  char name[30];
  char email[30];
  int age;
  float balance;
} Customer;

/* Function for querying the database for customers with a balance over a certain amount */
void getCustomersByBalance(float amount) {
  FILE *database;
  Customer customer;

  // Open the database file
  database = fopen("customer_database.dat", "rb");

  if (database == NULL) {
    printf("Error: Unable to open database.\n");
    exit(1);
  }

  // Loop through each customer in the database
  while(fread(&customer, sizeof(Customer), 1, database)) {
    if (customer.balance > amount) {
      printf("Customer ID: %d\n", customer.customerID);
      printf("Name: %s\n", customer.name);
      printf("Email: %s\n", customer.email);
      printf("Age: %d\n", customer.age);
      printf("Balance: $%.2f\n", customer.balance);
      printf("\n");
    }
  }

  // Close the database file
  fclose(database);
}

int main() {
  float balanceThreshold;

  printf("Please enter a balance threshold: ");
  scanf("%f", &balanceThreshold);

  printf("Finding all customers with a balance over $%.2f...\n\n", balanceThreshold);

  getCustomersByBalance(balanceThreshold);

  return 0;
}
//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a customer
struct Customer {
  int id;
  char name[50];
  char email[50];
  char address[100];
};

// Function to print a customer
void printCustomer(struct Customer c) {
  printf("Customer ID: %d\n", c.id);
  printf("Name: %s\n", c.name);
  printf("Email: %s\n", c.email);
  printf("Address: %s\n", c.address);
}

// Function to read a customer from a file
struct Customer readCustomer(FILE *f) {
  struct Customer c;
  fscanf(f, "%d %s %s %s", &c.id, c.name, c.email, c.address);
  return c;
}

// Function to write a customer to a file
void writeCustomer(struct Customer c, FILE *f) {
  fprintf(f, "%d %s %s %s\n", c.id, c.name, c.email, c.address);
}

int main() {
  // Create a file to store customers
  FILE *f = fopen("customers.txt", "w");
  if (f == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Create a customer
  struct Customer c1;
  c1.id = 1;
  strcpy(c1.name, "John Doe");
  strcpy(c1.email, "john.doe@example.com");
  strcpy(c1.address, "123 Main St");

  // Write the customer to the file
  writeCustomer(c1, f);

  // Close the file
  fclose(f);

  // Read the customer from the file
  f = fopen("customers.txt", "r");
  struct Customer c2 = readCustomer(f);

  // Print the customer
  printCustomer(c2);

  return 0;
}
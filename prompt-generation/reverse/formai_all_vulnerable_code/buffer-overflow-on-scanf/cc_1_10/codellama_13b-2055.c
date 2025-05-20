//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: dynamic
// Banking Record System Example Program

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Customer {
    char name[50];
    int age;
    char address[100];
    float balance;
  };

  int main() {
    struct Customer customers[100];
    int n = 0;

    // Get number of customers
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    // Get customer information
    for (int i = 0; i < n; i++) {
      printf("Enter customer %d's name: ", i + 1);
      scanf("%s", customers[i].name);
      printf("Enter customer %d's age: ", i + 1);
      scanf("%d", &customers[i].age);
      printf("Enter customer %d's address: ", i + 1);
      scanf("%s", customers[i].address);
      printf("Enter customer %d's balance: ", i + 1);
      scanf("%f", &customers[i].balance);
    }

    // Display customer information
    printf("Customer Information\n");
    for (int i = 0; i < n; i++) {
      printf("Name: %s\n", customers[i].name);
      printf("Age: %d\n", customers[i].age);
      printf("Address: %s\n", customers[i].address);
      printf("Balance: %.2f\n", customers[i].balance);
      printf("\n");
    }

    // Get customer ID
    int customerID;
    printf("Enter the customer ID: ");
    scanf("%d", &customerID);

    // Get customer information
    for (int i = 0; i < n; i++) {
      if (customers[i].name[0] == customerID) {
        printf("Name: %s\n", customers[i].name);
        printf("Age: %d\n", customers[i].age);
        printf("Address: %s\n", customers[i].address);
        printf("Balance: %.2f\n", customers[i].balance);
        break;
      }
    }

    // Get deposit amount
    float deposit;
    printf("Enter the deposit amount: ");
    scanf("%f", &deposit);

    // Update customer balance
    for (int i = 0; i < n; i++) {
      if (customers[i].name[0] == customerID) {
        customers[i].balance += deposit;
        break;
      }
    }

    // Display updated customer information
    printf("Updated Customer Information\n");
    for (int i = 0; i < n; i++) {
      if (customers[i].name[0] == customerID) {
        printf("Name: %s\n", customers[i].name);
        printf("Age: %d\n", customers[i].age);
        printf("Address: %s\n", customers[i].address);
        printf("Balance: %.2f\n", customers[i].balance);
        break;
      }
    }

    return 0;
  }
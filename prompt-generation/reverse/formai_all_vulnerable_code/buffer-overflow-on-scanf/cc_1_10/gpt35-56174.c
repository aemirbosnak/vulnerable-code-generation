//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
  char name[50];
  int account_num;
  double balance;
} customer;

int main() {
  customer customers[100];
  int num_customers = 0;

  printf("Welcome to the Banking Record System.\n");

  while (1) {
    printf("Please choose an option:\n");
    printf("1. Add customer\n");
    printf("2. View customer information\n");
    printf("3. Exit\n");

    int user_choice;
    scanf("%d", &user_choice);

    if (user_choice == 1) {
      if (num_customers < 100) {
        customer new_customer;

        printf("Enter customer name: ");
        scanf("%s", new_customer.name);

        printf("Enter account number: ");
        scanf("%d", &new_customer.account_num);

        printf("Enter initial balance: ");
        scanf("%lf", &new_customer.balance);

        customers[num_customers] = new_customer;
        num_customers++;

        printf("Customer added successfully.\n");
      } else {
        printf("Error: maximum number of customers reached.\n");
      }
    } else if (user_choice == 2) {
      int customer_found = 0;
      int search_account_num;

      printf("Enter account number: ");
      scanf("%d", &search_account_num);

      for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_num == search_account_num) {
          customer_found = 1;

          printf("Customer name: %s\n", customers[i].name);
          printf("Account number: %d\n", customers[i].account_num);
          printf("Balance: $%.2lf\n", customers[i].balance);
        }
      }

      if (!customer_found) {
        printf("Error: customer not found.\n");
      }
    } else if (user_choice == 3) {
      printf("Goodbye.\n");
      exit(0);
    } else {
      printf("Error: invalid input.\n");
    }
  }

  return 0;
}
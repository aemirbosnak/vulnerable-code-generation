//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

int num_customers = 0;

struct customer {
  char name[50];
  int account_number;
  float balance;
};

struct customer bank[MAX_CUSTOMERS];

void add_customer() {
  if (num_customers == MAX_CUSTOMERS) {
    printf("Error: Bank records full.\n");
    return;
  }

  struct customer new_cust;

  printf("Enter customer name: ");
  scanf("%s", new_cust.name);
  printf("Enter account number: ");
  scanf("%d", &new_cust.account_number);
  printf("Enter initial balance: ");
  scanf("%f", &new_cust.balance);

  bank[num_customers++] = new_cust;

  printf("Successfully added customer %s.\n", new_cust.name);
}

void print_customers() {
  if (num_customers == 0) {
    printf("No customers in bank records.\n");
    return;
  }

  printf("%-20s%-20s%-20s\n", "Customer Name", "Account Number", "Balance");

  for (int i=0; i<num_customers; i++) {
    struct customer cust = bank[i];
    printf("%-20s%-20d%-20.2f\n", cust.name, cust.account_number, cust.balance);
  }
}

void deposit() {
  int account;
  float amount;

  printf("Enter account number: ");
  scanf("%d", &account);

  for (int i=0; i<num_customers; i++) {
    struct customer cust = bank[i];
    if (cust.account_number == account) {
      printf("Enter amount to deposit: ");
      scanf("%f", &amount);

      cust.balance += amount;
      bank[i] = cust;

      printf("Successfully deposited %.2f into %s's account.\n", amount, cust.name);
      return;
    }
  }

  printf("Error: Customer not found.\n");
}

void withdraw() {
  int account;
  float amount;

  printf("Enter account number: ");
  scanf("%d", &account);

  for (int i=0; i<num_customers; i++) {
    struct customer cust = bank[i];
    if (cust.account_number == account) {
      printf("Enter amount to withdraw: ");
      scanf("%f", &amount);

      if (amount > cust.balance) {
        printf("Error: Insufficient funds.\n");
        return;
      }

      cust.balance -= amount;
      bank[i] = cust;

      printf("Successfully withdrew %.2f from %s's account.\n", amount, cust.name);
      return;
    }
  }

  printf("Error: Customer not found.\n");
}

int main() {
  int choice;

  do {
    printf("\n");
    printf("1. Add customer\n");
    printf("2. Print customers\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_customer();
        break;
      case 2:
        print_customers();
        break;
      case 3:
        deposit();
        break;
      case 4:
        withdraw();
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 5);

  return 0;
}
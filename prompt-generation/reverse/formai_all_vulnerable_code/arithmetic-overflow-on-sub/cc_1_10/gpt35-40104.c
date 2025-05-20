//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
  char name[100];
  int account_number;
  float balance;
};

void deposit(struct bank_record *customer) {
  float amount;
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  customer->balance += amount;
  printf("New balance is: %.2f\n", customer->balance);
}

void withdraw(struct bank_record *customer) {
  float amount;
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  if(amount > customer->balance) {
    printf("Insufficient funds.\n");
  } else {
    customer->balance -= amount;
    printf("New balance is: %.2f\n", customer->balance);
  }
}

void display(struct bank_record customer) {
  printf("Name: %s\n", customer.name);
  printf("Account number: %d\n", customer.account_number);
  printf("Balance: %.2f\n", customer.balance);
}

int main() {
  int num_customers;
  struct bank_record *customers;

  printf("Enter number of customers: ");
  scanf("%d", &num_customers);

  customers = malloc(num_customers * sizeof(struct bank_record));

  for(int i = 0; i < num_customers; i++) {
    printf("Enter name for customer %d: ", i+1);
    scanf("%s", customers[i].name);

    printf("Enter account number for customer %d: ", i+1);
    scanf("%d", &customers[i].account_number);

    printf("Enter starting balance for customer %d: ", i+1);
    scanf("%f", &customers[i].balance);
  }

  int choice;
  int customer_num;
  while(1) {
    printf("\nChoose an action:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2 || choice == 3) {
      printf("\nEnter customer number: ");
      scanf("%d", &customer_num);
      customer_num -= 1; // 0 index

      if(customer_num >= num_customers || customer_num < 0) {
        printf("Invalid customer number\n");
        continue;
      }
    }

    switch(choice) {
      case 1:
        deposit(&customers[customer_num]);
        break;
      case 2:
        withdraw(&customers[customer_num]);
        break;
      case 3:
        display(customers[customer_num]);
        break;
      case 4:
        printf("Exiting...\n");
        free(customers);
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
}
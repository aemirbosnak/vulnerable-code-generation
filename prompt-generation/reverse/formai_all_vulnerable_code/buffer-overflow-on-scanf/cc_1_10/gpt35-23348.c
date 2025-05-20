//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold customer information
struct customer {
  int account_number;
  char first_name[50];
  char last_name[50];
  float balance;
};

// function to add a new customer record
void add_customer(struct customer *customers, int num_customers) {
  int account_number;
  char first_name[50];
  char last_name[50];
  float balance;
  
  // get new customer details from user
  printf("\nEnter account number: ");
  scanf("%d", &account_number);
  printf("Enter first name: ");
  scanf("%s", first_name);
  printf("Enter last name: ");
  scanf("%s", last_name);
  printf("Enter starting balance: ");
  scanf("%f", &balance);
  
  // add new customer to array of customers
  struct customer new_customer;
  new_customer.account_number = account_number;
  strcpy(new_customer.first_name, first_name);
  strcpy(new_customer.last_name, last_name);
  new_customer.balance = balance;
  
  customers[num_customers] = new_customer;
  
  printf("\nNew customer added successfully!\n");
}

// function to search for a customer by account number
void search_customer(struct customer *customers, int num_customers) {
  int account_number;
  printf("\nEnter account number: ");
  scanf("%d", &account_number);

  for(int i=0; i<num_customers; i++) {
    if(customers[i].account_number == account_number) {
        printf("\nCustomer found!\n");
        printf("First name: %s\n", customers[i].first_name);
        printf("Last name: %s\n", customers[i].last_name);
        printf("Balance: %.2f\n", customers[i].balance);
        return;
    }
  }

  printf("\nCustomer not found.\n");
}

// function to display all customer records
void display_customers(struct customer *customers, int num_customers) {
  printf("\n");
  printf("All customers:\n");
  for(int i=0; i<num_customers; i++) {
    printf("Account number: %d\n", customers[i].account_number);
    printf("First name: %s\n", customers[i].first_name);
    printf("Last name: %s\n", customers[i].last_name);
    printf("Balance: %.2f\n", customers[i].balance);
    printf("\n");
  }
}

int main() {
  int num_customers = 0;
  struct customer *customers = malloc(num_customers * sizeof(struct customer));

  int option;
  do {
    printf("\nBanking Record System\n");
    printf("1. Add new customer\n");
    printf("2. Search for customer\n");
    printf("3. Display all customers\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
      case 1: add_customer(customers, num_customers); num_customers++; break;
      case 2: search_customer(customers, num_customers); break;
      case 3: display_customers(customers, num_customers); break;
      case 4: break;
      default: printf("\nInvalid option!\n"); break;
    }
  } while(option != 4);
  
  free(customers);
  
  printf("\nProgram terminated.\n");

  return 0;
}
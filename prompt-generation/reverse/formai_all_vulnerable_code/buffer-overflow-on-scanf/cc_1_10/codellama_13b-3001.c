//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
// Billing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for item
struct item {
  char name[50];
  int price;
};

// Define struct for customer
struct customer {
  char name[50];
  char phone[20];
  char email[50];
};

// Define struct for bill
struct bill {
  char customer_name[50];
  char customer_phone[20];
  char customer_email[50];
  int item_count;
  struct item items[10];
  int total_price;
};

// Function to print bill
void print_bill(struct bill bill) {
  printf("Customer Name: %s\n", bill.customer_name);
  printf("Customer Phone: %s\n", bill.customer_phone);
  printf("Customer Email: %s\n", bill.customer_email);
  printf("Item Count: %d\n", bill.item_count);
  printf("Items: \n");
  for (int i = 0; i < bill.item_count; i++) {
    printf("  %s: %d\n", bill.items[i].name, bill.items[i].price);
  }
  printf("Total Price: %d\n", bill.total_price);
}

// Main function
int main() {
  // Initialize variables
  struct customer customer;
  struct bill bill;
  int item_count = 0;
  int total_price = 0;

  // Get customer information
  printf("Enter customer name: ");
  scanf("%s", customer.name);
  printf("Enter customer phone: ");
  scanf("%s", customer.phone);
  printf("Enter customer email: ");
  scanf("%s", customer.email);

  // Get item information
  while (1) {
    printf("Enter item name (blank to stop): ");
    scanf("%s", bill.items[item_count].name);
    if (strlen(bill.items[item_count].name) == 0) {
      break;
    }
    printf("Enter item price: ");
    scanf("%d", &bill.items[item_count].price);
    total_price += bill.items[item_count].price;
    item_count++;
  }

  // Set bill information
  strcpy(bill.customer_name, customer.name);
  strcpy(bill.customer_phone, customer.phone);
  strcpy(bill.customer_email, customer.email);
  bill.item_count = item_count;
  bill.total_price = total_price;

  // Print bill
  print_bill(bill);

  return 0;
}
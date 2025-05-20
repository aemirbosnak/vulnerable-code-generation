//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a customer
typedef struct {
  char name[50];
  char address[100];
  char phone_number[20];
  char email[50];
  int items[5];
  int item_count;
} Customer;

// Define the struct for a menu item
typedef struct {
  char name[50];
  int price;
} MenuItem;

// Define the struct for a billing item
typedef struct {
  char name[50];
  int quantity;
  int price;
} BillingItem;

// Function to get customer information
void get_customer_info(Customer *customer) {
  printf("Enter your name: ");
  scanf("%s", customer->name);
  printf("Enter your address: ");
  scanf("%s", customer->address);
  printf("Enter your phone number: ");
  scanf("%s", customer->phone_number);
  printf("Enter your email: ");
  scanf("%s", customer->email);
}

// Function to get menu items
void get_menu_items(MenuItem menu_items[], int *menu_item_count) {
  printf("Enter the number of menu items: ");
  scanf("%d", menu_item_count);
  for (int i = 0; i < *menu_item_count; i++) {
    printf("Enter the name of menu item %d: ", i + 1);
    scanf("%s", menu_items[i].name);
    printf("Enter the price of menu item %d: ", i + 1);
    scanf("%d", &menu_items[i].price);
  }
}

// Function to get billing items
void get_billing_items(Customer *customer, MenuItem menu_items[], int menu_item_count, BillingItem billing_items[]) {
  printf("Enter the number of billing items: ");
  int billing_item_count;
  scanf("%d", &billing_item_count);
  for (int i = 0; i < billing_item_count; i++) {
    printf("Enter the name of billing item %d: ", i + 1);
    scanf("%s", billing_items[i].name);
    printf("Enter the quantity of billing item %d: ", i + 1);
    scanf("%d", &billing_items[i].quantity);
    billing_items[i].price = 0;
    for (int j = 0; j < menu_item_count; j++) {
      if (strcmp(billing_items[i].name, menu_items[j].name) == 0) {
        billing_items[i].price = menu_items[j].price * billing_items[i].quantity;
        break;
      }
    }
  }
}

// Function to calculate total cost
void calculate_total_cost(BillingItem billing_items[], int billing_item_count, int *total_cost) {
  *total_cost = 0;
  for (int i = 0; i < billing_item_count; i++) {
    *total_cost += billing_items[i].price;
  }
}

// Function to display bill
void display_bill(Customer *customer, BillingItem billing_items[], int billing_item_count, int total_cost) {
  printf("Customer Information:\n");
  printf("Name: %s\n", customer->name);
  printf("Address: %s\n", customer->address);
  printf("Phone Number: %s\n", customer->phone_number);
  printf("Email: %s\n", customer->email);
  printf("Billing Items:\n");
  for (int i = 0; i < billing_item_count; i++) {
    printf("%s: %d x %d = %d\n", billing_items[i].name, billing_items[i].quantity, billing_items[i].price, billing_items[i].price * billing_items[i].quantity);
  }
  printf("Total Cost: %d\n", total_cost);
}

int main() {
  // Create a customer struct
  Customer customer;
  // Get customer information
  get_customer_info(&customer);
  // Create an array of menu items
  MenuItem menu_items[5];
  int menu_item_count;
  // Get menu items
  get_menu_items(menu_items, &menu_item_count);
  // Create an array of billing items
  BillingItem billing_items[5];
  // Get billing items
  get_billing_items(&customer, menu_items, menu_item_count, billing_items);
  // Calculate total cost
  int total_cost;
  calculate_total_cost(billing_items, menu_item_count, &total_cost);
  // Display bill
  display_bill(&customer, billing_items, menu_item_count, total_cost);
  return 0;
}
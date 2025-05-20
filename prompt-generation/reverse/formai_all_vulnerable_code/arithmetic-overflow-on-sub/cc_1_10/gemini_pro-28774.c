//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
typedef struct MenuItem {
  char name[50];
  float price;
} MenuItem;

// Define the order item
typedef struct OrderItem {
  MenuItem item;
  int quantity;
} OrderItem;

// Define the order
typedef struct Order {
  OrderItem items[100];
  int num_items;
  float total_price;
} Order;

// Define the customer
typedef struct Customer {
  char name[50];
  char address[100];
  char phone[15];
} Customer;

// Function to print the menu
void print_menu(MenuItem menu[], int num_items) {
  printf("Welcome to the Cafe! Here is our exciting menu:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
  }
}

// Function to take the order
Order take_order(MenuItem menu[], int num_items) {
  Order order;
  order.num_items = 0;
  order.total_price = 0.0;

  int choice;
  int quantity;
  do {
    printf("Enter the number of the item you want to order (-1 to finish): ");
    scanf("%d", &choice);

    if (choice != -1) {
      printf("Enter the quantity: ");
      scanf("%d", &quantity);

      OrderItem item;
      item.item = menu[choice - 1];
      item.quantity = quantity;

      order.items[order.num_items] = item;
      order.num_items++;
      order.total_price += item.item.price * item.quantity;
    }
  } while (choice != -1);

  return order;
}

// Function to get the customer information
Customer get_customer_info() {
  Customer customer;

  printf("Please enter your name: ");
  scanf("%s", customer.name);

  printf("Please enter your address: ");
  scanf("%s", customer.address);

  printf("Please enter your phone number: ");
  scanf("%s", customer.phone);

  return customer;
}

// Function to print the receipt
void print_receipt(Order order, Customer customer) {
  printf("\nThank you for your order, %s!\n", customer.name);
  printf("Your order summary:\n");

  for (int i = 0; i < order.num_items; i++) {
    printf("%d. %s x %d - $%.2f\n", i + 1, order.items[i].item.name, order.items[i].quantity,
           order.items[i].item.price * order.items[i].quantity);
  }

  printf("Total: $%.2f\n", order.total_price);
}

// Main function
int main() {
  // Define the menu items
  MenuItem menu[] = {
      {"Coffee", 2.50},
      {"Tea", 2.00},
      {"Espresso", 3.00},
      {"Cappuccino", 3.50},
      {"Latte", 4.00},
      {"Mocha", 4.50},
      {"Muffin", 2.00},
      {"Croissant", 2.50},
      {"Bagel", 3.00},
      {"Sandwich", 4.00},
      {"Salad", 5.00},
      {"Soup", 4.50}};

  int num_items = sizeof(menu) / sizeof(menu[0]);

  // Print the menu
  print_menu(menu, num_items);

  // Take the order
  Order order = take_order(menu, num_items);

  // Get the customer information
  Customer customer = get_customer_info();

  // Print the receipt
  print_receipt(order, customer);

  return 0;
}
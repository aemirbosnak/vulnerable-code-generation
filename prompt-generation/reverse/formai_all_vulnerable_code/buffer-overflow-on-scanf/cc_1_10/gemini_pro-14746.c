//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the order
#define MAX_ITEMS 10

// Define the structure of an item in the order
typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

// Define the structure of the order
typedef struct {
  char customer_name[50];
  char customer_address[100];
  char customer_phone[20];
  Item items[MAX_ITEMS];
  int num_items;
  float total_price;
} Order;

// Function to print the menu
void print_menu() {
  printf("Menu:\n");
  printf("1. Coffee (Rs. 10)\n");
  printf("2. Tea (Rs. 15)\n");
  printf("3. Cold Coffee (Rs. 20)\n");
  printf("4. Hot Chocolate (Rs. 25)\n");
  printf("5. Cappuccino (Rs. 30)\n");
}

// Function to get the order from the customer
Order get_order() {
  Order order;

  // Get the customer's name, address, and phone number
  printf("Enter your name: ");
  scanf("%s", order.customer_name);
  printf("Enter your address: ");
  scanf("%s", order.customer_address);
  printf("Enter your phone number: ");
  scanf("%s", order.customer_phone);

  // Get the number of items in the order
  printf("How many items would you like to order? ");
  scanf("%d", &order.num_items);

  // Get the details of each item in the order
  for (int i = 0; i < order.num_items; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", order.items[i].name);
    printf("Enter the quantity of item %d: ", i + 1);
    scanf("%d", &order.items[i].quantity);
    printf("Enter the price of item %d: ", i + 1);
    scanf("%f", &order.items[i].price);
  }

  // Calculate the total price of the order
  order.total_price = 0;
  for (int i = 0; i < order.num_items; i++) {
    order.total_price += order.items[i].quantity * order.items[i].price;
  }

  return order;
}

// Function to print the order
void print_order(Order order) {
  printf("Customer Name: %s\n", order.customer_name);
  printf("Customer Address: %s\n", order.customer_address);
  printf("Customer Phone: %s\n", order.customer_phone);
  printf("\n");
  printf("Items:\n");
  for (int i = 0; i < order.num_items; i++) {
    printf("%s x %d = Rs. %.2f\n", order.items[i].name, order.items[i].quantity, order.items[i].quantity * order.items[i].price);
  }
  printf("\n");
  printf("Total Price: Rs. %.2f\n", order.total_price);
}

// Main function
int main() {
  // Print the menu
  print_menu();

  // Get the order from the customer
  Order order = get_order();

  // Print the order
  print_order(order);

  return 0;
}
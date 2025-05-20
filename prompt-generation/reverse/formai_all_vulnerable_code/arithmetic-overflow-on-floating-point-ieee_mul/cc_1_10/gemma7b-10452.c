//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 10

typedef struct Order {
  char customer_name[20];
  char item_name[20];
  int quantity;
  float price;
} Order;

Order orders[MAX_ORDERS];

void calculate_total(int num_orders) {
  float total = 0.0f;
  for (int i = 0; i < num_orders; i++) {
    Order order = orders[i];
    total += order.quantity * order.price;
  }
  printf("Total: $%.2f\n", total);
}

void print_menu() {
  printf("Menu:\n");
  for (int i = 0; i < MAX_ORDERS; i++) {
    Order order = orders[i];
    printf("%s - %s (%d) - $%.2f\n", order.customer_name, order.item_name, order.quantity, order.price);
  }
}

int main() {
  int num_orders = 0;

  // Create a loop to handle customer orders
  while (1) {
    // Get the customer's name, item name, quantity, and price
    char customer_name[20];
    printf("Enter your name: ");
    scanf("%s", customer_name);

    char item_name[20];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    float price;
    printf("Enter the price: ");
    scanf("%f", &price);

    // Create a new order
    Order new_order;
    strcpy(new_order.customer_name, customer_name);
    strcpy(new_order.item_name, item_name);
    new_order.quantity = quantity;
    new_order.price = price;

    // Add the new order to the array
    orders[num_orders++] = new_order;

    // Check if the customer wants to continue ordering
    char continue_ordering;
    printf("Do you want to continue ordering? (Y/N): ");
    scanf("%c", &continue_ordering);

    // If the customer does not want to continue ordering, break out of the loop
    if (continue_ordering == 'N') {
      break;
    }
  }

  // Calculate the total cost of the orders
  calculate_total(num_orders);

  // Print the menu
  print_menu();

  return 0;
}
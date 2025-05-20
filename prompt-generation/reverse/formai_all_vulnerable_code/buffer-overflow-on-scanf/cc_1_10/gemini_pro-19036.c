//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
  char *name;
  float price;
};

struct MenuItem menuItems[] = {
  {"Coffee", 2.50},
  {"Tea", 2.00},
  {"Soda", 1.50},
  {"Juice", 2.00},
  {"Water", 1.00},
  {"Muffin", 3.00},
  {"Cookie", 2.00},
  {"Brownie", 2.50},
  {"Scone", 2.50},
  {"Bagel", 3.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of a customer order
struct CustomerOrder {
  struct MenuItem *items[MAX_ITEMS];
  int numItems;
  float total;
};

// Get the customer's order
void getOrder(struct CustomerOrder *order) {
  int i;
  char input[100];

  // Get the number of items ordered
  printf("How many items would you like to order? ");
  scanf("%d", &order->numItems);

  // Get the items ordered
  for (i = 0; i < order->numItems; i++) {
    printf("What would you like to order? ");
    scanf("%s", input);

    // Find the item in the menu
    for (int j = 0; j < sizeof(menuItems) / sizeof(struct MenuItem); j++) {
      if (strcmp(input, menuItems[j].name) == 0) {
        order->items[i] = &menuItems[j];
        break;
      }
    }

    // If the item was not found, print an error message
    if (order->items[i] == NULL) {
      printf("Sorry, that item is not on the menu.\n");
      i--;
    }
  }

  // Calculate the total price of the order
  order->total = 0;
  for (i = 0; i < order->numItems; i++) {
    order->total += order->items[i]->price;
  }
}

// Print the customer's order
void printOrder(struct CustomerOrder *order) {
  int i;

  printf("Your order:\n");
  for (i = 0; i < order->numItems; i++) {
    printf("%s: %.2f\n", order->items[i]->name, order->items[i]->price);
  }

  printf("Total: %.2f\n", order->total);
}

// Get the payment from the customer
void getPayment(struct CustomerOrder *order) {
  float payment;

  printf("How much would you like to pay? ");
  scanf("%f", &payment);

  // If the payment is less than the total, print an error message
  if (payment < order->total) {
    printf("Sorry, your payment is not enough.\n");
    getPayment(order);
  }

  // Otherwise, print the change due
  else {
    printf("Your change is: %.2f\n", payment - order->total);
  }
}

// Main function
int main() {
  struct CustomerOrder order;

  // Get the customer's order
  getOrder(&order);

  // Print the customer's order
  printOrder(&order);

  // Get the payment from the customer
  getPayment(&order);

  return 0;
}
//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>

#define MAX_ITEMS 100 // maximum number of items on the menu
#define MAX_NAME_LENGTH 50 // maximum name length of an item
#define MAX_ORDER_SIZE 10 // maximum number of items a customer can order
#define TAX 0.05 // 5% tax rate

struct MenuItem {
  char name[MAX_NAME_LENGTH];
  float price;
};

struct Order {
  int itemNumber;
  int quantity;
};

struct Customer {
  char name[MAX_NAME_LENGTH];
  struct Order orders[MAX_ORDER_SIZE];
};

float calculateTotal(struct Customer customer);

struct MenuItem menu[MAX_ITEMS] = {
  {"Hamburger", 3.99},
  {"Cheeseburger", 4.49},
  {"French Fries", 2.49},
  {"Onion Rings", 2.99},
  {"Soft Drink", 1.49}
};

int main() {
  int numCustomers;
  printf("How many customers do you have? ");
  scanf("%d", &numCustomers);

  struct Customer customers[numCustomers];

  // iterate over each customer
  for (int i = 0; i < numCustomers; i++) {
    printf("\nCustomer %d\n", i + 1);

    // get customer name
    printf("Name: ");
    scanf("%s", customers[i].name);

    // get customer orders
    int numOrders;
    printf("How many items would you like to order (max %d)? ", MAX_ORDER_SIZE);
    scanf("%d", &numOrders);

    for (int j = 0; j < numOrders; j++) {
      int itemNumber;
      printf("Enter item number for order %d: ", j + 1);
      scanf("%d", &itemNumber);

      if (itemNumber < 1 || itemNumber > MAX_ITEMS) {
        printf("Invalid item number. Try again.\n");
        j--; // redo this order
        continue;
      }

      int quantity;
      printf("Enter quantity for order %d: ", j + 1);
      scanf("%d", &quantity);

      if (quantity < 1) {
        printf("Quantity must be at least 1. Try again.\n");
        j--; // redo this order
        continue;
      }

      struct Order order = { itemNumber, quantity };
      customers[i].orders[j] = order;
    }
  }

  // print the bill for each customer
  for (int i = 0; i < numCustomers; i++) {
    printf("\n\nCustomer %d - %s - Bill\n\n", i + 1, customers[i].name);

    printf("Item\t\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");

    float subtotal = 0;
    for (int j = 0; j < MAX_ORDER_SIZE; j++) {
      // check if the order has been made
      if (customers[i].orders[j].itemNumber == 0) {
        break;
      }

      int itemNumber = customers[i].orders[j].itemNumber;
      int quantity = customers[i].orders[j].quantity;
      struct MenuItem item = menu[itemNumber - 1]; // 0-indexed array

      float total = quantity * item.price;
      subtotal += total;

      printf("%s\t\t%d\t\t$%.2f\t\t$%.2f\n", item.name, quantity, item.price, total);
    }

    float taxAmount = subtotal * TAX;
    float total = subtotal + taxAmount;

    printf("-------------------------------------------------------\n");
    printf("\t\tSubtotal\t$%.2f\n", subtotal);
    printf("\t\tTax (5%%)\t$%.2f\n", taxAmount);
    printf("\t\tTotal\t\t$%.2f\n", total);
  }

  return 0;
}
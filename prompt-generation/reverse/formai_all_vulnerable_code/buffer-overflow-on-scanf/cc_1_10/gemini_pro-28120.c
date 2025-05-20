//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int quantity;
  double price;
} Item;

typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Order;

void printMenu() {
  printf("Welcome to the Cafe!\n");
  printf("---------------------\n");
  printf("1. Add item to order\n");
  printf("2. Remove item from order\n");
  printf("3. Print order\n");
  printf("4. Checkout\n");
  printf("5. Quit\n");
}

void addItem(Order *order) {
  char name[MAX_NAME_LEN];
  int quantity;
  double price;

  printf("Enter item name: ");
  scanf(" %s", name);

  printf("Enter quantity: ");
  scanf(" %d", &quantity);

  printf("Enter price: ");
  scanf(" %lf", &price);

  Item item = {name, quantity, price};
  order->items[order->num_items++] = item;
}

void removeItem(Order *order) {
  char name[MAX_NAME_LEN];
  int i;

  printf("Enter item name to remove: ");
  scanf(" %s", name);

  for (i = 0; i < order->num_items; i++) {
    if (strcmp(name, order->items[i].name) == 0) {
      order->items[i] = order->items[order->num_items - 1];
      order->num_items--;
      break;
    }
  }
}

void printOrder(Order *order) {
  int i;
  double total = 0;

  printf("Order:\n");
  printf("---------------------\n");
  for (i = 0; i < order->num_items; i++) {
    printf("%s x%d @ $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    total += order->items[i].quantity * order->items[i].price;
  }
  printf("---------------------\n");
  printf("Total: $%.2f\n", total);
}

void checkout(Order *order) {
  double total = 0;
  int i;

  for (i = 0; i < order->num_items; i++) {
    total += order->items[i].quantity * order->items[i].price;
  }

  printf("Your total is $%.2f.\n", total);
  printf("Please pay now.\n");
}

int main() {
  Order order;
  order.num_items = 0;

  int choice;

  while (1) {
    printMenu();
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    switch (choice) {
      case 1:
        addItem(&order);
        break;
      case 2:
        removeItem(&order);
        break;
      case 3:
        printOrder(&order);
        break;
      case 4:
        checkout(&order);
        return 0;
      case 5:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
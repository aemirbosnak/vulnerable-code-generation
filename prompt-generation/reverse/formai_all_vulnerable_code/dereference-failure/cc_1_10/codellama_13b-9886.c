//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
// Cafe Billing System

#include <stdio.h>
#include <stdlib.h>

struct item {
  char name[50];
  double price;
  int quantity;
};

struct order {
  struct item items[50];
  int total_items;
  double total_cost;
};

void display_menu(struct item menu[]) {
  printf("Welcome to our cafe!\n");
  printf("Our menu items:\n");
  for (int i = 0; i < 50; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
  }
  printf("\n");
}

void display_order(struct order order) {
  printf("Your order:\n");
  for (int i = 0; i < order.total_items; i++) {
    printf("%d. %s - $%.2f\n", i + 1, order.items[i].name, order.items[i].price);
  }
  printf("Total cost: $%.2f\n", order.total_cost);
}

void add_item_to_order(struct order *order, struct item item) {
  order->items[order->total_items] = item;
  order->total_items++;
  order->total_cost += item.price;
}

int main() {
  struct item menu[] = {
    {"Coffee", 3.0, 0},
    {"Tea", 2.5, 0},
    {"Soda", 3.5, 0},
    {"Cappuccino", 4.0, 0},
    {"Espresso", 3.5, 0},
    {"Lemonade", 3.0, 0},
    {"Croissant", 2.0, 0},
    {"Muffin", 1.5, 0},
    {"Donut", 1.0, 0},
  };

  struct order order = {0};

  display_menu(menu);

  int selection;
  while (1) {
    printf("Select an item (0 to quit): ");
    scanf("%d", &selection);
    if (selection == 0) {
      break;
    }
    add_item_to_order(&order, menu[selection - 1]);
  }

  display_order(order);

  return 0;
}
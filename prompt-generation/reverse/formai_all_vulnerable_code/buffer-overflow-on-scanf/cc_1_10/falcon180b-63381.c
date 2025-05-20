//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct item {
  char name[50];
  float price;
};

struct customer {
  char name[50];
  int table;
};

struct order {
  int item_count;
  struct item *items;
  struct customer *customer;
};

void add_item(struct item *items, int *item_count) {
  printf("Enter item name: ");
  scanf("%s", items[*item_count].name);
  printf("Enter item price: ");
  scanf("%f", &items[*item_count].price);
  (*item_count)++;
}

void display_items(struct item items[], int item_count) {
  printf("Items:\n");
  for (int i = 0; i < item_count; i++) {
    printf("%s - $%.2f\n", items[i].name, items[i].price);
  }
}

void add_customer(struct customer *customers, int *customer_count) {
  printf("Enter customer name: ");
  scanf("%s", customers[*customer_count].name);
  (*customer_count)++;
}

void display_customers(struct customer customers[], int customer_count) {
  printf("Customers:\n");
  for (int i = 0; i < customer_count; i++) {
    printf("%s\n", customers[i].name);
  }
}

void take_order(struct order *order) {
  int item_count = 0;
  add_item(order->items, &item_count);
  printf("Customer name: ");
  scanf("%s", order->customer->name);
  printf("Table number: ");
  scanf("%d", &order->customer->table);
}

void display_order(struct order order) {
  printf("Order for %s at table %d:\n", order.customer->name, order.customer->table);
  display_items(order.items, order.item_count);
  printf("Total: $%.2f\n", order.items[0].price * order.item_count);
}

int main() {
  struct item items[100];
  int item_count = 0;
  add_item(items, &item_count);
  add_item(items, &item_count);

  struct customer customers[100];
  int customer_count = 0;
  add_customer(customers, &customer_count);
  add_customer(customers, &customer_count);

  struct order order;
  take_order(&order);

  display_items(items, item_count);
  display_customers(customers, customer_count);

  display_order(order);

  return 0;
}
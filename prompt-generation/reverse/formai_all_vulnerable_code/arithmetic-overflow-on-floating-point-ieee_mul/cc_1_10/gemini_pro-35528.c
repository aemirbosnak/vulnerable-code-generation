//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int quantity;
  float price;
} Item;

typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
  float total_price;
} Bill;

void add_item_to_bill(Bill *bill, Item item) {
  bill->items[bill->num_items] = item;
  bill->num_items++;
  bill->total_price += item.quantity * item.price;
}

void print_bill(Bill bill) {
  printf("Cafe Billing System\n");
  printf("===================\n");
  for (int i = 0; i < bill.num_items; i++) {
    printf("%s x %d @ %.2f = %.2f\n", bill.items[i].name, bill.items[i].quantity, bill.items[i].price, bill.items[i].quantity * bill.items[i].price);
  }
  printf("Total: %.2f\n", bill.total_price);
}

int main() {
  Bill bill;
  bill.num_items = 0;
  bill.total_price = 0.0;

  Item item1;
  strcpy(item1.name, "Coffee");
  item1.quantity = 2;
  item1.price = 2.50;
  add_item_to_bill(&bill, item1);

  Item item2;
  strcpy(item2.name, "Tea");
  item2.quantity = 1;
  item2.price = 1.50;
  add_item_to_bill(&bill, item2);

  Item item3;
  strcpy(item3.name, "Cake");
  item3.quantity = 1;
  item3.price = 3.00;
  add_item_to_bill(&bill, item3);

  print_bill(bill);

  return 0;
}
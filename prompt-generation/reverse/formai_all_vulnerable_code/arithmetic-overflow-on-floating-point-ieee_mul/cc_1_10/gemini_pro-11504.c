//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>

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

void add_item(Bill *bill, Item item) {
  bill->items[bill->num_items] = item;
  bill->num_items++;
  bill->total_price += item.quantity * item.price;
}

void print_bill(Bill bill) {
  printf("Cafe Billing System\n");
  printf("===================\n");
  printf("Items:\n");
  for (int i = 0; i < bill.num_items; i++) {
    printf("  %s x %d @ $%.2f = $%.2f\n", bill.items[i].name, bill.items[i].quantity, bill.items[i].price, bill.items[i].quantity * bill.items[i].price);
  }
  printf("Total: $%.2f\n", bill.total_price);
}

int main() {
  Bill bill;
  bill.num_items = 0;
  bill.total_price = 0.0;

  // Add some items to the bill
  Item item1 = {"Coffee", 2, 2.50};
  add_item(&bill, item1);
  Item item2 = {"Tea", 1, 1.50};
  add_item(&bill, item2);
  Item item3 = {"Pastry", 3, 1.00};
  add_item(&bill, item3);

  // Print the bill
  print_bill(bill);

  return 0;
}
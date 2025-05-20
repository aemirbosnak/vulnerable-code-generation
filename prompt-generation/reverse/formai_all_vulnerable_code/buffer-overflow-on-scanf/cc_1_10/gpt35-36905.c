//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define TAXRATE 0.06

struct Item {
  char name[50];
  float price;
};

struct Order {
  struct Item items[50];
  int num_items;
};

float calc_subtotal(struct Order order) {
  float subtotal = 0;
  for (int i = 0; i < order.num_items; i++) {
    subtotal += order.items[i].price;
  }
  return subtotal;
}

float calc_tax(float subtotal) {
  return subtotal * TAXRATE;
}

float calc_total(float subtotal, float tax) {
  return subtotal + tax;
}

void print_order(struct Order order, float subtotal, float tax, float total) {
  printf("\n\n---ORDER---\n");
  for (int i = 0; i < order.num_items; i++) {
    printf("%s\t%.2f\n", order.items[i].name, order.items[i].price);
  }
  printf("\nSUBTOTAL:\t%.2f\nTAX:\t\t%.2f\nTOTAL:\t\t%.2f\n", subtotal, tax, total);
}

int main() {
  struct Item menu[5] = { {"Coffee", 1.99}, {"Tea", 1.50}, {"Muffin", 2.25}, {"Bagel", 2.50}, {"Croissant", 2.75} };
  printf("---MENU---\n");
  for (int i = 0; i < 5; i++) {
    printf("%s\t%.2f\n", menu[i].name, menu[i].price);
  }
  struct Order order;
  order.num_items = 0;
  char choice;
  do {
    printf("Enter the item number to add to the order: ");
    int item_num;
    scanf("%d", &item_num);
    if (item_num >= 1 && item_num <= 5) {
      order.items[order.num_items] = menu[item_num - 1];
      order.num_items++;
      printf("Added %s to the order.\n", menu[item_num - 1].name);
    } else {
      printf("Invalid item number.\n");
    }
    printf("Add another item? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y');

  float subtotal = calc_subtotal(order);
  float tax = calc_tax(subtotal);
  float total = calc_total(subtotal, tax);

  print_order(order, subtotal, tax, total);

  return 0;
}
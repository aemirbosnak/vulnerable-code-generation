//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
  char name[50];
  float price;
  int quantity;
} item;

void print_menu() {
  printf("Welcome to the Cafe Billing System!\n");
  printf("-----------------------------------\n");
  printf("Items:\n");
  printf("1. Coffee - $2.50\n");
  printf("2. Tea - $1.50\n");
  printf("3. Sandwich - $5.00\n");
  printf("4. Salad - $4.00\n");
  printf("5. Pastry - $2.00\n");
  printf("-----------------------------------\n");
}

void get_order(item *order, int *num_items) {
  printf("Enter the number of items you want to order: ");
  scanf("%d", num_items);
  for (int i = 0; i < *num_items; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", order[i].name);
    printf("Enter the price of item %d: ", i + 1);
    scanf("%f", &order[i].price);
    printf("Enter the quantity of item %d: ", i + 1);
    scanf("%d", &order[i].quantity);
  }
}

float calculate_total(item *order, int num_items) {
  float total = 0;
  for (int i = 0; i < num_items; i++) {
    total += order[i].price * order[i].quantity;
  }
  return total;
}

void print_receipt(item *order, int num_items, float total) {
  printf("-----------------------------------\n");
  printf("Receipt:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s - $%.2f x %d = $%.2f\n", order[i].name, order[i].price, order[i].quantity, order[i].price * order[i].quantity);
  }
  printf("-----------------------------------\n");
  printf("Total: $%.2f\n", total);
}

int main() {
  item order[100];
  int num_items;
  float total;

  print_menu();
  get_order(order, &num_items);
  total = calculate_total(order, num_items);
  print_receipt(order, num_items, total);

  return 0;
}
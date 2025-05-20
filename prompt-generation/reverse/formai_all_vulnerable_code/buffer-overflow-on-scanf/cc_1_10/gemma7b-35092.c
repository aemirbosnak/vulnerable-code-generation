//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  float price;
  int quantity;
} Item;

Item items[MAX_ITEMS] = {
  {"Coffee", 2.50, 10},
  {"Tea", 3.00, 5},
  {"Juice", 2.00, 7},
  {"Smoothie", 4.00, 3},
  {"Water", 1.50, 8},
  {"Soda", 2.20, 6},
  {"Juice", 2.00, 2},
  {"Energy Drink", 3.50, 4},
  {"Smoothie", 4.00, 1},
  {"Ice Tea", 2.75, 9}
};

void print_menu() {
  int i;
  printf("Menu:\n");
  for (i = 0; i < MAX_ITEMS; i++) {
    printf("%s - $%.2f, %d\n", items[i].name, items[i].price, items[i].quantity);
  }
}

int main() {
  int item_no;
  float total_price = 0.0;
  char continue_order = 'Y';

  print_menu();

  while (continue_order == 'Y') {
    printf("Enter item number: ");
    scanf("%d", &item_no);

    if (item_no < 0 || item_no >= MAX_ITEMS) {
      printf("Invalid item number.\n");
    } else {
      total_price += items[item_no].price * items[item_no].quantity;
    }

    printf("Continue order? (Y/N): ");
    scanf(" %c", &continue_order);
  }

  printf("Total price: $%.2f\n", total_price);

  return 0;
}
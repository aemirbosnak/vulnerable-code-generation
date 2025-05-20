//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  {"Smoothie", 3.50, 2},
  {"Biscuits", 1.50, 8},
  {"Cookies", 1.20, 6},
  {"Scones", 2.20, 3},
  {"Muffins", 2.00, 4},
  {"Pancakes", 2.75, 9},
  {"Waffles", 3.25, 1}
};

int main() {
  int item_no = 0;
  char item_name[20];
  float item_price;
  int item_quantity;
  float total_amount = 0.0;

  printf("Welcome to Caffeinated Dreams!\n");

  // Display menu items
  printf("Items:\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("%d. %s - %.2f, %d\n", i + 1, items[i].name, items[i].price, items[i].quantity);
  }

  // Get item name and quantity
  printf("Enter item name: ");
  scanf("%s", item_name);

  for (item_no = 0; item_no < MAX_ITEMS; item_no++) {
    if (strcmp(item_name, items[item_no].name) == 0) {
      printf("Enter item quantity: ");
      scanf("%d", &item_quantity);

      // Calculate item total price
      item_price = items[item_no].price * item_quantity;

      // Add item total price to total amount
      total_amount += item_price;

      break;
    }
  }

  // Calculate total amount
  total_amount = total_amount + total_amount * 0.10;

  // Print receipt
  printf("----------------------------------------\n");
  printf("Caffeinated Dreams Receipt\n");
  printf("----------------------------------------\n");
  printf("Item: %s, Quantity: %d, Price: %.2f\n", items[item_no].name, item_quantity, items[item_no].price);
  printf("Total amount: %.2f\n", total_amount);
  printf("Thank you for your visit!\n");

  return 0;
}
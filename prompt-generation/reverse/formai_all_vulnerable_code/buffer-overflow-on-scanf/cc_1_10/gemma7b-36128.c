//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS] = {
  {"Coffee", 10, 2.50},
  {"Tea", 5, 2.00},
  {"Juice", 7, 3.00},
  {"Smoothie", 2, 3.50},
  {"Cake", 3, 4.00},
  {"Pie", 4, 4.50},
  {"Cookies", 6, 5.00},
  {"Brownies", 1, 5.50},
  {"Meringues", 8, 6.00},
  {"Biscuits", 9, 6.50}
};

int main() {
  int i, total_items = 0, total_price = 0;
  char item_name[20];
  int item_quantity;

  // Calculate the total number of items
  for (i = 0; i < MAX_ITEMS; i++) {
    if (items[i].quantity > 0) {
      total_items++;
    }
  }

  // Print the total number of items
  printf("Total number of items: %d\n", total_items);

  // Calculate the total price of items
  for (i = 0; i < MAX_ITEMS; i++) {
    if (items[i].quantity > 0) {
      total_price += items[i].quantity * items[i].price;
    }
  }

  // Print the total price of items
  printf("Total price of items: $%.2f\n", total_price);

  // Get the item name and quantity from the user
  printf("Enter item name: ");
  scanf("%s", item_name);

  // Get the item quantity from the user
  printf("Enter item quantity: ");
  scanf("%d", &item_quantity);

  // Check if the item is available
  for (i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      // Check if the item quantity is within the available quantity
      if (items[i].quantity >= item_quantity) {
        // Update the item quantity
        items[i].quantity -= item_quantity;

        // Calculate the item total price
        float item_total_price = items[i].quantity * items[i].price;

        // Print the item total price
        printf("Item total price: $%.2f\n", item_total_price);
      } else {
        // Print an error message
        printf("Error: insufficient item quantity.\n");
      }
    }
  }

  return 0;
}
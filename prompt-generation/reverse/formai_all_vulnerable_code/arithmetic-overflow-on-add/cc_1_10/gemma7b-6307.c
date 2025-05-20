//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
  char name[20];
  int price;
  int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
  {"Coffee", 50, 10},
  {"Tea", 40, 8},
  {"Juice", 30, 6},
  {"Smoothie", 60, 5},
  {"Ice Cream", 70, 4},
  {"Cake", 80, 3},
  {"Cookies", 90, 2},
  {"Brownies", 100, 1}
};

int main() {
  int item_num = 0;
  int total_price = 0;

  printf("Welcome to Caffeinated Dreams!\n");

  // Display menu
  printf("Items:\n");
  for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
    printf("%s - $%d, Quantity: %d\n", items[item_num].name, items[item_num].price, items[item_num].quantity);
  }

  // Get item selection
  char item_name[20];
  printf("Enter item name: ");
  scanf("%s", item_name);

  // Find item
  item_num = -1;
  for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
    if (strcmp(items[item_num].name, item_name) == 0) {
      break;
    }
  }

  // If item is found, add to cart
  if (item_num != -1) {
    int quantity;
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    items[item_num].quantity += quantity;
    total_price += items[item_num].price * quantity;
  } else {
    printf("Item not found.\n");
  }

  // Calculate total price
  total_price = total_price + 10; // Service charge

  // Display total price
  printf("Total price: $%d\n", total_price);

  // Thank you
  printf("Thank you for your order, have a nice day!\n");

  return 0;
}
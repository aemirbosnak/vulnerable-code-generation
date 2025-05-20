//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
  char name[20];
  float price;
  int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
  {"Coffee", 2.50, 10},
  {"Tea", 3.00, 8},
  {"Juice", 2.00, 12},
  {"Smoothie", 4.00, 6},
  {"Pancake", 5.00, 14},
  {"French Toast", 4.50, 16},
  {"Waffles", 3.50, 18},
  {"Omelette", 4.00, 20},
  {"Scrambled Eggs", 3.00, 12},
  {"Fruit", 2.00, 16}
};

int main() {

  int item_num;
  char item_name[20];
  float item_price;
  int item_quantity;
  float total_amount = 0.0f;

  printf("Welcome to the C Cafe!\n");
  printf("Please select an item: ");

  scanf("%s", item_name);

  for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
    if (strcmp(items[item_num].name, item_name) == 0) {
      item_price = items[item_num].price;
      item_quantity = items[item_num].quantity;
      break;
    }
  }

  if (item_num == MAX_ITEM_NUM) {
    printf("Error: item not found.\n");
  } else {
    printf("Item: %s, Price: %.2f, Quantity: %d\n", items[item_num].name, items[item_num].price, items[item_num].quantity);
    printf("Enter the quantity you want to order: ");
    scanf("%d", &item_quantity);

    total_amount = item_price * item_quantity;
    printf("Total amount: %.2f\n", total_amount);
  }

  return 0;
}
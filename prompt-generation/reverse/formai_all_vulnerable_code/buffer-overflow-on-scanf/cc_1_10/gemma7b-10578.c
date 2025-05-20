//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  char name[20];
  float price;
  int quantity;
} item_t;

item_t items[] = {
  {"Coffee", 2.50, 10},
  {"Tea", 2.20, 8},
  {"Juice", 2.00, 6},
  {"Smoothie", 2.70, 7}
};

int main() {

  int i, order_num = 1, total_price = 0;
  char customer_name[20];

  printf("Welcome to the Crazy Coffee Cafe!\n");
  printf("Please enter your name: ");
  scanf("%s", customer_name);

  printf("Here is our menu:\n");
  for (i = 0; i < 4; i++) {
    printf("%s - %.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
  }

  printf("Please select an item: ");
  char item_name[20];
  scanf("%s", item_name);

  for (i = 0; i < 4; i++) {
    if (strcmp(item_name, items[i].name) == 0) {
      int quantity = 0;
      printf("Enter the quantity of your item: ");
      scanf("%d", &quantity);

      items[i].quantity -= quantity;
      total_price += quantity * items[i].price;
    }
  }

  printf("Thank you, %s, for your order!\n", customer_name);
  printf("Your total price is: $%.2f\n", total_price);

  return 0;
}
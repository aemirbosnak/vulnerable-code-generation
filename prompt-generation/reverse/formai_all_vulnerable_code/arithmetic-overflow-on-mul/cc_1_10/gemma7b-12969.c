//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define PAY_TYPE int
#define ITEM_TYPE struct Item

struct Item {
  char name[20];
  int price;
  int quantity;
};

typedef struct Item Item;

Item items[] = {
  {"Coffee", 50, 10},
  {"Tea", 40, 5},
  {"Juice", 30, 7},
  {"Water", 20, 8}
};

PAY_TYPE CalculateTotal(Item item, int quantity) {
  return item.price * quantity;
}

int main() {
  int i, total = 0;
  char choice;

  // Menu display
  printf("Welcome to Caffeinated Dreams!\n");
  printf("Please select an item:\n");
  for (i = 0; i < 4; i++) {
    printf("%d. %s - $%d\n", i + 1, items[i].name, items[i].price);
  }

  // Item selection and quantity
  scanf("Enter item number: ", &i);
  printf("Enter quantity: ");
  scanf("%d", &items[i - 1].quantity);

  // Total calculation
  total = CalculateTotal(items[i - 1], items[i - 1].quantity);

  // Payment processing
  printf("Total: $%d\n", total);
  printf("Please insert coins: ");
  scanf("%d", &i);

  // Change calculation
  i = i - total;
  printf("Change: $%d\n", i);

  return 0;
}
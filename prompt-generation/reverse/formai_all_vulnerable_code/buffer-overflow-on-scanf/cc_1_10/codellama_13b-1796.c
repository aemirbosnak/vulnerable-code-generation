//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
// Cafe Billing System
#include <stdio.h>

struct MenuItem {
  char name[50];
  float price;
};

struct Customer {
  char name[50];
  float total;
};

int main() {
  struct MenuItem items[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Mocha", 4.00},
    {"Espresso", 2.00},
    {"Americano", 3.50}
  };

  struct Customer customers[10];

  int itemCount = sizeof(items) / sizeof(items[0]);
  int customerCount = sizeof(customers) / sizeof(customers[0]);

  printf("Welcome to our cafe!\n");
  printf("We have the following items available:\n");
  for (int i = 0; i < itemCount; i++) {
    printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
  }
  printf("Please enter your name: ");
  scanf("%s", customers[0].name);

  for (int i = 0; i < customerCount; i++) {
    for (int j = 0; j < itemCount; j++) {
      printf("%d. %s - $%.2f\n", j + 1, items[j].name, items[j].price);
      printf("Please enter your choice: ");
      scanf("%d", &customers[i].total);
      break;
    }
  }

  printf("Here is your total: $%.2f\n", customers[0].total);

  return 0;
}
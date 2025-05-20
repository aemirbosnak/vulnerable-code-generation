//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coffee {
  char name[20];
  int quantity;
  double price;
} Coffee;

Coffee coffee_menu[] = {
  {"Latte", 2, 3.5},
  {"Cappuccino", 1, 4.0},
  {"Americano", 3, 2.0},
  {"Mocha", 0, 4.5},
  {"Macchiato", 1, 3.0}
};

int main() {
  char customer_name[20];
  printf("Welcome to the Coffee Cafe, %s!\n", customer_name);

  int order_num = 0;
  Coffee current_coffee;
  char order_choice[20];

  printf("Please select your coffee:**\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s (%d cups) - $%.2lf\n", i + 1, coffee_menu[i].name, coffee_menu[i].quantity, coffee_menu[i].price);
  }

  printf("Enter your choice number:");
  scanf("%d", &order_num);

  current_coffee = coffee_menu[order_num - 1];

  printf("You ordered: %s (%d cups)\n", current_coffee.name, current_coffee.quantity);

  double total_price = current_coffee.price * current_coffee.quantity;
  printf("Total price: $%.2lf\n", total_price);

  char payment_method[20];
  printf("Please select your payment method:**\n");
  printf("1. Cash\n");
  printf("2. Credit Card\n");
  printf("3. Debit Card\n");

  printf("Enter your choice:");
  scanf("%s", payment_method);

  double change = 0;
  if (strcmp(payment_method, "1") == 0) {
    change = total_price;
  } else if (strcmp(payment_method, "2") == 0) {
    change = total_price * 0.02;
  } else if (strcmp(payment_method, "3") == 0) {
    change = total_price * 0.01;
  }

  printf("Change: $%.2lf\n", change);

  return 0;
}
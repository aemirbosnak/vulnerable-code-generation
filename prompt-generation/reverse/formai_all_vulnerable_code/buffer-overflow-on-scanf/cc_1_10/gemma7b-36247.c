//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Coffee {
  char name[20];
  int quantity;
  float price;
} Coffee;

Coffee coffee_menu[] = {
  {"Latte", 2, 5.0},
  {"Cappuccino", 1, 4.5},
  {"Americano", 3, 3.0},
  {"Macchiato", 0, 4.0}
};

int main() {
  int i, order_num = 0, total_price = 0;
  Coffee order;

  system("clear");

  // Display menu
  printf("Welcome to the Surrealist Coffee Emporium!\n\n");
  for (i = 0; i < 4; i++) {
    printf("%d. %s - %d cups - $%.2f\n", i + 1, coffee_menu[i].name, coffee_menu[i].quantity, coffee_menu[i].price);
  }

  // Get user order
  printf("Please enter the number of your desired coffee: ");
  scanf("%d", &order_num);

  // Validate order
  if (order_num < 1 || order_num > 4) {
    printf("Invalid order number. Please try again.\n");
    return 1;
  }

  // Create order
  order = coffee_menu[order_num - 1];

  // Calculate total price
  total_price = order.quantity * order.price;

  // Display order confirmation
  printf("Your order:\n");
  printf("%s - %d cups\n", order.name, order.quantity);
  printf("Total price: $%.2f\n", total_price);

  // Prompt payment
  printf("Please pay the total price: ");
  float payment;
  scanf("%f", &payment);

  // Calculate change
  float change = payment - total_price;

  // Display change
  printf("Your change: $%.2f\n", change);

  return 0;
}
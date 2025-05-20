//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: creative
// C Cafe Billing System Example Program

#include <stdio.h>
#include <string.h>

// Define the menu items and their prices
#define MENU_ITEM_1 "Coffee"
#define MENU_ITEM_2 "Tea"
#define MENU_ITEM_3 "Cappuccino"
#define MENU_ITEM_4 "Latte"
#define MENU_ITEM_5 "Mocha"
#define MENU_ITEM_6 "Americano"
#define MENU_ITEM_7 "Breakfast"
#define MENU_ITEM_8 "Sandwich"
#define MENU_ITEM_9 "Soup"
#define MENU_ITEM_10 "Salad"
#define MENU_ITEM_11 "Dessert"

// Define the prices of the menu items
#define PRICE_COFFEE 1.00
#define PRICE_TEA 1.25
#define PRICE_CAPPUCCINO 3.00
#define PRICE_LATTE 4.50
#define PRICE_MOCHA 5.00
#define PRICE_AMERICANO 3.50
#define PRICE_BREAKFAST 7.50
#define PRICE_SANDWICH 5.00
#define PRICE_SOUP 4.00
#define PRICE_SALAD 6.00
#define PRICE_DESSERT 3.00

// Define the structure for a menu item
struct menu_item {
  char name[100];
  double price;
};

// Define the structure for a customer order
struct order {
  struct menu_item item;
  int quantity;
};

// Define the structure for a billing record
struct bill {
  char customer_name[100];
  double total_price;
  struct order order;
};

// Define the function to calculate the total price of an order
double calculate_total_price(struct order order) {
  return order.item.price * order.quantity;
}

// Define the function to print the billing record
void print_billing_record(struct bill bill) {
  printf("Customer Name: %s\n", bill.customer_name);
  printf("Total Price: $%.2f\n", bill.total_price);
  printf("Order: %s x %d\n", bill.order.item.name, bill.order.quantity);
}

// Define the function to process an order
void process_order(struct bill *bill, struct order order) {
  bill->total_price = calculate_total_price(order);
  bill->order = order;
}

int main() {
  // Create a menu
  struct menu_item menu[] = {
    {MENU_ITEM_1, PRICE_COFFEE},
    {MENU_ITEM_2, PRICE_TEA},
    {MENU_ITEM_3, PRICE_CAPPUCCINO},
    {MENU_ITEM_4, PRICE_LATTE},
    {MENU_ITEM_5, PRICE_MOCHA},
    {MENU_ITEM_6, PRICE_AMERICANO},
    {MENU_ITEM_7, PRICE_BREAKFAST},
    {MENU_ITEM_8, PRICE_SANDWICH},
    {MENU_ITEM_9, PRICE_SOUP},
    {MENU_ITEM_10, PRICE_SALAD},
    {MENU_ITEM_11, PRICE_DESSERT}
  };

  // Create a customer
  struct bill customer = {"John Doe", 0, {0}};

  // Print the menu
  printf("Welcome to our cafe!\n");
  printf("Here is our menu:\n");
  for (int i = 0; i < 11; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
  }

  // Ask the customer for their order
  int choice;
  printf("What would you like to order? ");
  scanf("%d", &choice);

  // Process the customer's order
  struct order order = {menu[choice - 1], 1};
  process_order(&customer, order);

  // Print the billing record
  print_billing_record(customer);

  return 0;
}
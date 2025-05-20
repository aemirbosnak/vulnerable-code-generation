//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure to store information about the customer
struct Customer {
  char name[50];
  int age;
  char gender;
  int table_number;
};

// Structure to store information about the menu items
struct MenuItem {
  char name[50];
  int price;
};

// Structure to store information about the order
struct Order {
  struct Customer customer;
  struct MenuItem menu_item;
  int quantity;
};

// Function to display the menu
void display_menu(struct MenuItem* menu, int num_items) {
  printf("Menu:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d. %s - $%d\n", i + 1, menu[i].name, menu[i].price);
  }
}

// Function to take an order
void take_order(struct Order* order, struct MenuItem* menu, int num_items) {
  printf("What is your name? ");
  scanf("%s", order->customer.name);
  printf("What is your age? ");
  scanf("%d", &order->customer.age);
  printf("What is your gender? ");
  scanf("%c", &order->customer.gender);
  printf("What table number are you sitting at? ");
  scanf("%d", &order->customer.table_number);

  printf("What would you like to order? ");
  int item_number;
  scanf("%d", &item_number);
  order->menu_item = menu[item_number - 1];

  printf("How many would you like to order? ");
  scanf("%d", &order->quantity);
}

// Function to display the order
void display_order(struct Order order) {
  printf("Customer: %s (%d, %c)\n", order.customer.name, order.customer.age, order.customer.gender);
  printf("Table Number: %d\n", order.customer.table_number);
  printf("Order: %d x %s - $%d\n", order.quantity, order.menu_item.name, order.menu_item.price);
}

// Function to calculate the total cost
int calculate_total_cost(struct Order order) {
  return order.quantity * order.menu_item.price;
}

int main() {
  // Create the menu items
  struct MenuItem menu[] = {
    {"Sandwich", 10},
    {"Salad", 8},
    {"Soup", 5},
    {"Breadsticks", 7},
    {"Ice Cream", 3},
  };

  // Create an order
  struct Order order;
  take_order(&order, menu, 5);

  // Display the order
  display_order(order);

  // Calculate the total cost
  int total_cost = calculate_total_cost(order);
  printf("Total cost: $%d\n", total_cost);

  return 0;
}
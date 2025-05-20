//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: curious
// Cafe Billing System

#include <stdio.h>
#include <string.h>

// Structures
struct Item {
  char name[50];
  float price;
};

struct Order {
  char customer_name[50];
  int table_number;
  struct Item items[5];
  int num_items;
};

// Functions
void print_menu();
void print_bill(struct Order order);

int main() {
  struct Order order;
  char input[100];
  int i, num_items;

  // Take input from the user
  printf("Enter the customer name: ");
  scanf("%s", order.customer_name);
  printf("Enter the table number: ");
  scanf("%d", &order.table_number);

  // Print the menu
  print_menu();

  // Take input for the items
  printf("Enter the number of items: ");
  scanf("%d", &num_items);
  for (i = 0; i < num_items; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", order.items[i].name);
    printf("Enter the price of item %d: ", i + 1);
    scanf("%f", &order.items[i].price);
  }

  // Print the bill
  print_bill(order);

  return 0;
}

// Functions
void print_menu() {
  printf("Menu:\n");
  printf("1. Coffee - $1.50\n");
  printf("2. Tea - $1.20\n");
  printf("3. Milkshake - $2.50\n");
  printf("4. Sandwich - $3.00\n");
  printf("5. Pizza - $4.00\n");
  printf("Enter the number of items: ");
}

void print_bill(struct Order order) {
  int i;
  float total_cost = 0;

  // Print the order details
  printf("Customer Name: %s\n", order.customer_name);
  printf("Table Number: %d\n", order.table_number);

  // Print the items and calculate the total cost
  for (i = 0; i < order.num_items; i++) {
    printf("Item %d: %s - $%.2f\n", i + 1, order.items[i].name, order.items[i].price);
    total_cost += order.items[i].price;
  }

  // Print the total cost
  printf("Total Cost: $%.2f\n", total_cost);
}
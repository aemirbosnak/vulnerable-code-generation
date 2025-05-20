//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu(void) {
  printf("\nWelcome to the Coffee Shop!\n");
  printf("Please select an option:\n");
  printf("1. Place an order\n");
  printf("2. View your order history\n");
  printf("3. Exit\n");
}

void place_order(void) {
  char name[50];
  char beverage[50];
  int quantity;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter the name of your beverage: ");
  scanf("%s", beverage);

  printf("Enter the quantity you want: ");
  scanf("%d", &quantity);

  // Calculate the total cost of the order
  int total_cost = quantity * 2;

  // Print the order confirmation
  printf("Order confirmation:\n");
  printf("Name: %s\n", name);
  printf("Beverage: %s\n", beverage);
  printf("Quantity: %d\n", quantity);
  printf("Total cost: $%d\n", total_cost);
}

void view_order_history(void) {
  // Assuming there is a database of previous orders
  // This code would display the previous orders
}

int main(void) {
  int choice;

  print_menu();

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      place_order();
      break;
    case 2:
      view_order_history();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
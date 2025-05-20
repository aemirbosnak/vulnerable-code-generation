//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the menu items and their prices
char menu_items[MAX_ITEMS][20] = {"Coffee", "Tea", "Soda", "Juice", "Water", "Sandwich", "Salad", "Soup", "Cookie", "Muffin"};
float menu_prices[MAX_ITEMS] = {1.50, 1.25, 1.00, 1.25, 0.50, 4.00, 5.00, 3.50, 1.00, 1.25};

// Define the function to print the menu
void print_menu() {
  printf("Welcome to the Cafe!\n");
  printf("Here is our menu:\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu_items[i], menu_prices[i]);
  }
}

// Define the function to get the user's order
int get_order() {
  int item_number;
  printf("Please enter the number of the item you would like to order: ");
  scanf("%d", &item_number);
  return item_number;
}

// Define the function to calculate the total cost of the order
float calculate_total(int item_numbers[], int num_items) {
  float total = 0.0;
  for (int i = 0; i < num_items; i++) {
    total += menu_prices[item_numbers[i] - 1];
  }
  return total;
}

// Define the function to print the receipt
void print_receipt(int item_numbers[], int num_items, float total) {
  printf("Here is your receipt:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu_items[item_numbers[i] - 1], menu_prices[item_numbers[i] - 1]);
  }
  printf("Total: $%.2f\n", total);
}

// Define the main function
int main() {
  // Print the menu
  print_menu();

  // Get the user's order
  int item_numbers[MAX_ITEMS];
  int num_items = 0;
  do {
    int item_number = get_order();
    if (item_number > 0 && item_number <= MAX_ITEMS) {
      item_numbers[num_items] = item_number;
      num_items++;
    } else {
      printf("Invalid item number. Please try again.\n");
    }
  } while (num_items < MAX_ITEMS);

  // Calculate the total cost of the order
  float total = calculate_total(item_numbers, num_items);

  // Print the receipt
  print_receipt(item_numbers, num_items, total);

  return 0;
}
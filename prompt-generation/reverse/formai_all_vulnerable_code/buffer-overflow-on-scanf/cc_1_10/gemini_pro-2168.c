//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Cold Coffee", "Hot Chocolate", "Juice"};
float prices[] = {20.0, 15.0, 25.0, 20.0, 18.0};

// Get the number of items ordered
int get_num_items() {
  int num_items;
  printf("How many items would you like to order? ");
  scanf("%d", &num_items);
  return num_items;
}

// Get the item names and quantities ordered
void get_order(char order[][20], int quantities[], int num_items) {
  for (int i = 0; i < num_items; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", order[i]);
    printf("Enter the quantity of item %d: ", i + 1);
    scanf("%d", &quantities[i]);
  }
}

// Calculate the total bill
float calculate_bill(char order[][20], int quantities[], int num_items) {
  float total = 0.0;
  for (int i = 0; i < num_items; i++) {
    // Find the index of the item in the menu
    int index = -1;
    for (int j = 0; j < 5; j++) {
      if (strcmp(order[i], menu[j]) == 0) {
        index = j;
        break;
      }
    }

    // If the item is not found, print an error message and continue
    if (index == -1) {
      printf("Invalid item: %s\n", order[i]);
      continue;
    }

    // Calculate the price of the item
    float price = prices[index] * quantities[i];

    // Add the price of the item to the total
    total += price;
  }

  return total;
}

// Print the bill
void print_bill(char order[][20], int quantities[], int num_items, float total) {
  printf("\nHere is your bill:\n");
  printf("-----------------------------------------------------\n");
  printf("Item\t\tQuantity\tPrice\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s\t\t%d\t\t%.2f\n", order[i], quantities[i], prices[i] * quantities[i]);
  }
  printf("-----------------------------------------------------\n");
  printf("Total:\t\t\t%.2f\n", total);
  printf("-----------------------------------------------------\n");
}

// Main function
int main() {
  // Get the number of items ordered
  int num_items = get_num_items();

  // Get the item names and quantities ordered
  char order[num_items][20];
  int quantities[num_items];
  get_order(order, quantities, num_items);

  // Calculate the total bill
  float total = calculate_bill(order, quantities, num_items);

  // Print the bill
  print_bill(order, quantities, num_items, total);

  return 0;
}
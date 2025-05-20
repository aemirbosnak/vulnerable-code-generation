//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS] = {
  {"Coffee", 10, 50.0},
  {"Tea", 5, 40.0},
  {"Juice", 7, 30.0},
  {"Soda", 8, 20.0},
  {"Water", 9, 10.0},
  {"Biscuits", 12, 25.0},
  {"Scones", 6, 35.0},
  {"Muffins", 4, 45.0},
  {"Cakes", 2, 60.0},
  {"Cookies", 3, 55.0}
};

int main() {

  int numItems = 0;
  float totalAmount = 0.0f;

  // Display menu and get customer order
  printf("Welcome to the C Cafe!\n");
  printf("Please select an item from the menu:\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("%d. %s - %d units - $%.2f\n", i + 1, items[i].name, items[i].quantity, items[i].price);
  }

  int itemChoice = 0;
  printf("Enter the number of the item you want to order: ");
  scanf("%d", &itemChoice);

  // Validate item choice
  if (itemChoice < 1 || itemChoice > MAX_ITEMS) {
    printf("Invalid item choice.\n");
    return 1;
  }

  // Get item quantity
  int quantity = 0;
  printf("Enter the quantity you want to order: ");
  scanf("%d", &quantity);

  // Calculate total cost
  float itemPrice = items[itemChoice - 1].price * quantity;
  totalAmount += itemPrice;

  // Print order confirmation
  printf("Your order:\n");
  printf("%s - %d units - $%.2f\n", items[itemChoice - 1].name, quantity, itemPrice);
  printf("Total amount: $%.2f\n", totalAmount);

  // Prompt for payment
  printf("Please pay the total amount: $%.2f\n", totalAmount);
  float payment = 0.0f;
  scanf("%f", &payment);

  // Validate payment
  if (payment < totalAmount) {
    printf("Insufficient payment.\n");
    return 1;
  }

  // Give change
  float change = payment - totalAmount;
  printf("Your change: $%.2f\n", change);

  return 0;
}
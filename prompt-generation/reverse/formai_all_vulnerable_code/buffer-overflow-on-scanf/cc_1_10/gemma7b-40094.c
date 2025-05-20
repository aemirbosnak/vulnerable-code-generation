//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS];

int main() {
  int numItems = 0;
  float totalCost = 0.0f;
  char choice = 'y';

  // Loop to add items to the menu
  while (choice == 'y') {
    // Get item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);

    numItems++;
    printf("Add another item? (y/n): ");
    scanf(" %c", &choice);
  }

  // Calculate total cost
  for (int i = 0; i < numItems; i++) {
    totalCost += items[i].quantity * items[i].price;
  }

  // Print receipt
  printf("\n---------------------------------------------------\n");
  printf("C Cafe Billing System\n");
  printf("---------------------------------------------------\n");
  printf("Items:\n");

  for (int i = 0; i < numItems; i++) {
    printf("%s - %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
  }

  printf("\nTotal Cost: %.2f\n", totalCost);
  printf("Thank you for your order!\n");

  return 0;
}
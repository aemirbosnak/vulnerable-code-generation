//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS];

void calculateTotal(int numItems) {
  float total = 0;
  for (int i = 0; i < numItems; i++) {
    total += items[i].quantity * items[i].price;
  }
  printf("Total: %.2f\n", total);
}

int main() {
  int numItems = 0;
  char choice;

  printf("Welcome to the Coffee Cafe!\n");

  // Loop until the user enters "q"
  while (choice != 'q') {
    // Get the item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter price: ");
    scanf("%f", &items[numItems].price);

    // Increment the number of items
    numItems++;

    // Ask the user if they want to continue
    printf("Do you want to continue? (Y/N): ");
    scanf(" %c", &choice);
  }

  // Calculate the total cost
  calculateTotal(numItems);

  // Thank the customer
  printf("Thank you for your order. Come again soon!\n");

  return 0;
}
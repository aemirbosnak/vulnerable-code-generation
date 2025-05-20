//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEM_NUM] = {
  {"Coffee", 10, 2.50},
  {"Tea", 8, 2.20},
  {"Juice", 12, 2.00},
  {"Soda", 15, 2.70},
  {"Water", 20, 2.30}
};

int main() {
  int numItems = 5;
  int itemIndex;
  float totalCost = 0.0;
  char choice;

  printf("Welcome to the C Cafe!\n");

  // Display item list
  printf("Items:");
  for (int i = 0; i < numItems; i++) {
    printf("\n%s - %d - %.2f", items[i].name, items[i].quantity, items[i].price);
  }

  // Get item index and quantity
  printf("\nEnter item index:");
  scanf("%d", &itemIndex);

  printf("Enter quantity:");
  scanf("%d", &items[itemIndex].quantity);

  // Calculate total cost
  totalCost = items[itemIndex].price * items[itemIndex].quantity;

  // Display total cost
  printf("\nTotal cost: %.2f", totalCost);

  // Offer additional items?
  printf("\nWould you like to add another item? (Y/N)");
  scanf(" %c", &choice);

  // Repeat if necessary
  if (choice == 'Y') {
    main();
  }

  // Thank you and exit
  printf("\nThank you for your visit to the C Cafe. See you again next time!");
  exit(0);
}
//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
  char *name;
  int price;
};

struct MenuItem menuItems[] = {
  { "A flagon of ale", 10 },
  { "A trencher of bread", 5 },
  { "A joint of meat", 15 },
  { "A goblet of wine", 12 },
  { "A slice of pie", 6 }
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Get the user's order
void getOrder(struct MenuItem *menuItems, int *order, int *numItems) {
  int choice;

  printf("Welcome to the tavern, weary traveler! What wouldst thou have to eat and drink?\n");

  *numItems = 0;

  do {
    printf("Enter the number of the item you would like to order, or 0 to finish:\n");
    for (int i = 0; i < 5; i++) {
      printf("%d. %s - %d gold\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
    scanf("%d", &choice);

    if (choice > 0 && choice <= 5) {
      order[*numItems] = choice - 1;
      *numItems = *numItems + 1;
    }
  } while (choice != 0 && *numItems < MAX_ITEMS);
}

// Calculate the total bill
int calculateBill(struct MenuItem *menuItems, int *order, int numItems) {
  int total = 0;

  for (int i = 0; i < numItems; i++) {
    total = total + menuItems[order[i]].price;
  }

  return total;
}

// Print the bill
void printBill(struct MenuItem *menuItems, int *order, int numItems, int total) {
  printf("Thy bill, good sir:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s - %d gold\n", menuItems[order[i]].name, menuItems[order[i]].price);
  }
  printf("Total: %d gold\n", total);
}

// Main function
int main() {
  int order[MAX_ITEMS];
  int numItems;
  int total;

  getOrder(menuItems, order, &numItems);
  total = calculateBill(menuItems, order, numItems);
  printBill(menuItems, order, numItems, total);

  return 0;
}
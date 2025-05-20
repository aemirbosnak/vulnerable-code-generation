//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int itemID;
  char *itemName;
  float price;
} Item;

Item items[] = {
  {1, "Coffee", 1.50},
  {2, "Tea", 1.25},
  {3, "Cake", 2.00},
  {4, "Muffin", 1.75},
  {5, "Cookie", 0.75}
};

int numItems = sizeof(items) / sizeof(Item);

float calculateTotal(int *order, int numItemsOrdered) {
  float total = 0;
  for (int i = 0; i < numItemsOrdered; i++) {
    total += items[order[i]].price;
  }
  return total;
}

void printReceipt(int *order, int numItemsOrdered, float total) {
  printf("==========================================\n");
  printf("Cafe Billing System\n");
  printf("==========================================\n");
  for (int i = 0; i < numItemsOrdered; i++) {
    printf("%s\t\t\t%.2f\n", items[order[i]].itemName, items[order[i]].price);
  }
  printf("------------------------------------------\n");
  printf("Total\t\t\t%.2f\n", total);
  printf("==========================================\n");
}

int main() {
  int order[100];
  int numItemsOrdered = 0;
  float total = 0;

  char choice;
  do {
    printf("Enter the item ID: ");
    scanf("%d", &order[numItemsOrdered]);
    numItemsOrdered++;

    printf("Do you want to order another item? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y');

  total = calculateTotal(order, numItemsOrdered);
  printReceipt(order, numItemsOrdered, total);

  return 0;
}
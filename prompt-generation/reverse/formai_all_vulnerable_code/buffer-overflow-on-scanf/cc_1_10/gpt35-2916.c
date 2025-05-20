//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item {
  char name[20];
  int quantity;
  float price;
};

void addItem(struct Item *items, int *numItems) {
  if (*numItems >= MAX_ITEMS) {
    printf("Cannot add more items, warehouse is full.\n");
    return;
  }
  printf("Enter item name: ");
  scanf("%s", items[*numItems].name);
  printf("Enter item quantity: ");
  scanf("%d", &items[*numItems].quantity);
  printf("Enter item price: ");
  scanf("%f", &items[*numItems].price);
  (*numItems)++;
  printf("Item added successfully.\n");
}

void removeItem(struct Item *items, int *numItems) {
  if (*numItems <= 0) {
    printf("Warehouse is empty, cannot remove items.\n");
    return;
  }
  char name[20];
  printf("Enter item name to remove: ");
  scanf("%s", name);
  for (int i = 0; i < *numItems; i++) {
    if (strcmp(items[i].name, name) == 0) {
      (*numItems)--;
      for (int j = i; j < *numItems; j++) {
        items[j] = items[j + 1];
      }
      printf("Item removed successfully.\n");
      return;
    }
  }
  printf("Item not found.\n");
}

void searchItem(struct Item *items, int *numItems) {
  if (*numItems <= 0) {
    printf("Warehouse is empty, nothing to search.\n");
    return;
  }
  char name[20];
  printf("Enter item name to search: ");
  scanf("%s", name);
  for (int i = 0; i < *numItems; i++) {
    if (strcmp(items[i].name, name) == 0) {
      printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
      return;
    }
  }
  printf("Item not found.\n");
}

void displayItems(struct Item *items, int *numItems) {
  if (*numItems <= 0) {
    printf("Warehouse is empty, nothing to display.\n");
    return;
  }
  printf("Name\tQuantity\tPrice\n");
  for (int i = 0; i < *numItems; i++) {
    printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
  }
}

int main() {
  struct Item items[MAX_ITEMS];
  int numItems = 0;
  int choice;
  do {
    printf("1. Add item\n2. Remove item\n3. Search item\n4. Display items\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addItem(items, &numItems);
        break;
      case 2:
        removeItem(items, &numItems);
        break;
      case 3:
        searchItem(items, &numItems);
        break;
      case 4:
        displayItems(items, &numItems);
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  } while (choice != 5);
  return 0;
}
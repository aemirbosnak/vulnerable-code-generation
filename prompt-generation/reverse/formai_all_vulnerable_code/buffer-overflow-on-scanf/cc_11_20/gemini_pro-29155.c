//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
  char name[32];
  int quantity;
  float price;
} item_t;

item_t inventory[MAX_ITEMS];

int main() {
  int num_items = 0;

  while (1) {
    printf("Welcome to the post-apocalyptic inventory system.\n");
    printf("Options:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (num_items == MAX_ITEMS) {
          printf("Inventory is full.\n");
          break;
        }

        printf("Enter item name: ");
        scanf("%s", inventory[num_items].name);

        printf("Enter item quantity: ");
        scanf("%d", &inventory[num_items].quantity);

        printf("Enter item price: ");
        scanf("%f", &inventory[num_items].price);

        num_items++;
        break;

      case 2:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
          break;
        }

        printf("Enter item name to remove: ");
        char name[32];
        scanf("%s", name);

        int found = 0;
        for (int i = 0; i < num_items; i++) {
          if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < num_items - 1; j++) {
              inventory[j] = inventory[j + 1];
            }
            num_items--;
            break;
          }
        }

        if (!found) {
          printf("Item not found.\n");
        }
        break;

      case 3:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
          break;
        }

        printf("Inventory:\n");
        for (int i = 0; i < num_items; i++) {
          printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
        break;

      case 4:
        printf("Goodbye.\n");
        exit(0);

      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
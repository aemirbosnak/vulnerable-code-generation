//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct item {
  int id;
  char name[50];
  int quantity;
};

int main() {
  int choice;
  struct item items[100];
  int item_count = 0;

  while (1) {
    printf("\nEnter your choice:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. View warehouse inventory\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nAdding new item...\n");
        printf("Enter item name: ");
        scanf("%s", items[item_count].name);
        printf("Enter quantity: ");
        scanf("%d", &items[item_count].quantity);
        items[item_count].id = item_count + 1;
        item_count++;
        printf("Item added successfully!\n");
        break;

      case 2:
        printf("\nRemoving item...\n");
        printf("Enter item ID: ");
        int id;
        scanf("%d", &id);
        for (int i = 0; i < item_count; i++) {
          if (items[i].id == id) {
            for (int j = i; j < item_count - 1; j++) {
              items[j] = items[j + 1];
            }
            item_count--;
            printf("Item removed successfully!\n");
            break;
          }
        }
        break;

      case 3:
        printf("\nWarehouse inventory:\n");
        printf("%-10s %-20s %s\n", "ID", "Name", "Quantity");
        for (int i = 0; i < item_count; i++) {
          printf("%-10d %-20s %d\n", items[i].id, items[i].name, items[i].quantity);
        }
        break;

      case 4:
        printf("\nGoodbye!\n");
        exit(0);

      default:
        printf("\nInvalid choice, try again.\n");
        break;
    }
  }

  return 0;
}
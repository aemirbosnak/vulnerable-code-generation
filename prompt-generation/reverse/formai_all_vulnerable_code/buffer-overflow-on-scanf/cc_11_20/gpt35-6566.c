//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[20];
  int quantity;
  float price;
};

int main() {

  struct Item items[50];
  int num_items = 0;
  float total_value = 0;

  int choice;

  while (1) {

    printf("Please choose an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Print inventory\n");
    printf("4. Print total value\n");
    printf("5. Quit\n");

    scanf("%d", &choice);

    switch (choice) {

      case 1:

        printf("Enter item name: ");
        scanf("%s", items[num_items].name);

        printf("Enter item quantity: ");
        scanf("%d", &items[num_items].quantity);

        printf("Enter item price (per unit): ");
        scanf("%f", &items[num_items].price);

        num_items++;
        break;

      case 2:

        printf("Enter item name to remove: ");
        char item_to_remove[20];
        scanf("%s", item_to_remove);

        int index_of_item_to_remove = -1;
        for (int i = 0; i < num_items; i++) {
          if (strcmp(items[i].name, item_to_remove) == 0) {
            index_of_item_to_remove = i;
            break;
          }
        }

        if (index_of_item_to_remove == -1) {
          printf("Item not found.");
        }
        else {
          int quantity_to_remove;
          printf("Enter quantity to remove: ");
          scanf("%d", &quantity_to_remove);

          if (quantity_to_remove > items[index_of_item_to_remove].quantity) {
            printf("Not enough quantity to remove.");
          }
          else {
            items[index_of_item_to_remove].quantity -= quantity_to_remove;

            if (items[index_of_item_to_remove].quantity == 0) {
              for (int i = index_of_item_to_remove; i < (num_items - 1); i++) {
                items[i] = items[i+1];
              }
              num_items--;
            }
          }
        }
        break;

      case 3:

        printf("Inventory:\n");
        printf("%-20s%-20s%s\n", "Name", "Quantity", "Price");

        for (int i = 0; i < num_items; i++) {
          printf("%-20s%-20d%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
        break;

      case 4:

        for (int i = 0; i < num_items; i++) {
          total_value += (items[i].quantity * items[i].price);
        }

        printf("Total value: %.2f\n", total_value);
        break;

      case 5:

        printf("Thanks for using the warehouse management system.\n");
        exit(0);
        break;

      default:

        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}
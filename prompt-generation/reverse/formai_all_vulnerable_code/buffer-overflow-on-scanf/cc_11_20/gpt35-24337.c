//FormAI DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
  char name[20];
  int quantity;
  float price;
} Item;

void print_menu() {
  printf("Please choose an option:\n");
  printf("1. Add item to inventory\n");
  printf("2. Display inventory\n");
  printf("3. Search by name\n");
  printf("4. Search by price\n");
  printf("5. Remove item from inventory\n");
  printf("6. Exit\n");
}

int main() {
  Item inventory[MAX_ITEMS];
  int num_items = 0;
  int selection;

  do {
    print_menu();
    printf("Selection: ");
    scanf("%d", &selection);
    printf("\n");

    switch (selection) {
      case 1:
        if (num_items < MAX_ITEMS) {
          Item item;
          printf("Name: ");
          scanf("%s", item.name);
          printf("Quantity: ");
          scanf("%d", &item.quantity);
          printf("Price: ");
          scanf("%f", &item.price);
          printf("\n");

          inventory[num_items] = item;
          num_items++;

          printf("Item added to inventory.\n");
        } else {
          printf("Error: inventory full.\n");
        }
        break;

      case 2:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
        } else {
          printf("Inventory:\n");
          printf("Name\tQuantity\tPrice\n");
          for (int i = 0; i < num_items; i++) {
            printf("%s\t%d\t%f\n", inventory[i].name, inventory[i].quantity,
                inventory[i].price);
          }
        }
        break;

      case 3:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
        } else {
          char search_name[20];
          printf("Name: ");
          scanf("%s", search_name);
          printf("\n");

          for (int i = 0; i < num_items; i++) {
            if (strcmp(search_name, inventory[i].name) == 0) {
              printf("Name\tQuantity\tPrice\n");
              printf("%s\t%d\t%f\n", inventory[i].name, inventory[i].quantity,
                  inventory[i].price);
              break;
            }
            if (i == num_items - 1) {
              printf("Item not found.\n");
            }
          }
        }
        break;

      case 4:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
        } else {
          float search_price;
          printf("Price: ");
          scanf("%f", &search_price);
          printf("\n");

          for (int i = 0; i < num_items; i++) {
            if (search_price == inventory[i].price) {
              printf("Name\tQuantity\tPrice\n");
              printf("%s\t%d\t%f\n", inventory[i].name, inventory[i].quantity,
                  inventory[i].price);
            }
            if (i == num_items - 1) {
              printf("Items not found.\n");
            }
          }
        }
        break;

      case 5:
        if (num_items == 0) {
          printf("Inventory is empty.\n");
        } else {
          char remove_name[20];
          printf("Name: ");
          scanf("%s", remove_name);
          printf("\n");

          for (int i = 0; i < num_items; i++) {
            if (strcmp(remove_name, inventory[i].name) == 0) {
              memmove(&inventory[i], &inventory[i+1], (num_items-i-1) * sizeof(Item));
              num_items--;
              printf("Item removed from inventory.\n");
              break;
            }
            if (i == num_items - 1) {
              printf("Item not found.\n");
            }
          }
        }
        break;

      case 6:
        printf("Exiting program.\n");
        exit(0);

      default:
        printf("Invalid selection.\n");
        break;
    }

    printf("\n");

  } while (1);

  return 0;
}
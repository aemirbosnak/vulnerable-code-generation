//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct Item {
  char name[20];
  int quantity;
};

int main() {
  struct Item inventory[MAX_ITEMS];
  int num_items = 0;
  int choice;

  printf("Welcome to our Happy Warehouse Management System!\n");

  do {
    printf("\nWhat do you want to do? Please input a number:\n");
    printf("1. Add an item to inventory\n");
    printf("2. Remove an item from inventory\n");
    printf("3. Check inventory\n");
    printf("4. Exit\n");

    printf("\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (num_items >= MAX_ITEMS) {
          printf("Sorry, the inventory is full.");
        } else {
          printf("What is the name of the item you want to add? ");
          scanf("%s", inventory[num_items].name);
          printf("How many do you want to add? ");
          scanf("%d", &inventory[num_items].quantity);
          num_items++;
          printf("Item added successfully!");
        }
        break;

      case 2:
        if (num_items == 0) {
          printf("There are no items in inventory.");
        } else {
          char name[20];
          printf("What is the name of the item you want to remove? ");
          scanf("%s", name);

          int i;
          for (i = 0; i < num_items; i++) {
            if (strcmp(inventory[i].name, name) == 0) {
              int j;
              for (j = i; j < num_items - 1; j++) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].quantity = inventory[j + 1].quantity;
              }
              num_items--;
              printf("Item removed successfully!");
              break;
            }
          }
          if (i == num_items) {
            printf("The item was not found in inventory.");
          }
        }
        break;

      case 3:
        if (num_items == 0) {
          printf("There are no items in inventory.");
        } else {
          int i;
          for (i = 0; i < num_items; i++) {
            printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
          }
        }
        break;

      case 4:
        printf("Exiting the Happy Warehouse Management System. Have a nice day!\n");
        break;

      default:
        printf("Invalid choice. Please choose again.\n");
        break;
    }

  } while (choice != 4);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  char name[50];
  int quantity;
  float price;
} Item;

int main() {
  Item items[100];
  int i = 0;
  char command[20];

  printf("Welcome to the C Warehouse Management System!\n");

  while (1) {
    printf("Enter a command (add, remove, list, exit): ");
    scanf("%s", command);

    switch (command[0]) {
      case 'a':
        printf("Enter the item name: ");
        scanf("%s", items[i].name);
        printf("Enter the item quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter the item price: ");
        scanf("%f", &items[i].price);
        i++;
        break;
      case 'r':
        printf("Enter the item name: ");
        scanf("%s", items[i].name);
        for (int j = 0; j < i; j++) {
          if (strcmp(items[j].name, items[i].name) == 0) {
            items[j].quantity--;
            break;
          }
        }
        break;
      case 'l':
        printf("List of items:\n");
        for (int j = 0; j < i; j++) {
          printf("%s - %d - %.2f\n", items[j].name, items[j].quantity, items[j].price);
        }
        break;
      case 'e':
        exit(0);
        break;
      default:
        printf("Invalid command.\n");
    }
  }

  return 0;
}
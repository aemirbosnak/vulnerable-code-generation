//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[50];
  float price;
  int quantity;
} Item;

Item items[MAX_ITEMS];

void print_menu() {
  int i = 0;
  printf("Menu:\n");
  for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
    printf("%s - %.2f (%d)\n", items[i].name, items[i].price, items[i].quantity);
  }
}

void add_item() {
  Item item;
  printf("Enter item name: ");
  scanf("%s", item.name);
  printf("Enter item price: ");
  scanf("%f", &item.price);
  printf("Enter item quantity: ");
  scanf("%d", &item.quantity);
  items[MAX_ITEMS - 1] = item;
}

void remove_item() {
  char item_name[50];
  printf("Enter item name: ");
  scanf("%s", item_name);
  int i = 0;
  for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      items[i] = items[MAX_ITEMS - 1];
      items[MAX_ITEMS - 1].name[0] = '\0';
      break;
    }
  }
}

void calculate_total() {
  int i = 0;
  float total = 0.0f;
  for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
    total += items[i].price * items[i].quantity;
  }
  printf("Total: $%.2f\n", total);
}

int main() {
  int choice;
  print_menu();
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      add_item();
      break;
    case 2:
      remove_item();
      break;
    case 3:
      calculate_total();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medical_item {
  int id;
  char name[100];
  int quantity;
  float price;
};

struct medical_item database[100];
int total_items = 0;

void add_item() {
  int id, quantity;
  float price;
  char name[100];

  printf("Enter item id: ");
  scanf("%d", &id);

  printf("Enter item name: ");
  scanf("%s", name);

  printf("Enter item quantity: ");
  scanf("%d", &quantity);

  printf("Enter item price: ");
  scanf("%f", &price);

  struct medical_item item;
  item.id = id;
  strcpy(item.name, name);
  item.quantity = quantity;
  item.price = price;

  database[total_items++] = item;

  printf("Item added successfully.\n\n");
}

void search_item() {
  int id;
  printf("Enter item id: ");
  scanf("%d", &id);

  for (int i = 0; i < total_items; i++) {
    if (database[i].id == id) {
      printf("Name: %s\n", database[i].name);
      printf("Quantity: %d\n", database[i].quantity);
      printf("Price: %.2f\n\n", database[i].price);
      return;
    }
  }

  printf("Item not found.\n\n");
}

void delete_item() {
  int id;
  printf("Enter item id: ");
  scanf("%d", &id);

  for (int i = 0; i < total_items; i++) {
    if (database[i].id == id) {
      for (int j = i; j < total_items - 1; j++) {
        database[j] = database[j+1];
      }

      total_items--;
      printf("Item deleted successfully.\n\n");
      return;
    }
  }

  printf("Item not found.\n\n");
}

void display_stock() {
  printf("ID\tName\tQuantity\tPrice\n\n");

  for (int i = 0; i < total_items; i++) {
    struct medical_item item = database[i];
    printf("%d\t%s\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
  }

  printf("\n");
}

int main() {
  while (1) {
    printf("Enter 1 to add item, 2 to search item, 3 to delete item, 4 to display stock, and 5 to exit.\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_item();
        break;
      case 2:
        search_item();
        break;
      case 3:
        delete_item();
        break;
      case 4:
        display_stock();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n\n");
    }
  }

  return 0;
}
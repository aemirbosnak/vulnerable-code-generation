//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
  int id;
  char name[20];
  float price;
  int quantity;
};

typedef struct product Product;

void add_item(Product* inventory, int *num_items) {
  Product new_item;
  printf("Enter product name: ");
  scanf("%s", new_item.name);
  printf("Enter product price: ");
  scanf("%f", &new_item.price);
  printf("Enter product quantity: ");
  scanf("%d", &new_item.quantity);
  new_item.id = *num_items + 1;
  inventory[*num_items] = new_item;
  (*num_items)++;
}

void update_item(Product* inventory, int num_items, int id) {
  for(int i = 0; i < num_items; i++) {
    if(inventory[i].id == id) {
      printf("Enter new price: ");
      scanf("%f", &inventory[i].price);
      printf("Enter new quantity: ");
      scanf("%d", &inventory[i].quantity);
      return;
    }
  }
  printf("Item with ID %d not found.", id);
}

void delete_item(Product* inventory, int *num_items, int id) {
  for(int i = 0; i < *num_items; i++) {
    if(inventory[i].id == id) {
      for(int j = i; j < *num_items - 1; j++) {
        inventory[j] = inventory[j+1];
      }
      (*num_items)--;
      return;
    }
  }
  printf("Item with ID %d not found.", id);
}

int main() {
  Product inventory[100];
  int num_items = 0;
  int choice;
  int id;

  while(1) {
    printf("\nProduct Inventory Management System\n");
    printf("-----------------------------------\n");
    printf("(1) Add an item\n");
    printf("(2) Update an item\n");
    printf("(3) Delete an item\n");
    printf("(4) List all items\n");
    printf("(5) Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_item(inventory, &num_items);
        break;

      case 2:
        printf("Enter ID of item to update: ");
        scanf("%d", &id);
        update_item(inventory, num_items, id);
        break;

      case 3:
        printf("Enter ID of item to delete: ");
        scanf("%d", &id);
        delete_item(inventory, &num_items, id);
        break;

      case 4:
        printf("\nProduct Inventory\n");
        for(int i = 0; i < num_items; i++) {
          printf("%d | %s | %.2f | %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid choice. Please try again.");
    }
  }
  return 0;
}
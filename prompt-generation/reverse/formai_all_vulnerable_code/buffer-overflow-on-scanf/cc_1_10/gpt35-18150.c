//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
  char name[20];
  int quantity;
  float price;
};

void add_items(struct item *inventory, int *total_items) {
  char name[20];
  int quantity;
  float price;

  printf("Enter the name of the item: ");
  scanf("%s", name);
  printf("Enter the quantity: ");
  scanf("%d", &quantity);
  printf("Enter the price: ");
  scanf("%f", &price);

  strcpy(inventory[*total_items].name, name);
  inventory[*total_items].quantity = quantity;
  inventory[*total_items].price = price;

  *total_items += 1;
  
  printf("Item added successfully!\n\n");
}

void display_items(struct item *inventory, int total_items) {
  printf("*********Inventory*********\n\n");

  for(int i=0; i<total_items; i++) {
    printf("Name: %s\n", inventory[i].name);
    printf("Quantity: %d\n", inventory[i].quantity);
    printf("Price: %.2f\n\n", inventory[i].price);
  }
}

void sell_items(struct item *inventory, int *total_items) {
  char name[20];
  int quantity;
  int index = -1;

  printf("Enter the name of the item to sell: ");
  scanf("%s", name);
  printf("Enter the quantity: ");
  scanf("%d", &quantity);

  for(int i=0; i<*total_items; i++) {
    if(strcmp(inventory[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  if(index == -1) {
    printf("Item not found!\n\n");
    return;
  }

  if(inventory[index].quantity < quantity) {
    printf("Quantity not available!\n\n");
    return;
  }

  inventory[index].quantity -= quantity;

  if(inventory[index].quantity == 0) {
    for(int i=index; i<*total_items-1; i++) {
      strcpy(inventory[i].name, inventory[i+1].name);
      inventory[i].quantity = inventory[i+1].quantity;
      inventory[i].price = inventory[i+1].price;
    }

    *total_items -= 1;
  }
  
  printf("Sale successful!\n\n");
}

void menu() {
  printf("*********Warehouse Management System*********\n\n");
  printf("1. Add item\n");
  printf("2. Display items\n");
  printf("3. Sell item\n");
  printf("4. Exit\n\n");
}

int main() {
  int choice;
  int total_items = 0;
  struct item inventory[100];

  do {
    menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_items(inventory, &total_items);
        break;
      case 2:
        display_items(inventory, total_items);
        break;
      case 3:
        sell_items(inventory, &total_items);
        break;
      case 4:
        printf("Thank you for using the Warehouse Management System!\n");
        break;
      default:
        printf("Invalid choice!\n\n");
    }
  } while(choice != 4);

  return 0;
}
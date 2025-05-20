//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

typedef struct{
  char item_name[20];
  int quantity;
  float price;
} Item;

Item warehouse[100];
int num_items = 0;

void display_options(){
  printf("1. Add item to warehouse\n");
  printf("2. Remove item from warehouse\n");
  printf("3. Display all items in warehouse\n");
  printf("4. Update item price in warehouse\n");
  printf("5. Exit\n");
}

void add_item(){
  Item new_item;
  printf("Enter item name: ");
  scanf("%s", new_item.item_name);
  printf("Enter item quantity: ");
  scanf("%d", &new_item.quantity);
  printf("Enter item price: ");
  scanf("%f", &new_item.price);
  warehouse[num_items] = new_item;
  num_items++;
  printf("Item added successfully!\n");
}

void remove_item(){
  char item_name[20];
  printf("Enter item name to remove: ");
  scanf("%s", item_name);
  int i;
  for(i=0; i<num_items; i++){
    if(strcmp(warehouse[i].item_name, item_name) == 0){
      int j;
      for(j=i; j<num_items-1; j++)
        warehouse[j] = warehouse[j+1];
      num_items--;
      printf("Item removed successfully!\n");
      return;
    }
  }
  printf("Item not found in warehouse.\n");
}

void display_items(){
  printf("\n%-20s|%10s|%10s\n", "ITEM NAME", "QUANTITY", "PRICE");
  int i;
  for(i=0; i<num_items; i++)
    printf("%-20s|%10d|%10.2f\n", warehouse[i].item_name, warehouse[i].quantity, warehouse[i].price);
  printf("\n");
}

void update_price(){
  char item_name[20];
  printf("Enter item name to update price: ");
  scanf("%s", item_name);
  int i;
  for(i=0; i<num_items; i++){
    if(strcmp(warehouse[i].item_name, item_name) == 0){
      printf("Current price: %.2f\n", warehouse[i].price);
      printf("Enter new price: ");
      scanf("%f", &warehouse[i].price);
      printf("Price updated successfully!\n");
      return;
    }
  }
  printf("Item not found in warehouse.\n");
}

int main(){
  int choice;
  do{
    display_options();
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        add_item();
        break;
      case 2:
        remove_item();
        break;
      case 3:
        display_items();
        break;
      case 4:
        update_price();
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }while(choice != 5);

  return 0;
}
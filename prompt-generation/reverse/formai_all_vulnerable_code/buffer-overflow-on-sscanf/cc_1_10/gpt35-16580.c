//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structures to hold information about each item in our warehouse
struct Item {
  char* name;
  int quantity;
  float price;
};

//Define a list of items in the warehouse
struct Item inventory[] = {
  { "Widget", 100, 1.50 },
  { "Doodad", 50, 2.25 },
  { "Gizmo", 75, 3.00 }
};

//Define a function to update an item's quantity in the warehouse
void update_item(char* name, int new_quantity) {
  int i;
  for(i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
    if(strcmp(inventory[i].name, name) == 0) {
      inventory[i].quantity = new_quantity;
      printf("Updated %s - new quantity is %d\n", name, new_quantity);
      return;
    }
  }
  printf("Could not find item %s in inventory\n", name);
}

//Define a function to print out the current inventory
void print_inventory() {
  int i;
  printf("Warehouse Inventory:\n");
  printf("%-10s |%-10s |%-10s\n", "Name", "Quantity", "Price");
  for(i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
    printf("%-10s |%-10d |$%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

int main() {
  char command[100];
  char name[100];
  int quantity;
  while(1) {
    //Print out the current inventory and ask the user for a command
    print_inventory();
    printf("Enter a command (update <item> <quantity>, quit):\n");
    fgets(command, sizeof(command), stdin);
    //Parse the command
    if(strcmp(command, "quit\n") == 0) {
      printf("Goodbye!\n");
      break;
    } else if(sscanf(command, "update %s %d", name, &quantity) == 2) {
      update_item(name, quantity);
    } else {
      printf("Invalid command\n");
    }
  }
  return 0;
}
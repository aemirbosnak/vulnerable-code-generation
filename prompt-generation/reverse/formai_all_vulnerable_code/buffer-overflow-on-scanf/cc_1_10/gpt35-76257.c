//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: artistic
// Welcome to our Warehouse Management System!
// This program allows you to input, store, and retrieve information about items in your warehouse.

#include <stdio.h>
#include <string.h>

// Define a struct to store information about each item in the warehouse
typedef struct {
  int itemNumber;
  char itemName[50];
  float price;
  int quantity;
} Item;

// Declare an array of type Item to store all items in the warehouse
Item warehouse[100];

// Define a function to add a new item to the warehouse
void addNewItem(int index) {
  printf("Enter Item Number: ");
  scanf("%d", &warehouse[index].itemNumber);
  printf("Enter Item Name: ");
  scanf("%s", warehouse[index].itemName);
  printf("Enter Item Price: ");
  scanf("%f", &warehouse[index].price);
  printf("Enter Item Quantity: ");
  scanf("%d", &warehouse[index].quantity);

  printf("\nNew item added successfully!\n");
}

// Define a function to display all items currently in the warehouse
void displayItems(int count) {
  printf("\n---------- Current Inventory ----------\n");
  printf("%-15s %-25s %-10s %-10s\n", "Item Number", "Item Name", "Price", "Quantity");
  for (int i = 0; i < count; i++) {
    printf("%-15d %-25s $%-9.2f %-10d\n", warehouse[i].itemNumber, warehouse[i].itemName, warehouse[i].price, warehouse[i].quantity);
  }
  printf("---------------------------------------\n");
}

// Define a function to search for an item in the warehouse by item name
void searchByName(int count) {
  char searchName[50];

  printf("Enter Item Name to search for: ");
  scanf("%s", searchName);

  for (int i = 0; i < count; i++) {
    if (strcmp(warehouse[i].itemName, searchName) == 0) {
      printf("\n---------- Search Results ----------\n");
      printf("%-15s %-25s %-10s %-10s\n", "Item Number", "Item Name", "Price", "Quantity");
      printf("%-15d %-25s $%-9.2f %-10d\n", warehouse[i].itemNumber, warehouse[i].itemName, warehouse[i].price, warehouse[i].quantity);
      printf("------------------------------------\n");
      return;
    }
  }

  printf("\nItem not found in warehouse.\n");
}

int main() {
  int option;
  int itemCount = 0;

  printf("Welcome to the Warehouse Management System!\n\n");

  do {
    printf("Please select an option:\n");
    printf("1. Add New Item\n");
    printf("2. Display All Items\n");
    printf("3. Search for Item by Name\n");
    printf("4. Exit\n");
    printf("Option: ");
    scanf("%d", &option);

    if (option == 1) {
      addNewItem(itemCount);
      itemCount++;
    } else if (option == 2) {
      displayItems(itemCount);
    } else if (option == 3) {
      searchByName(itemCount);
    } else if (option == 4) {
      printf("\nThank you for using the Warehouse Management System!\n");
    } else {
      printf("\nInvalid option selected. Please try again.\n");
    }
  } while (option != 4);

  return 0;
}
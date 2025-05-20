//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000 // Maximum number of items that can be stored in the warehouse

typedef struct WarehouseItem {
  char name[50]; // Name of the item
  int quantity; // Number of items in the warehouse
} WarehouseItem;

WarehouseItem items[MAX_ITEMS]; // Array to store warehouse items
int numItems = 0; // Number of items currently in the warehouse

void addNewItem(char name[], int quantity);
void displayAllItems();
void displayItem(char name[]);
void removeItem(char name[]);
void updateItem(char name[]);
void saveToFile(char filename[]);
void readFromFile(char filename[]);

int main() {
  int choice;
  char name[50];
  int quantity;
  char filename[100];

  // Load data from file
  readFromFile("warehouse.txt");

  do {
    // Display menu
    printf("\n1. Add a new item\n");
    printf("2. Display all items\n");
    printf("3. Display an item\n");
    printf("4. Remove an item\n");
    printf("5. Update an item\n");
    printf("6. Save data to file\n");
    printf("7. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // Add a new item
        printf("\nEnter item name: ");
        scanf("%s", name);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        addNewItem(name, quantity);
        break;
      case 2: // Display all items
        displayAllItems();
        break;
      case 3: // Display an item
        printf("\nEnter item name: ");
        scanf("%s", name);
        displayItem(name);
        break;
      case 4: // Remove an item
        printf("\nEnter item name: ");
        scanf("%s", name);
        removeItem(name);
        break;
      case 5: // Update an item
        printf("\nEnter item name: ");
        scanf("%s", name);
        updateItem(name);
        break;
      case 6: // Save data to file
        printf("\nEnter filename to save to: ");
        scanf("%s", filename);
        saveToFile(filename);
        break;
      case 7: // Exit
        printf("\nExiting program...\n");
        break;
      default: // Invalid choice
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 7);

  // Save data to file before exiting
  saveToFile("warehouse.txt");

  return 0;
}

// Add a new item to the warehouse
void addNewItem(char name[], int quantity) {
  // Check if item already exists
  for(int i = 0; i < numItems; i++) {
    if(strcmp(name, items[i].name) == 0) {
      printf("\nItem '%s' already exists in the warehouse.\n", name);
      return;
    }
  }

  // Add new item
  if(numItems < MAX_ITEMS) {
    strcpy(items[numItems].name, name);
    items[numItems].quantity = quantity;
    numItems++;
    printf("\nItem '%s' added to the warehouse.\n", name);
  } else {
    printf("\nWarehouse is full. Cannot add item.\n");
  }
}

// Display all items in the warehouse
void displayAllItems() {
  if(numItems == 0) {
    printf("\nWarehouse is empty.\n");
  } else {
    printf("\nWarehouse items:\n");
    printf("-----------------\n");
    for(int i = 0; i < numItems; i++) {
      printf("%s: %d\n", items[i].name, items[i].quantity);
    }
  }
}

// Display an item in the warehouse
void displayItem(char name[]) {
  int found = 0;

  for(int i = 0; i < numItems; i++) {
    if(strcmp(name, items[i].name) == 0) {
      printf("\nItem: %s\n", name);
      printf("Quantity: %d\n", items[i].quantity);
      found = 1;
      break;
    }
  }

  if(!found) {
    printf("\nItem '%s' not found in the warehouse.\n", name);
  }
}

// Remove an item from the warehouse
void removeItem(char name[]) {
  int found = 0;

  for(int i = 0; i < numItems; i++) {
    if(strcmp(name, items[i].name) == 0) {
      printf("\nRemoved item: %s\n", name);
      found = 1;

      // Shift elements to remove item from array
      for(int j = i; j < numItems - 1; j++) {
        strcpy(items[j].name, items[j+1].name);
        items[j].quantity = items[j+1].quantity;
      }

      numItems--;
      break;
    }
  }

  if(!found) {
    printf("\nItem '%s' not found in the warehouse.\n", name);
  }
}

// Update an item in the warehouse
void updateItem(char name[]) {
  int found = 0;
  int quantity;

  for(int i = 0; i < numItems; i++) {
    if(strcmp(name, items[i].name) == 0) {
      printf("\nEnter new quantity: ");
      scanf("%d", &quantity);
      items[i].quantity = quantity;
      printf("\nItem '%s' updated.\n", name);
      found = 1;
      break;
    }
  }

  if(!found) {
    printf("\nItem '%s' not found in the warehouse.\n", name);
  }
}

// Save warehouse data to file
void saveToFile(char filename[]) {
  FILE *fp;
  fp = fopen(filename, "w");

  // Write number of items to file
  fprintf(fp, "%d\n", numItems);

  // Write each item to file
  for(int i = 0; i < numItems; i++) {
    fprintf(fp, "%s %d\n", items[i].name, items[i].quantity);
  }

  fclose(fp);

  printf("\nWarehouse data saved to file '%s'.\n", filename);
}

// Load warehouse data from file
void readFromFile(char filename[]) {
  FILE *fp;
  fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("\nNo data file found. Creating new file.\n");
    fp = fopen(filename, "w");
    fclose(fp);
    return;
  }

  // Read number of items from file
  fscanf(fp, "%d", &numItems);

  // Read each item from file
  for(int i = 0; i < numItems; i++) {
    fscanf(fp, "%s %d", items[i].name, &items[i].quantity);
  }

  fclose(fp);

  printf("\nWarehouse data loaded from file '%s'.\n", filename);
}
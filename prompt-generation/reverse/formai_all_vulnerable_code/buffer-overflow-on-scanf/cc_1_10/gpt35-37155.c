//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

// Structure for storing medicine information
struct Medicine {
  char name[50];
  int quantity;
  float price;
};

// Function to add a new medicine to the inventory
int addMedicine(struct Medicine inventory[], int count) {
  if (count >= MAX_MEDICINES) {
    printf("Inventory is full. Cannot add more medicines.\n");
    return count;
  }

  struct Medicine newMedicine;
  printf("Enter medicine name: ");
  scanf("%s", newMedicine.name);
  printf("Enter quantity: ");
  scanf("%d", &newMedicine.quantity);
  printf("Enter price: ");
  scanf("%f", &newMedicine.price);

  inventory[count] = newMedicine;
  printf("Medicine added successfully.\n");

  return count + 1;
}

// Function to search for a medicine by name
void searchMedicine(struct Medicine inventory[], int count) {
  char searchName[50];
  printf("Enter medicine name to search: ");
  scanf("%s", searchName);

  int found = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(inventory[i].name, searchName) == 0) {
      printf("Medicine found: %s, Quantity: %d, Price: %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Medicine not found.\n");
  }
}

// Function to update medicine quantity
void updateQuantity(struct Medicine inventory[], int count) {
  char updateName[50];
  printf("Enter medicine name to update: ");
  scanf("%s", updateName);

  int found = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(inventory[i].name, updateName) == 0) {
      printf("Enter new quantity: ");
      scanf("%d", &inventory[i].quantity);
      printf("Quantity updated successfully.\n");
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Medicine not found.\n");
  }
}

// Function to calculate total value of inventory
float inventoryValue(struct Medicine inventory[], int count) {
  float value = 0;
  for (int i = 0; i < count; i++) {
    value += inventory[i].price * inventory[i].quantity;
  }
  return value;
}

// Function to display inventory information
void displayInventory(struct Medicine inventory[], int count) {
  printf("Medicine Inventory:\n");
  for (int i = 0; i < count; i++) {
    printf("%s\t%d\t%f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
  printf("Total Inventory Value: %f\n", inventoryValue(inventory, count));
}

int main() {
  struct Medicine inventory[MAX_MEDICINES];
  int count = 0;
  int option;

  do {
    printf("\nMedical Store Management System\n");
    printf("1. Add new medicine\n");
    printf("2. Search for a medicine\n");
    printf("3. Update medicine quantity\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");

    printf("Enter your choice (1-5): ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        count = addMedicine(inventory, count);
        break;
      case 2:
        searchMedicine(inventory, count);
        break;
      case 3:
        updateQuantity(inventory, count);
        break;
      case 4:
        displayInventory(inventory, count);
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while(option != 5);

  return 0;
}
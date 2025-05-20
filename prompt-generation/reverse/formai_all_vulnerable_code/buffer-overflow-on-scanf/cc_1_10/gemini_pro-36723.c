//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
  char name[50];
  char company[50];
  int quantity;
  float price;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *count) {
  printf("Enter medicine name: ");
  scanf(" %s", inventory[*count].name);
  printf("Enter company name: ");
  scanf(" %s", inventory[*count].company);
  printf("Enter quantity: ");
  scanf("%d", &inventory[*count].quantity);
  printf("Enter price: ");
  scanf("%f", &inventory[*count].price);
  (*count)++;
}

// Function to search for a medicine in the inventory
medicine* search_medicine(medicine *inventory, int count, char *name) {
  for (int i = 0; i < count; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      return &inventory[i];
    }
  }
  return NULL;
}

// Function to sell a medicine from the inventory
void sell_medicine(medicine *inventory, int *count, char *name, int quantity) {
  medicine *med = search_medicine(inventory, *count, name);
  if (med != NULL) {
    if (med->quantity >= quantity) {
      med->quantity -= quantity;
      printf("Medicine sold successfully.\n");
    } else {
      printf("Insufficient quantity.\n");
    }
  } else {
    printf("Medicine not found.\n");
  }
}

// Function to print the inventory
void print_inventory(medicine *inventory, int count) {
  printf("Medicine Inventory:\n");
  printf("--------------------\n");
  for (int i = 0; i < count; i++) {
    printf("%s\t%s\t%d\t%.2f\n", inventory[i].name, inventory[i].company, inventory[i].quantity,
           inventory[i].price);
  }
}

// Driver code
int main() {
  // Create an array of medicines
  medicine inventory[100];

  // Initialize the count of medicines to 0
  int count = 0;

  // Add some medicines to the inventory
  add_medicine(inventory, &count);
  add_medicine(inventory, &count);
  add_medicine(inventory, &count);

  // Print the inventory
  print_inventory(inventory, count);

  // Search for a medicine
  char name[50];
  printf("Enter medicine name to search: ");
  scanf(" %s", name);
  medicine *med = search_medicine(inventory, count, name);
  if (med != NULL) {
    printf("Medicine found:\n");
    printf("Name: %s\n", med->name);
    printf("Company: %s\n", med->company);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
  } else {
    printf("Medicine not found.\n");
  }

  // Sell a medicine
  printf("Enter medicine name to sell: ");
  scanf(" %s", name);
  int quantity;
  printf("Enter quantity to sell: ");
  scanf("%d", &quantity);
  sell_medicine(inventory, &count, name, quantity);

  // Print the inventory again
  print_inventory(inventory, count);

  return 0;
}
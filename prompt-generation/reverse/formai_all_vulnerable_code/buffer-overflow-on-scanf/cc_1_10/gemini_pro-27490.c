//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of each medicine
typedef struct medicine {
  int id;
  char name[50];
  float price;
  int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *size) {
  // Increase the size of the inventory array by 1
  *size = *size + 1;

  // Get the details of the new medicine
  printf("Enter the ID of the new medicine: ");
  scanf("%d", &inventory[*size - 1].id);
  printf("Enter the name of the new medicine: ");
  scanf("%s", inventory[*size - 1].name);
  printf("Enter the price of the new medicine: ");
  scanf("%f", &inventory[*size - 1].price);
  printf("Enter the quantity of the new medicine: ");
  scanf("%d", &inventory[*size - 1].quantity);
}

// Function to display the inventory of medicines
void displayInventory(medicine *inventory, int size) {
  printf("\n\nInventory of Medicines:\n\n");
  printf("ID\tName\tPrice\tQuantity\n");
  for (int i = 0; i < size; i++) {
    printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price,
           inventory[i].quantity);
  }
}

// Function to search for a medicine by its ID
medicine *searchMedicineById(medicine *inventory, int size, int id) {
  for (int i = 0; i < size; i++) {
    if (inventory[i].id == id) {
      return &inventory[i];
    }
  }
  return NULL;
}

// Function to sell a medicine
void sellMedicine(medicine *inventory, int *size) {
  int id, quantity;
  printf("Enter the ID of the medicine to be sold: ");
  scanf("%d", &id);
  printf("Enter the quantity to be sold: ");
  scanf("%d", &quantity);

  // Search for the medicine in the inventory
  medicine *med = searchMedicineById(inventory, *size, id);
  if (med == NULL) {
    printf("Medicine not found!");
    return;
  }

  // Check if the quantity to be sold is available
  if (med->quantity < quantity) {
    printf("Insufficient quantity!");
    return;
  }

  // Update the quantity of the medicine
  med->quantity = med->quantity - quantity;

  // Calculate the total price of the sold medicines
  float totalPrice = quantity * med->price;

  // Print the invoice
  printf("\n\nInvoice:\n\n");
  printf("Medicine Name: %s\n", med->name);
  printf("Quantity Sold: %d\n", quantity);
  printf("Total Price: %.2f\n", totalPrice);
}

// Main function
int main() {
  // Declare an array of structures to store the inventory of medicines
  medicine inventory[100];

  // Initialize the size of the inventory to 0
  int size = 0;

  // Add some sample medicines to the inventory
  addMedicine(inventory, &size);
  addMedicine(inventory, &size);
  addMedicine(inventory, &size);

  // Display the inventory of medicines
  displayInventory(inventory, size);

  // Search for a medicine by its ID
  int id;
  printf("\nEnter the ID of the medicine to be searched: ");
  scanf("%d", &id);
  medicine *med = searchMedicineById(inventory, size, id);
  if (med == NULL) {
    printf("Medicine not found!");
  } else {
    printf("\nMedicine Details:\n\n");
    printf("ID: %d\n", med->id);
    printf("Name: %s\n", med->name);
    printf("Price: %.2f\n", med->price);
    printf("Quantity: %d\n", med->quantity);
  }

  // Sell a medicine
  sellMedicine(inventory, &size);

  return 0;
}
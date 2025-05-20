//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
// Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data types
typedef struct {
  char name[50];
  char address[50];
  int quantity;
  float price;
} medicine;

// Function to add medicine
void addMedicine(medicine *medicine) {
  printf("Enter the name of the medicine: ");
  scanf("%s", medicine->name);
  printf("Enter the address of the medicine: ");
  scanf("%s", medicine->address);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &medicine->quantity);
  printf("Enter the price of the medicine: ");
  scanf("%f", &medicine->price);
}

// Function to display medicine
void displayMedicine(medicine *medicine) {
  printf("Name: %s\n", medicine->name);
  printf("Address: %s\n", medicine->address);
  printf("Quantity: %d\n", medicine->quantity);
  printf("Price: %.2f\n", medicine->price);
}

// Function to update medicine
void updateMedicine(medicine *medicine) {
  printf("Enter the name of the medicine: ");
  scanf("%s", medicine->name);
  printf("Enter the address of the medicine: ");
  scanf("%s", medicine->address);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &medicine->quantity);
  printf("Enter the price of the medicine: ");
  scanf("%f", &medicine->price);
}

// Function to delete medicine
void deleteMedicine(medicine *medicine) {
  printf("Enter the name of the medicine: ");
  scanf("%s", medicine->name);
  printf("Enter the address of the medicine: ");
  scanf("%s", medicine->address);
}

int main() {
  medicine medicine[50];
  int choice;

  // Add medicine
  printf("Enter 1 to add medicine: ");
  scanf("%d", &choice);
  if (choice == 1) {
    addMedicine(medicine);
  }

  // Display medicine
  printf("Enter 2 to display medicine: ");
  scanf("%d", &choice);
  if (choice == 2) {
    displayMedicine(medicine);
  }

  // Update medicine
  printf("Enter 3 to update medicine: ");
  scanf("%d", &choice);
  if (choice == 3) {
    updateMedicine(medicine);
  }

  // Delete medicine
  printf("Enter 4 to delete medicine: ");
  scanf("%d", &choice);
  if (choice == 4) {
    deleteMedicine(medicine);
  }

  return 0;
}
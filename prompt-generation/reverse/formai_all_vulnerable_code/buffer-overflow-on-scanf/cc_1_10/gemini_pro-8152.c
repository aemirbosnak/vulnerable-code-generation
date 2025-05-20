//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the inventory
void addMedicine(Medicine *inventory, int *size) {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*size].name);
    printf("Enter the brand of the medicine: ");
    scanf("%s", inventory[*size].brand);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*size].quantity);

    // Increment the size of the inventory
    (*size)++;
}

// Function to search for a medicine in the inventory
Medicine *searchMedicine(Medicine *inventory, int size, char *name) {
    // Linear search for the medicine
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }

    // Medicine not found
    return NULL;
}

// Function to sell a medicine from the inventory
void sellMedicine(Medicine *inventory, int *size, char *name, int quantity) {
    // Search for the medicine in the inventory
    Medicine *medicine = searchMedicine(inventory, *size, name);

    // If medicine is found, update the quantity
    if (medicine != NULL) {
        if (medicine->quantity >= quantity) {
            medicine->quantity -= quantity;
        } else {
            printf("Insufficient quantity of the medicine.\n");
        }
    } else {
        printf("Medicine not found.\n");
    }
}

// Function to print the inventory
void printInventory(Medicine *inventory, int size) {
    // Print the header
    printf("Name\tBrand\tPrice\tQuantity\n");

    // Print the details of each medicine
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t%.2f\t%d\n", inventory[i].name, inventory[i].brand, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Medicine inventory[100];
    int size = 0;

    // Add some sample medicines to the inventory
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);

    // Search for a medicine in the inventory
    Medicine *medicine = searchMedicine(inventory, size, "Medicine 1");

    // If medicine is found, print its details
    if (medicine != NULL) {
        printf("Medicine found:\n");
        printf("Name: %s\n", medicine->name);
        printf("Brand: %s\n", medicine->brand);
        printf("Price: %.2f\n", medicine->price);
        printf("Quantity: %d\n", medicine->quantity);
    } else {
        printf("Medicine not found.\n");
    }

    // Sell a medicine from the inventory
    sellMedicine(inventory, &size, "Medicine 1", 1);

    // Print the updated inventory
    printf("Updated inventory:\n");
    printInventory(inventory, size);

    return 0;
}
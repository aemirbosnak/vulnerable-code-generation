//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the inventory
void addMedicine(Medicine *inventory, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*size].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

// Function to search for a medicine in the inventory
Medicine *searchMedicine(Medicine *inventory, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Function to sell a medicine from the inventory
void sellMedicine(Medicine *inventory, int *size, char *name, int quantity) {
    Medicine *medicine = searchMedicine(inventory, *size, name);
    if (medicine == NULL) {
        printf("Medicine not found in the inventory.\n");
        return;
    }
    if (medicine->quantity < quantity) {
        printf("Insufficient quantity of the medicine in the inventory.\n");
        return;
    }
    medicine->quantity -= quantity;
    printf("Medicine sold successfully.\n");
}

// Function to display the inventory
void displayInventory(Medicine *inventory, int size) {
    printf("\nInventory:\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-10s |\n", "Sr. No.", "Medicine Name", "Price", "Quantity");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %-5d | %-20s | %-10.2f | %-10d |\n", i + 1, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Initialize the inventory with a size of 10
    Medicine inventory[10];
    int size = 0;

    // Add some sample medicines to the inventory
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);

    // Display the inventory
    displayInventory(inventory, size);

    // Search for a medicine in the inventory
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);
    Medicine *medicine = searchMedicine(inventory, size, name);
    if (medicine == NULL) {
        printf("Medicine not found in the inventory.\n");
    } else {
        printf("Medicine found:\n");
        printf("Name: %s\n", medicine->name);
        printf("Price: %.2f\n", medicine->price);
        printf("Quantity: %d\n", medicine->quantity);
    }

    // Sell a medicine from the inventory
    printf("Enter the name of the medicine to sell: ");
    scanf("%s", name);
    int quantity;
    printf("Enter the quantity of the medicine to sell: ");
    scanf("%d", &quantity);
    sellMedicine(inventory, &size, name, quantity);

    // Display the inventory again
    displayInventory(inventory, size);

    return 0;
}
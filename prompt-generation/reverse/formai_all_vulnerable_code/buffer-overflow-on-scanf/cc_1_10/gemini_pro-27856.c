//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*size].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

// Function to search for a medicine in the inventory
int searchMedicine(medicine *inventory, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of a medicine in the inventory
void updateQuantity(medicine *inventory, int size, char *name, int quantity) {
    int index = searchMedicine(inventory, size, name);
    if (index != -1) {
        inventory[index].quantity += quantity;
    } else {
        printf("Medicine not found!\n");
    }
}

// Function to display the inventory
void displayInventory(medicine *inventory, int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int size = 0;

    // Add some medicines to the inventory
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);

    // Display the inventory
    displayInventory(inventory, size);

    // Search for a medicine in the inventory
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);
    int index = searchMedicine(inventory, size, name);
    if (index != -1) {
        printf("Medicine found!\n");
    } else {
        printf("Medicine not found!\n");
    }

    // Update the quantity of a medicine in the inventory
    printf("Enter the name of the medicine you want to update the quantity of: ");
    scanf("%s", name);
    int quantity;
    printf("Enter the new quantity: ");
    scanf("%d", &quantity);
    updateQuantity(inventory, size, name, quantity);

    // Display the updated inventory
    displayInventory(inventory, size);

    return 0;
}
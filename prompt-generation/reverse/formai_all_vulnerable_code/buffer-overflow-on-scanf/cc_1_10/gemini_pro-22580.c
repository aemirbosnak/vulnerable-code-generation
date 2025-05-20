//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *size) {
    printf("Enter medicine name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter medicine brand: ");
    scanf("%s", inventory[*size].brand);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter medicine quantity: ");
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

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int size, char *name, int quantity) {
    int index = searchMedicine(inventory, size, name);
    if (index == -1) {
        printf("Medicine not found!\n");
    } else if (inventory[index].quantity < quantity) {
        printf("Insufficient quantity!\n");
    } else {
        inventory[index].quantity -= quantity;
        printf("Medicine sold successfully!\n");
    }
}

// Function to print the inventory
void printInventory(medicine *inventory, int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %s %.2f %d\n", inventory[i].name, inventory[i].brand, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int size = 0;

    // Add some sample medicines to the inventory
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);
    addMedicine(inventory, &size);

    // Print the inventory
    printInventory(inventory, size);

    // Search for a medicine in the inventory
    char name[50];
    printf("Enter medicine name to search for: ");
    scanf("%s", name);
    int index = searchMedicine(inventory, size, name);
    if (index == -1) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine found: %s %s %.2f %d\n", inventory[index].name, inventory[index].brand, inventory[index].price, inventory[index].quantity);
    }

    // Sell a medicine from the inventory
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    int quantity;
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    sellMedicine(inventory, size, name, quantity);

    // Print the inventory
    printInventory(inventory, size);

    return 0;
}
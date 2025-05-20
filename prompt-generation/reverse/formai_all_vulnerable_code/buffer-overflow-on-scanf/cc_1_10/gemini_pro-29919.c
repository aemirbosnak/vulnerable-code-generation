//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the store
void addMedicine(Medicine *store, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*size].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*size].quantity);

    (*size)++;
}

// Function to search for a medicine in the store
int searchMedicine(Medicine *store, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(store[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to sell a medicine from the store
void sellMedicine(Medicine *store, int size, char *name, int quantity) {
    int index = searchMedicine(store, size, name);

    if (index == -1) {
        printf("Medicine not found!\n");
    } else if (store[index].quantity < quantity) {
        printf("Insufficient quantity!\n");
    } else {
        store[index].quantity -= quantity;
        printf("Medicine sold successfully!\n");
    }
}

// Function to print the inventory of the store
void printInventory(Medicine *store, int size) {
    printf("Inventory:\n");
    printf("--------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-20s %-10.2f %-10d\n", store[i].name, store[i].price, store[i].quantity);
    }
    printf("--------------------------------------------------------------------------\n");
}

int main() {
    // Create an array of medicines to store the inventory
    Medicine store[100];

    // Initialize the size of the array to 0
    int size = 0;

    // Add some sample medicines to the store
    addMedicine(store, &size);
    addMedicine(store, &size);
    addMedicine(store, &size);

    // Print the inventory of the store
    printInventory(store, size);

    // Search for a medicine in the store
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);

    int index = searchMedicine(store, size, name);

    if (index == -1) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine found!\n");
        printf("Name: %s\n", store[index].name);
        printf("Price: %.2f\n", store[index].price);
        printf("Quantity: %d\n", store[index].quantity);
    }

    // Sell a medicine from the store
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);
    printf("Enter the quantity you want to sell: ");
    int quantity;
    scanf("%d", &quantity);

    sellMedicine(store, size, name, quantity);

    // Print the inventory of the store
    printInventory(store, size);

    return 0;
}
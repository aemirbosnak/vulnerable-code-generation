//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
struct Medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
};

// Function to add a medicine to the inventory
void addMedicine(struct Medicine *inventory, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*size].name);

    printf("Enter the name of the company: ");
    scanf("%s", inventory[*size].company);

    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*size].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*size].quantity);

    (*size)++;
}

// Function to search for a medicine in the inventory
int searchMedicine(struct Medicine *inventory, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to sell a medicine
void sellMedicine(struct Medicine *inventory, int *size, char *name, int quantity) {
    int index = searchMedicine(inventory, *size, name);

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    if (inventory[index].quantity < quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    inventory[index].quantity -= quantity;
}

// Function to display the inventory
void displayInventory(struct Medicine *inventory, int size) {
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Price", "Quantity");

    for (int i = 0; i < size; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].company, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Create an inventory of medicines
    struct Medicine inventory[100];
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

    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found:\n");
        printf("Name: %s\n", inventory[index].name);
        printf("Company: %s\n", inventory[index].company);
        printf("Price: %.2f\n", inventory[index].price);
        printf("Quantity: %d\n", inventory[index].quantity);
    }

    // Sell a medicine
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);
    int quantity;
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);
    sellMedicine(inventory, &size, name, quantity);

    // Display the updated inventory
    displayInventory(inventory, size);

    return 0;
}
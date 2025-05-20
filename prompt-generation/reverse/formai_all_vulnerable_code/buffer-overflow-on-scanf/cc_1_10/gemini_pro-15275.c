//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
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
void addMedicine(medicine *inventory, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*count].quantity);
    (*count)++;
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int *count) {
    char name[50];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
                return;
            } else {
                printf("Insufficient quantity of medicine in stock!\n");
                return;
            }
        }
    }
    printf("Medicine not found in inventory!\n");
}

// Function to display the inventory
void displayInventory(medicine *inventory, int count) {
    printf("Medicine Inventory:\n");
    printf("---------------------\n");
    printf("Name\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Allocate memory for the inventory
    medicine *inventory = malloc(100 * sizeof(medicine));

    // Initialize the inventory count
    int count = 0;

    // Display the main menu
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("------------------------------\n");
        printf("1. Add a new medicine\n");
        printf("2. Sell a medicine\n");
        printf("3. Display the inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                sellMedicine(inventory, &count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
        }
    } while (choice != 4);

    // Free the allocated memory
    free(inventory);

    return 0;
}
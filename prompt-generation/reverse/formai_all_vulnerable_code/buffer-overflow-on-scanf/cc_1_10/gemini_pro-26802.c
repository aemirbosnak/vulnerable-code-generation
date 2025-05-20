//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *numMedicines) {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*numMedicines].name);
    printf("Enter the manufacturer of the medicine: ");
    scanf("%s", inventory[*numMedicines].manufacturer);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*numMedicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*numMedicines].quantity);

    // Increment the number of medicines in the inventory
    (*numMedicines)++;
}

// Function to search for a medicine in the inventory
void searchMedicine(medicine *inventory, int numMedicines) {
    // Get the name of the medicine to search for
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);

    // Search for the medicine in the inventory
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Print the details of the medicine
            printf("Name: %s\n", inventory[i].name);
            printf("Manufacturer: %s\n", inventory[i].manufacturer);
            printf("Price: %f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int *numMedicines) {
    // Get the name of the medicine to sell
    char name[50];
    printf("Enter the name of the medicine to sell: ");
    scanf("%s", name);

    // Search for the medicine in the inventory
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Get the quantity of the medicine to sell
            int quantity;
            printf("Enter the quantity of the medicine to sell: ");
            scanf("%d", &quantity);

            // If the quantity to sell is greater than the quantity in stock, print an error message
            if (quantity > inventory[i].quantity) {
                printf("Insufficient stock.\n");
            } else {
                // Deduct the quantity sold from the quantity in stock
                inventory[i].quantity -= quantity;

                // If the quantity in stock is now 0, remove the medicine from the inventory
                if (inventory[i].quantity == 0) {
                    for (int j = i; j < *numMedicines - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }
                    (*numMedicines)--;
                }

                // Print a confirmation message
                printf("Medicine sold successfully.\n");
            }
            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to print the inventory
void printInventory(medicine *inventory, int numMedicines) {
    // Print the header
    printf("Name\tManufacturer\tPrice\tQuantity\n");

    // Print the details of each medicine
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%s\t%.2f\t%d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Create an array to store the inventory
    medicine inventory[100];

    // Initialize the number of medicines in the inventory to 0
    int numMedicines = 0;

    // Get the user's choice
    int choice;
    do {
        // Print the menu
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Sell a medicine\n");
        printf("4. Print the inventory\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addMedicine(inventory, &numMedicines);
                break;
            case 2:
                searchMedicine(inventory, numMedicines);
                break;
            case 3:
                sellMedicine(inventory, &numMedicines);
                break;
            case 4:
                printInventory(inventory, numMedicines);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
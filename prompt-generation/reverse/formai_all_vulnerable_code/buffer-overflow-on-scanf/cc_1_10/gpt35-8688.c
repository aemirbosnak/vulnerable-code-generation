//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold medicine data
struct Medicine {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

// Function to add a new medicine to inventory
void addMedicine(struct Medicine *inventory, int *numMedicines) {
    struct Medicine newMedicine;

    printf("Enter medicine name: ");
    fgets(newMedicine.name, 50, stdin);
    printf("Enter manufacturer: ");
    fgets(newMedicine.manufacturer, 50, stdin);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);

    newMedicine.id = *numMedicines + 1; // Set unique ID

    inventory[*numMedicines] = newMedicine; // Add to inventory
    (*numMedicines)++; // Increment number of medicines
}

// Function to search for medicine by name
void searchMedicine(struct Medicine *inventory, int numMedicines) {
    char searchName[50];
    int found = 0;

    printf("Enter medicine name to search: ");
    fgets(searchName, 50, stdin);

    for (int i = 0; i < numMedicines; i++) { // Search through inventory
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Medicine found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s", inventory[i].name);
            printf("Manufacturer: %s", inventory[i].manufacturer);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to sell medicine
void sellMedicine(struct Medicine *inventory, int numMedicines) {
    int sellID, quantitySold;
    int found = 0;

    printf("Enter medicine ID to sell: ");
    scanf("%d", &sellID);

    for (int i = 0; i < numMedicines; i++) { // Search through inventory
        if (inventory[i].id == sellID) {
            found = 1;

            printf("Enter quantity to sell: ");
            scanf("%d", &quantitySold);

            if (quantitySold > inventory[i].quantity) {
                printf("Not enough stock available.\n");
            } else {
                inventory[i].quantity -= quantitySold;
                printf("Total amount due: %.2f\n", inventory[i].price * quantitySold);
            }
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Main function
int main() {
    struct Medicine inventory[100]; // Inventory array
    int numMedicines = 0; // Number of medicines in inventory
    int choice;

    do { // Menu loop
        printf("\n\n");
        printf("----------- Medical Store Management System -----------\n\n");
        printf("1. Add new medicine to inventory\n");
        printf("2. Search for medicine by name\n");
        printf("3. Sell medicine\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                addMedicine(inventory, &numMedicines);
                break;
            case 2:
                searchMedicine(inventory, numMedicines);
                break;
            case 3:
                sellMedicine(inventory, numMedicines);
                break;
            case 0:
                printf("Exiting application.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
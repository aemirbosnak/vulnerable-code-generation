//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine item
typedef struct MedicineItem {
    char name[50];
    char dosage[50];
    int quantity;
    double price;
} MedicineItem;

// Define the function to add a new medicine item
void addMedicineItem(MedicineItem **items, int *itemsCount) {
    // Allocate memory for a new item
    MedicineItem *newItem = (MedicineItem *)malloc(sizeof(MedicineItem));

    // Get the item name, dosage, quantity, and price from the user
    printf("Enter the name of the medicine item: ");
    scanf("%s", newItem->name);

    printf("Enter the dosage of the medicine item: ");
    scanf("%s", newItem->dosage);

    printf("Enter the quantity of the medicine item: ");
    scanf("%d", &newItem->quantity);

    printf("Enter the price of the medicine item: ");
    scanf("%lf", &newItem->price);

    // Add the item to the array
    *items = realloc(*items, (*itemsCount + 1) * sizeof(MedicineItem));
    (*itemsCount)++;
    *items = items;

    // Print a confirmation message
    printf("Item added successfully.\n");
}

// Define the function to search for a medicine item
void searchMedicineItem(MedicineItem *items, int itemsCount) {
    // Get the item name from the user
    char searchItem[50];
    printf("Enter the name of the medicine item: ");
    scanf("%s", searchItem);

    // Search for the item
    int found = 0;
    for (int i = 0; i < itemsCount; i++) {
        if (strcmp(items[i].name, searchItem) == 0) {
            // Print the item information
            printf("Name: %s\n", items[i].name);
            printf("Dosage: %s\n", items[i].dosage);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2lf\n", items[i].price);
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define the function to update the quantity of a medicine item
void updateMedicineItemQuantity(MedicineItem *items, int itemsCount) {
    // Get the item name from the user
    char updateItem[50];
    printf("Enter the name of the medicine item: ");
    scanf("%s", updateItem);

    // Search for the item
    int found = 0;
    for (int i = 0; i < itemsCount; i++) {
        if (strcmp(items[i].name, updateItem) == 0) {
            // Get the new quantity from the user
            int newQuantity;
            printf("Enter the new quantity of the medicine item: ");
            scanf("%d", &newQuantity);

            // Update the item quantity
            items[i].quantity = newQuantity;

            // Print a confirmation message
            printf("Quantity updated successfully.\n");
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define the function to delete a medicine item
void deleteMedicineItem(MedicineItem *items, int *itemsCount) {
    // Get the item name from the user
    char deleteItem[50];
    printf("Enter the name of the medicine item: ");
    scanf("%s", deleteItem);

    // Search for the item
    int found = 0;
    for (int i = 0; i < *itemsCount; i++) {
        if (strcmp(items[i].name, deleteItem) == 0) {
            // Delete the item from the array
            items = realloc(items, (*itemsCount - 1) * sizeof(MedicineItem));
            *itemsCount--;
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

int main() {
    // Create an array of medicine items
    MedicineItem *items = NULL;
    int itemsCount = 0;

    // Main loop
    int choice;
    while (1) {
        // Display the menu options
        printf("1. Add a new medicine item\n");
        printf("2. Search for a medicine item\n");
        printf("3. Update the quantity of a medicine item\n");
        printf("4. Delete a medicine item\n");
        printf("Enter your choice: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Switch case to handle the user's choice
        switch (choice) {
            case 1:
                addMedicineItem(&items, &itemsCount);
                break;
            case 2:
                searchMedicineItem(items, itemsCount);
                break;
            case 3:
                updateMedicineItemQuantity(items, itemsCount);
                break;
            case 4:
                deleteMedicineItem(items, &itemsCount);
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Ask the user if they want to continue
        char continueChoice;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continueChoice);

        // If the user does not want to continue, break out of the loop
        if (continueChoice != 'Y') {
            break;
        }
    }

    // Free the memory allocated for the items
    free(items);

    return 0;
}
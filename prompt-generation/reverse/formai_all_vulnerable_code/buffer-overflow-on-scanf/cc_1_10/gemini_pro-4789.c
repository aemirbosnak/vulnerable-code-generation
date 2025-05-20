//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char type[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *size) {
    printf("\n\n======...Add New Medicine...======\n");

    // Increase the size of the inventory array by 1
    *size = *size + 1;

    // Get the details of the new medicine
    printf("Enter medicine name: ");
    scanf("%s", inventory[*size - 1].name);
    printf("Enter medicine type: ");
    scanf("%s", inventory[*size - 1].type);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*size - 1].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*size - 1].quantity);

    printf("\nMedicine added successfully!\n");
}

// Function to display the inventory
void display_inventory(medicine *inventory, int size) {
    printf("\n\n======...Medicine Inventory...======\n");

    printf("%-30s %-20s %-10s %-10s\n", "Medicine Name", "Type", "Price", "Quantity");
    for (int i = 0; i < size; i++) {
        printf("%-30s %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].type, inventory[i].price, inventory[i].quantity);
    }
}

// Function to search for a medicine by name
void search_medicine(medicine *inventory, int size) {
    printf("\n\n======...Search Medicine...======\n");

    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Type: %s\n", inventory[i].type);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Function to update the quantity of a medicine
void update_quantity(medicine *inventory, int size) {
    printf("\n\n======...Update Medicine Quantity...======\n");

    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Function to delete a medicine from the inventory
void delete_medicine(medicine *inventory, int *size) {
    printf("\n\n======...Delete Medicine...======\n");

    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift all the elements after the deleted element to the left
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            // Decrease the size of the inventory array by 1
            *size = *size - 1;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Main function
int main() {
    // Create an inventory array with an initial size of 0
    medicine *inventory = NULL;
    int size = 0;

    // Main menu loop
    int choice;
    do {
        // Display the main menu
        printf("\n\n======...Medical Store Management System...======\n");
        printf("1. Add New Medicine\n");
        printf("2. Display Inventory\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine Quantity\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_medicine(inventory, &size);
                break;
            case 2:
                display_inventory(inventory, size);
                break;
            case 3:
                search_medicine(inventory, size);
                break;
            case 4:
                update_quantity(inventory, size);
                break;
            case 5:
                delete_medicine(inventory, &size);
                break;
            case 6:
                printf("\nThank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    // Free the allocated memory
    free(inventory);

    return 0;
}
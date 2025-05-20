//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a medicine
struct medicine {
    char name[50];
    int quantity;
    float price;
};

// Define a function to add medicine to the inventory
void addMedicine(struct medicine* inventory, int* size) {
    char name[50];
    int quantity;
    float price;

    printf("Enter medicine name: ");
    scanf("%s", name);

    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    printf("Enter medicine price: ");
    scanf("%f", &price);

    // Create a new medicine and add it to the inventory
    struct medicine newMedicine;
    strcpy(newMedicine.name, name);
    newMedicine.quantity = quantity;
    newMedicine.price = price;

    inventory[*size] = newMedicine;
    (*size)++;

    printf("Medicine added to inventory!\n");
}

// Define a function to remove medicine from the inventory
void removeMedicine(struct medicine* inventory, int* size) {
    char name[50];
    int found = 0;

    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    // Loop through the inventory and find the medicine
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            // Shift all the medicines after the removed medicine to the left
            for (int j = i; j < (*size) - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Medicine removed from inventory!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in inventory!\n");
    }
}

// Define a function to search for a medicine in the inventory
void searchMedicine(struct medicine* inventory, int* size) {
    char name[50];
    int found = 0;

    printf("Enter medicine name to search: ");
    scanf("%s", name);

    // Loop through the inventory and find the medicine
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("Medicine found in inventory!\nName: %s\nQuantity: %d\nPrice: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in inventory!\n");
    }
}

// Define a function to display the entire inventory
void displayInventory(struct medicine* inventory, int* size) {
    if (*size == 0) {
        printf("No medicines in inventory!\n");
        return;
    }

    printf("Inventory:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d. %s\nQuantity: %d\nPrice: $%.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // Initialize the inventory with a size of 10
    const int MAX_SIZE = 10;
    struct medicine inventory[MAX_SIZE];
    int size = 0;

    int option;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nOptions:\n1. Add medicine\n2. Remove medicine\n3. Search medicine\n4. Display inventory\n5. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            addMedicine(inventory, &size);
            break;
        case 2:
            removeMedicine(inventory, &size);
            break;
        case 3:
            searchMedicine(inventory, &size);
            break;
        case 4:
            displayInventory(inventory, &size);
            break;
        case 5:
            printf("Thank you for using the Medical Store Management System!\n");
            exit(0);
        default:
            printf("Invalid option number!\n");
        }
    }

    return 0;
}
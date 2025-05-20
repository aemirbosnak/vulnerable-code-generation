//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for string inputs
#define MAX_INPUT_LENGTH 50

// Define structure for medication items
typedef struct {
    int id;
    char name[MAX_INPUT_LENGTH];
    float price;
    int quantity;
} Medication;

// Function to add medication item to inventory
void addMedication(Medication* inventory, int* itemCount) {
    printf("Enter medication name: ");
    scanf("%s", inventory[*itemCount].name);

    printf("Enter medication price: ");
    scanf("%f", &inventory[*itemCount].price);

    printf("Enter medication quantity: ");
    scanf("%d", &inventory[*itemCount].quantity);

    inventory[*itemCount].id = (*itemCount) + 1;

    (*itemCount)++;

    printf("Medication added successfully!\n");
}

// Function to remove medication item from inventory
void removeMedication(Medication* inventory, int* itemCount) {
    int idToRemove;
    printf("Enter medication ID to remove: ");
    scanf("%d", &idToRemove);

    // Find index of medication item with matching ID
    int indexToRemove = -1;
    for (int i = 0; i < *itemCount; i++) {
        if (inventory[i].id == idToRemove) {
            indexToRemove = i;
            break;
        }
    }

    // Shift all remaining items over to fill gap
    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < (*itemCount) - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        (*itemCount)--;

        printf("Medication removed successfully!\n");
    } else {
        printf("Medication with ID %d not found.\n", idToRemove);
    }
}

// Function to display all medication items in inventory
void displayInventory(Medication* inventory, int* itemCount) {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < *itemCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    Medication inventory[50];
    int itemCount = 0;
    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    // Loop through menu options until user chooses to exit
    do {
        printf("\nPlease choose from the following options:\n");
        printf("1. Add medication\n");
        printf("2. Remove medication\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedication(inventory, &itemCount);
                break;
            case 2:
                removeMedication(inventory, &itemCount);
                break;
            case 3:
                displayInventory(inventory, &itemCount);
                break;
            case 4:
                printf("Exiting Medical Store Management System...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
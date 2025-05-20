//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of a medicine
typedef struct Medicine {
    char name[50];
    char brand[50];
    char type[50];
    int quantity;
    float price;
} Medicine;

// Function to add a new medicine to the inventory
void addMedicine(Medicine *inventory, int *count) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*count].name);

    printf("Enter the brand of the medicine: ");
    scanf("%s", inventory[*count].brand);

    printf("Enter the type of the medicine: ");
    scanf("%s", inventory[*count].type);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
}

// Function to search for a medicine in the inventory
void searchMedicine(Medicine *inventory, int count) {
    char name[50];

    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Brand: %s\n", inventory[i].brand);
            printf("Type: %s\n", inventory[i].type);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %f\n", inventory[i].price);

            return;
        }
    }

    printf("Medicine not found.\n");
}

// Function to display the inventory
void displayInventory(Medicine *inventory, int count) {
    printf("Inventory:\n");

    for (int i = 0; i < count; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Brand: %s\n", inventory[i].brand);
        printf("Type: %s\n", inventory[i].type);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %f\n\n", inventory[i].price);
    }
}

// Function to sell a medicine
void sellMedicine(Medicine *inventory, int *count) {
    char name[50];
    int quantity;

    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);

    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Medicine sold successfully.\n");

                return;
            } else {
                printf("Insufficient quantity of medicine in stock.\n");

                return;
            }
        }
    }

    printf("Medicine not found.\n");
}

// Main function
int main() {
    Medicine inventory[100];
    int count = 0;

    int choice;

    do {
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Display the inventory\n");
        printf("4. Sell a medicine\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                searchMedicine(inventory, count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                sellMedicine(inventory, &count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
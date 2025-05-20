//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_LENGTH 50

// Structure for storing medicine information
typedef struct Medicine {
    char name[MAX_LENGTH];
    float price;
    int quantity;
} Medicine;

// Global variable for storing medicine inventory
Medicine inventory[MAX_MEDICINES];

// Function for adding a new medicine to the inventory
void addMedicine() {
    printf("Enter medicine name: ");
    char name[MAX_LENGTH];
    scanf("%s", name);

    printf("Enter medicine price: ");
    float price;
    scanf("%f", &price);

    printf("Enter medicine quantity: ");
    int quantity;
    scanf("%d", &quantity);

    int i;
    for (i = 0; i < MAX_MEDICINES; i++) {
        if (inventory[i].name[0] == '\0') {
            strcpy(inventory[i].name, name);
            inventory[i].price = price;
            inventory[i].quantity = quantity;
            printf("Medicine added successfully!\n\n");
            return;
        }
    }

    printf("Error: Maximum capacity reached.\n\n");
}

// Function for removing a medicine from the inventory
void removeMedicine() {
    printf("Enter medicine name: ");
    char name[MAX_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < MAX_MEDICINES; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].name[0] = '\0';
            inventory[i].price = 0;
            inventory[i].quantity = 0;
            printf("Medicine removed successfully!\n\n");
            return;
        }
    }

    printf("Error: Medicine not found.\n\n");
}

// Function for displaying all the medicines in the inventory
void displayInventory() {
    printf("Medicine Name\tPrice\tQuantity\n");
    int i;
    for (i = 0; i < MAX_MEDICINES; i++) {
        if (inventory[i].name[0] != '\0') {
            printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Thank you for using the Medical Store Management System.\n\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n\n");
        }
    }
    return 0;
}
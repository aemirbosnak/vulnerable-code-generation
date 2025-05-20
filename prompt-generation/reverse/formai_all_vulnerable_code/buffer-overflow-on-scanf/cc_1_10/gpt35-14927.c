//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for storing medicine information */
struct Medicine {
    int id;
    char name[50];
    double price;
    int quantity;
};

/* Function to add a new medicine to the inventory */
void addMedicine(struct Medicine inventory[], int *count) {
    printf("\n=== Add Medicine ===\n");

    /* Get new medicine information from user */
    struct Medicine newMedicine;
    newMedicine.id = *count + 1;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%lf", &newMedicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);

    /* Add new medicine to inventory */
    inventory[*count] = newMedicine;
    *count += 1;

    printf("\nMedicine added successfully!\n");
}

/* Function to display the inventory */
void displayInventory(struct Medicine inventory[], int count) {
    printf("\n=== Medicine Inventory ===\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2lf\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

/* Function to search for a medicine by name */
void searchMedicine(struct Medicine inventory[], int count) {
    char searchTerm[50];
    int found = 0;

    printf("\n=== Search Medicine ===\n");
    printf("Enter medicine name: ");
    scanf("%s", searchTerm);

    /* Loop over inventory to find matching medicine */
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, searchTerm) == 0) {
            found = 1;
            printf("\nMedicine found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2lf\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found.\n");
    }
}

/* Function to sell a medicine */
void sellMedicine(struct Medicine inventory[], int count) {
    int sellId;
    int quantity;
    int sold = 0;

    printf("\n=== Sell Medicine ===\n");
    printf("Enter medicine ID: ");
    scanf("%d", &sellId);

    /* Loop over inventory to find matching medicine */
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == sellId) {
            printf("Medicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2lf\n", inventory[i].price);
            printf("Quantity in stock: %d\n", inventory[i].quantity);
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            /* Check if enough quantity is available */
            if (quantity <= inventory[i].quantity) {
                inventory[i].quantity -= quantity;
                printf("\nTransaction successful!\n");
                printf("Total cost: %.2lf\n", inventory[i].price * quantity);
                printf("Medicine %s remaining quantity: %d\n", inventory[i].name, inventory[i].quantity);
                sold = 1;
            } else {
                printf("\nInsufficient quantity in stock.\n");
            }
            break;
        }
    }

    if (!sold) {
        printf("\nMedicine not found.\n");
    }
}

int main() {
    struct Medicine inventory[50];  // maximum 50 medicines in inventory
    int count = 0;  // number of medicines currently in inventory
    int choice;

    do {
        /* Display menu and get user choice */
        printf("\n\n=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display Inventory\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        /* Execute user choice */
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                searchMedicine(inventory, count);
                break;
            case 4:
                sellMedicine(inventory, count);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
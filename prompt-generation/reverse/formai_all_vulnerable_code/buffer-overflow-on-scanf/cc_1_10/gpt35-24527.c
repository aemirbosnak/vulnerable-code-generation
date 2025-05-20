//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold medical store item details
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Function to add item to inventory
void addItem(Item *inventory, int *size) {
    printf("Enter new item name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*size].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*size].price);
    (*size)++;
    printf("Item added to inventory successfully!\n\n");
}

// Function to display inventory
void displayInventory(Item *inventory, int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\tQuantity: %d\tPrice: %.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

// Function to search for items by name
void searchItem(Item *inventory, int size) {
    char searchName[50];
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("%s found at index %d.\nQuantity: %d\tPrice: %.2f\n", searchName, i+1, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
    printf("\n");
}

int main() {

    int choice, size = 0;
    Item inventory[100];

    while (1) {

        printf("Medical Store Management System\n");
        printf("================================\n");
        printf("1. Add new item to inventory\n");
        printf("2. Display inventory\n");
        printf("3. Search for item\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &size);
                break;
            case 2:
                displayInventory(inventory, size);
                break;
            case 3:
                searchItem(inventory, size);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }

    }
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define FILE_NAME "inventory.txt"

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

void addItem();
void viewItems();
void deleteItem();
void clearScreen();

int main() {
    int choice;

    do {
        clearScreen();
        printf("=======================================\n");
        printf("          Fantasy Inventory            \n");
        printf("=======================================\n");
        printf("1. Add an item\n");
        printf("2. View items\n");
        printf("3. Delete an item\n");
        printf("4. Exit\n");
        printf("=======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after the choice

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                printf("Thank you for managing your inventory! Farewell!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("Press Enter to continue...\n");
        getchar();
    } while (choice != 4);

    return 0;
}

void addItem() {
    Item item;
    FILE *file = fopen(FILE_NAME, "a");
    
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter the item name: ");
    fgets(item.name, ITEM_NAME_LENGTH, stdin);
    item.name[strcspn(item.name, "\n")] = 0;  // Remove newline character
    printf("Enter the item quantity: ");
    scanf("%d", &item.quantity);
    getchar();  // To consume the newline character

    fprintf(file, "%s %d\n", item.name, item.quantity);
    fclose(file);

    printf("Item '%s' with quantity %d added to inventory!\n", item.name, item.quantity);
}

void viewItems() {
    Item item;
    FILE *file = fopen(FILE_NAME, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Your Inventory:\n");
    printf("--------------------------------\n");
    while (fscanf(file, "%s %d", item.name, &item.quantity) != EOF) {
        printf("Item: %s | Quantity: %d\n", item.name, item.quantity);
    }
    printf("--------------------------------\n");
    fclose(file);
}

void deleteItem() {
    Item item;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char itemName[ITEM_NAME_LENGTH];

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter the item name you wish to delete: ");
    fgets(itemName, ITEM_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;  // Remove newline character

    int found = 0;
    while (fscanf(file, "%s %d", item.name, &item.quantity) != EOF) {
        if (strcmp(item.name, itemName) == 0) {
            found = 1;
            printf("Item '%s' with quantity %d deleted from inventory!\n", item.name, item.quantity);
            continue; // Skip adding the deleted item to temp file
        }
        fprintf(tempFile, "%s %d\n", item.name, item.quantity);
    }

    if (!found) {
        printf("Item '%s' not found in inventory!\n", itemName);
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME); // Remove old inventory file
    rename("temp.txt", FILE_NAME); // Rename temp file to original file name
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}
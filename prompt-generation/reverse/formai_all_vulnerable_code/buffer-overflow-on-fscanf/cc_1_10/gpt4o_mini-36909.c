//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define ITEM_CODE_LENGTH 10

typedef struct {
    char name[ITEM_NAME_LENGTH];
    char code[ITEM_CODE_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void loadItemsFromFile();
void saveItemsToFile();
void addItem();
void deleteItem();
void searchItem();
void displayItems();
void clearInputBuffer();

int main() {
    loadItemsFromFile();
    int choice;
    
    while (1) {
        printf("\n=== Medical Store Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Search Item\n");
        printf("4. Display All Items\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                deleteItem();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                saveItemsToFile();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void loadItemsFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) return;

    while (fscanf(file, "%s %s %d %f", inventory[itemCount].name, inventory[itemCount].code,
                  &inventory[itemCount].quantity, &inventory[itemCount].price) != EOF) {
        itemCount++;
    }
    fclose(file);
}

void saveItemsToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error saving items to file.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %s %d %.2f\n", inventory[i].name, inventory[i].code,
                inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full, cannot add more items.\n");
        return;
    }
    
    printf("Enter item name: ");
    fgets(inventory[itemCount].name, ITEM_NAME_LENGTH, stdin);
    strtok(inventory[itemCount].name, "\n"); // Remove newline character
    
    printf("Enter item code: ");
    fgets(inventory[itemCount].code, ITEM_CODE_LENGTH, stdin);
    strtok(inventory[itemCount].code, "\n"); // Remove newline character
    
    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);
    
    printf("Enter price: ");
    scanf("%f", &inventory[itemCount].price);
    
    itemCount++;
    printf("Item added successfully.\n");
}

void deleteItem() {
    char code[ITEM_CODE_LENGTH];
    printf("Enter item code to delete: ");
    fgets(code, ITEM_CODE_LENGTH, stdin);
    strtok(code, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift items up
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Item with code %s not found.\n", code);
    }
}

void searchItem() {
    char code[ITEM_CODE_LENGTH];
    printf("Enter item code to search: ");
    fgets(code, ITEM_CODE_LENGTH, stdin);
    strtok(code, "\n"); // Remove newline character
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Item found: %s | Code: %s | Quantity: %d | Price: %.2f\n",
                   inventory[i].name, inventory[i].code,
                   inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with code %s not found.\n", code);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\n=== Inventory Items ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s, Code: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].name, inventory[i].code, inventory[i].quantity,
               inventory[i].price);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}
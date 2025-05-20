//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    char description[MAX_DESCRIPTION_LENGTH];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

// Function prototypes
void addItem(Inventory* inventory);
void displayItems(const Inventory* inventory);
void saveInventoryToFile(const Inventory* inventory, const char* filename);
void loadInventoryFromFile(Inventory* inventory, const char* filename);
void searchItem(const Inventory* inventory, const char* query);

int main() {
    Inventory inventory = { .count = 0 };
    int choice;
    char filename[100];

    printf("Welcome to the Inventory Management System\n");
    printf("Please enter the name of the file to load inventory: ");
    scanf("%s", filename);
    
    loadInventoryFromFile(&inventory, filename);

    do {
        printf("\n1. Add Item\n2. Display Items\n3. Search Item\n4. Save Inventory\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                displayItems(&inventory);
                break;
            case 3: {
                char query[MAX_NAME_LENGTH];
                printf("Enter the name of the item to search: ");
                scanf("%s", query);
                searchItem(&inventory, query);
                break;
            }
            case 4:
                saveInventoryToFile(&inventory, filename);
                break;
            case 5:
                printf("Exiting the system. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addItem(Inventory* inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item description: ");
    scanf(" %[^\n]", newItem.description); // Read string with spaces

    inventory->items[inventory->count] = newItem;
    inventory->count++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void displayItems(const Inventory* inventory) {
    if (inventory->count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inventory->items[i].name);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Description: %s\n\n", inventory->items[i].description);
    }
}

void saveInventoryToFile(const Inventory* inventory, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        fprintf(file, "%s\n%.2f\n%s\n", inventory->items[i].name, inventory->items[i].price, inventory->items[i].description);
    }

    fclose(file);
    printf("Inventory saved successfully to '%s'.\n", filename);
}

void loadInventoryFromFile(Inventory* inventory, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No existing inventory file found. Starting with an empty inventory.\n");
        return;
    }

    while (fscanf(file, "%s\n%f\n%[^\n]\n", inventory->items[inventory->count].name, &inventory->items[inventory->count].price, inventory->items[inventory->count].description) != EOF) {
        inventory->count++;
        if (inventory->count >= MAX_ITEMS) {
            break; // Prevent adding more than max items
        }
    }
    fclose(file);
    printf("Inventory loaded successfully from '%s'.\n", filename);
}

void searchItem(const Inventory* inventory, const char* query) {
    int found = 0;
    for (int i = 0; i < inventory->count; i++) {
        if (strcasecmp(inventory->items[i].name, query) == 0) {
            printf("Item found:\n");
            printf("Name: %s\n", inventory->items[i].name);
            printf("Price: %.2f\n", inventory->items[i].price);
            printf("Description: %s\n", inventory->items[i].description);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item '%s' not found in the inventory.\n", query);
    }
}
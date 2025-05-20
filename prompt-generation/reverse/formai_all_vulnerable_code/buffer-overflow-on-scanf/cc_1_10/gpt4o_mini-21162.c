//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

void displayMenu();
void addItem(Item items[], int *itemCount);
void listItems(Item items[], int itemCount);
void searchItem(Item items[], int itemCount);
void updateItem(Item items[], int itemCount);
void deleteItem(Item items[], int *itemCount);
void saveData(Item items[], int itemCount);
void loadData(Item items[], int *itemCount);
void clearBuffer();

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    loadData(items, &itemCount);

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                listItems(items, itemCount);
                break;
            case 3:
                searchItem(items, itemCount);
                break;
            case 4:
                updateItem(items, itemCount);
                break;
            case 5:
                deleteItem(items, &itemCount);
                break;
            case 6:
                saveData(items, itemCount);
                printf("Exiting... Data saved!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Inventory Management System ---\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Search Item\n");
    printf("4. Update Item\n");
    printf("5. Delete Item\n");
    printf("6. Exit\n");
}

void addItem(Item items[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    fgets(items[*itemCount].name, ITEM_NAME_LENGTH, stdin);
    strtok(items[*itemCount].name, "\n"); // Remove newline
    printf("Enter item price: ");
    scanf("%f", &items[*itemCount].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*itemCount].quantity);
    clearBuffer();
    
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void listItems(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\n--- Items in Inventory ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: Name: %s, Price: %.2f, Quantity: %d\n", 
               i + 1, items[i].name, items[i].price, items[i].quantity);
    }
}

void searchItem(Item items[], int itemCount) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    fgets(name, ITEM_NAME_LENGTH, stdin);
    strtok(name, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Found: Name: %s, Price: %.2f, Quantity: %d\n", 
                   items[i].name, items[i].price, items[i].quantity);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void updateItem(Item items[], int itemCount) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to update: ");
    fgets(name, ITEM_NAME_LENGTH, stdin);
    strtok(name, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            clearBuffer();
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void deleteItem(Item items[], int *itemCount) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to delete: ");
    fgets(name, ITEM_NAME_LENGTH, stdin);
    strtok(name, "\n");

    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < *itemCount - 1; j++) {
                items[j] = items[j + 1]; // Shift items
            }
            (*itemCount)--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void saveData(Item items[], int itemCount) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %.2f %d\n", items[i].name, items[i].price, items[i].quantity);
    }
    fclose(file);
}

void loadData(Item items[], int *itemCount) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %f %d", items[*itemCount].name, &items[*itemCount].price, 
                  &items[*itemCount].quantity) != EOF) {
        (*itemCount)++;
    }
    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}
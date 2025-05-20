//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

// Structure to hold item information
typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Function declarations
void addItem(Item items[], int *itemCount);
void viewItems(Item items[], int itemCount);
void updateItem(Item items[], int itemCount);
void deleteItem(Item items[], int *itemCount);
void saveData(Item items[], int itemCount);
void loadData(Item items[], int *itemCount);
void displayMenu();

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    loadData(items, &itemCount);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                viewItems(items, itemCount);
                break;
            case 3:
                updateItem(items, itemCount);
                break;
            case 4:
                deleteItem(items, &itemCount);
                break;
            case 5:
                saveData(items, itemCount);
                printf("Data saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Save Data\n");
    printf("6. Exit\n");
}

void addItem(Item items[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[*itemCount].name);
    printf("Enter quantity: ");
    scanf("%d", &items[*itemCount].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*itemCount].price);
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void viewItems(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("\n--- Items in Warehouse ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s, Quantity: %d, Price: %.2f\n", 
               i + 1, items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItem(Item items[], int itemCount) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Current quantity: %d, Current price: %.2f\n", 
                   items[i].quantity, items[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem(Item items[], int *itemCount) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < *itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            (*itemCount)--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void saveData(Item items[], int itemCount) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving data!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %d %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    fclose(file);
}

void loadData(Item items[], int *itemCount) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (file == NULL) {
        return;
    }
    
    while (fscanf(file, "%s %d %f", items[*itemCount].name, 
                  &items[*itemCount].quantity, &items[*itemCount].price) == 3) {
        (*itemCount)++;
    }
    fclose(file);
}
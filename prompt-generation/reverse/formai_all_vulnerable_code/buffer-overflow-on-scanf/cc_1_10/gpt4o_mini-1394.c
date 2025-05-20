//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Item;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add New Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. Display All Items\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
    printf("Select an option (1-6): ");
}

void addItem(Item items[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = *itemCount + 1; // auto-increment ID
    printf("Enter item name: ");
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // remove newline
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    clearInputBuffer();
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    clearInputBuffer();

    items[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void updateItem(Item items[], int itemCount) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    if (id < 1 || id > itemCount) {
        printf("Item not found.\n");
        return;
    }

    printf("Enter new name for Item ID %d: ", id);
    fgets(items[id - 1].name, NAME_LENGTH, stdin);
    items[id - 1].name[strcspn(items[id - 1].name, "\n")] = 0; // remove newline
    printf("Enter new price for Item ID %d: ", id);
    scanf("%f", &items[id - 1].price);
    clearInputBuffer();
    printf("Enter new quantity for Item ID %d: ", id);
    scanf("%d", &items[id - 1].quantity);
    clearInputBuffer();

    printf("Item updated successfully!\n");
}

void deleteItem(Item items[], int *itemCount) {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    if (id < 1 || id > *itemCount) {
        printf("Item not found.\n");
        return;
    }

    for (int i = id - 1; i < *itemCount - 1; i++) {
        items[i] = items[i + 1];
    }
    (*itemCount)--;

    printf("Item deleted successfully!\n");
}

void displayItems(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n=== Inventory Items ===\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

void searchItem(Item items[], int itemCount) {
    char searchName[NAME_LENGTH];
    printf("Enter item name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // remove newline

    printf("\n=== Search Results ===\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strstr(items[i].name, searchName) != NULL) {
            printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No items found with that name.\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                updateItem(items, itemCount);
                break;
            case 3:
                deleteItem(items, &itemCount);
                break;
            case 4:
                displayItems(items, itemCount);
                break;
            case 5:
                searchItem(items, itemCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

void displayMenu() {
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

Item* createItem(const char* name, int quantity) {
    Item* newItem = (Item*) malloc(sizeof(Item));
    if (newItem == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newItem->name, name, MAX_NAME_LENGTH - 1);
    newItem->name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null termination
    newItem->quantity = quantity;
    return newItem;
}

void addItem(Item** items, int* itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name); // simple input, could use safer alternative like fgets
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    items[*itemCount] = createItem(name, quantity);
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void viewItems(Item** items, int itemCount) {
    if (itemCount == 0) {
        printf("No items to display.\n");
        return;
    }
    printf("Items in inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: Name: %s, Quantity: %d\n", i + 1, items[i]->name, items[i]->quantity);
    }
}

void removeItem(Item** items, int* itemCount) {
    if (*itemCount == 0) {
        printf("No items to remove.\n");
        return;
    }
    int index;
    viewItems(items, *itemCount);
    printf("Enter the item number to remove: ");
    scanf("%d", &index);
    index--;  // Convert to zero-based index

    if (index < 0 || index >= *itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    free(items[index]);

    // Shift items to fill the gap
    for (int i = index; i < *itemCount - 1; i++) {
        items[i] = items[i + 1];
    }
    (*itemCount)--;

    printf("Item removed successfully!\n");
}

void freeItems(Item** items, int itemCount) {
    for (int i = 0; i < itemCount; i++) {
        free(items[i]);
    }
}

int main() {
    Item* items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                viewItems(items, itemCount);
                break;
            case 3:
                removeItem(items, &itemCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeItems(items, itemCount);
    return 0;
}
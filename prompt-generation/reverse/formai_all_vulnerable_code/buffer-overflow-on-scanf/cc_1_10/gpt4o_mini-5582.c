//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} ShoppingList;

void initializeShoppingList(ShoppingList *list) {
    list->count = 0;
}

void addItem(ShoppingList *list, const char *itemName) {
    if (list->count < MAX_ITEMS) {
        strncpy(list->items[list->count].name, itemName, MAX_ITEM_NAME_LENGTH-1);
        list->items[list->count].name[MAX_ITEM_NAME_LENGTH-1] = '\0'; // Ensure null-termination
        list->count++;
        printf("Added item: %s\n", itemName);
    } else {
        printf("Shopping list is full! Cannot add more items.\n");
    }
}

void removeItem(ShoppingList *list, const char *itemName) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->items[i].name, itemName) == 0) {
            // Move items down to fill the gap
            for (int j = i; j < list->count - 1; j++) {
                list->items[j] = list->items[j + 1];
            }
            list->count--;
            printf("Removed item: %s\n", itemName);
            return;
        }
    }
    printf("Item not found: %s\n", itemName);
}

void viewItems(const ShoppingList *list) {
    if (list->count == 0) {
        printf("The shopping list is empty.\n");
        return;
    }
    printf("Shopping List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->items[i].name);
    }
}

void saveToFile(const ShoppingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->items[i].name);
    }
    fclose(file);
    printf("Shopping list saved to %s\n", filename);
}

void loadFromFile(ShoppingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    char line[MAX_ITEM_NAME_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL && list->count < MAX_ITEMS) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        addItem(list, line);
    }
    fclose(file);
    printf("Shopping list loaded from %s\n", filename);
}

int main() {
    ShoppingList list;
    initializeShoppingList(&list);

    loadFromFile(&list, "shoppinglist.txt"); // Load existing shopping list from file
    int choice;
    char itemName[MAX_ITEM_NAME_LENGTH];

    do {
        printf("\nShopping List Menu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Save List\n");
        printf("5. Load List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after entering choice

        switch (choice) {
            case 1:
                printf("Enter item name to add: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Remove newline character
                addItem(&list, itemName);
                break;
            case 2:
                printf("Enter item name to remove: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Remove newline character
                removeItem(&list, itemName);
                break;
            case 3:
                viewItems(&list);
                break;
            case 4:
                saveToFile(&list, "shoppinglist.txt");
                break;
            case 5:
                loadFromFile(&list, "shoppinglist.txt");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
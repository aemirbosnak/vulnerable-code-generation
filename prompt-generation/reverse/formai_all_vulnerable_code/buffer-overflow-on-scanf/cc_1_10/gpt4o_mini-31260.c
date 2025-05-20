//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char name[30];
    int id;
} Item;

void displayItems(Item items[], int count) {
    printf("\nCurrent Items:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", items[i].id, items[i].name);
    }
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        fprintf(stderr, "Error: Cannot add more items. Max limit reached.\n");
        return;
    }

    Item newItem;
    printf("Enter item ID: ");
    if (scanf("%d", &newItem.id) != 1) {
        fprintf(stderr, "Input error: %s\n", strerror(errno));
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }

    printf("Enter item name: ");
    if (scanf("%s", newItem.name) != 1) {
        fprintf(stderr, "Input error: %s\n", strerror(errno));
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }

    items[*count] = newItem;
    (*count)++;
    printf("Item added successfully!\n");
}

void removeItem(Item items[], int *count) {
    if (*count == 0) {
        fprintf(stderr, "Error: No items to remove.\n");
        return;
    }

    int idToRemove;
    printf("Enter item ID to remove: ");
    if (scanf("%d", &idToRemove) != 1) {
        fprintf(stderr, "Input error: %s\n", strerror(errno));
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (items[i].id == idToRemove) {
            items[i] = items[--(*count)]; // Remove item by swapping with the last and decrement count
            printf("Item with ID %d removed successfully!\n", idToRemove);
            return;
        }
    }
    
    fprintf(stderr, "Error: Item with ID %d not found.\n", idToRemove);
}

void listMenu() {
    printf("\nMenu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Item items[MAX_ITEMS];
    int item_count = 0;
    int choice;

    while (1) {
        listMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Input error: %s\n", strerror(errno));
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addItem(items, &item_count);
                break;
            case 2:
                removeItem(items, &item_count);
                break;
            case 3:
                displayItems(items, item_count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                fprintf(stderr, "Error: Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
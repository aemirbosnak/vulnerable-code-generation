//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Item;

// Function prototypes
void addItem(Item items[], int *count);
void searchItem(Item items[], int count);
void displayItems(Item items[], int count);
void sortItems(Item items[], int count);

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory System\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                searchItem(items, count);
                break;
            case 3:
                displayItems(items, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add item to inventory
void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &items[*count].id);
    getchar(); // Consume the newline
    printf("Enter item name: ");
    fgets(items[*count].name, NAME_LENGTH, stdin);
    items[*count].name[strcspn(items[*count].name, "\n")] = 0; // Remove newline character

    (*count)++;
    printf("Item added successfully!\n");
}

// Function to search for an item by ID
void searchItem(Item items[], int count) {
    if (count == 0) {
        printf("No items in the inventory to search.\n");
        return;
    }

    int searchId;
    printf("Enter item ID to search: ");
    scanf("%d", &searchId);

    // Sort the items before searching
    sortItems(items, count);

    int left = 0, right = count - 1, mid;
    int found = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (items[mid].id == searchId) {
            printf("Item found: ID = %d, Name = %s\n", items[mid].id, items[mid].name);
            found = 1;
            break;
        } else if (items[mid].id < searchId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
}

// Function to display all items in inventory
void displayItems(Item items[], int count) {
    if (count == 0) {
        printf("No items in the inventory to display.\n");
        return;
    }

    printf("\nItems in Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", items[i].id, items[i].name);
    }
}

// Function to sort items by ID using bubble sort
void sortItems(Item items[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (items[j].id > items[j + 1].id) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}
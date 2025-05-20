//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_STRING_LENGTH 100

/* Structure to store item information */
struct Item {
    int id;
    char name[MAX_STRING_LENGTH];
    int quantity;
    float price;
};

/* Function to add an item to the inventory */
void add_item(struct Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[*count].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*count].price);

    items[*count].id = (*count) + 1; // Assign item ID
    (*count)++; // Update item count

    printf("Item added successfully\n");
}

/* Function to search for an item by name */
void search_item(struct Item items[], int count) {
    char name[MAX_STRING_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }

    printf("Item not found\n");
}

/* Function to display all items in the inventory */
void display_items(struct Item items[], int count) {
    printf("Inventory:\n");
    printf("| ID | Name | Quantity | Price |\n");
    for (int i = 0; i < count; i++) {
        printf("| %d | %s | %d | %.2f |\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

/* Function to remove an item from the inventory */
void remove_item(struct Item items[], int *count) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (items[i].id == id) {
            for (int j = i; j < (*count) - 1; j++) {
                items[j] = items[j+1]; // Shift all the items down
            }
            (*count)--; // Update item count
            printf("Item removed successfully\n");
            return;
        }
    }

    printf("Item not found\n");
}

int main() {
    struct Item items[MAX_ITEMS];
    int count = 0;

    int choice;

    do {
        printf("\nInventory Management\n");
        printf("1. Add item\n");
        printf("2. Search item\n");
        printf("3. Display items\n");
        printf("4. Remove item\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item(items, &count); break;
            case 2: search_item(items, count); break;
            case 3: display_items(items, count); break;
            case 4: remove_item(items, &count); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
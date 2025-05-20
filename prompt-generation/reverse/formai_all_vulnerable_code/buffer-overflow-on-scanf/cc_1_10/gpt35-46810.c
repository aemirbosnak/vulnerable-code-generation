//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

// Structure to represent an item in the warehouse
typedef struct item {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Function to get an item from user
Item getItem() {
    Item item;
    printf("Enter item id: ");
    scanf("%d", &item.id);
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    return item;
}

// Function to add an item to the warehouse
void addItem(Item *items, int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    items[*count] = getItem();
    (*count)++;
    printf("Item added successfully!\n");
}

// Function to remove an item from the warehouse
void removeItem(Item *items, int *count, int id) {
    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (items[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (i = i+1; i < *count; i++) {
            items[i-1] = items[i];
        }
        (*count)--;
        printf("Item removed successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

// Function to update an item in the warehouse
void updateItem(Item *items, int *count, int id) {
    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (items[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        items[i] = getItem();
        printf("Item updated successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

// Function to search for an item in the warehouse
void searchItem(Item *items, int count, int id) {
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Item found:\n");
        printf("ID: %d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %.2f\n", items[i].price);
    } else {
        printf("Item not found!\n");
    }
}

// Function to display all items in the warehouse
void displayItems(Item *items, int count) {
    int i;
    printf("All items in the warehouse:\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %.2f\n", items[i].price);
        printf("\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice, id;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item\n");
        printf("4. Search item\n");
        printf("5. Display all items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                printf("Enter item id to remove: ");
                scanf("%d", &id);
                removeItem(items, &count, id);
                break;
            case 3:
                printf("Enter item id to update: ");
                scanf("%d", &id);
                updateItem(items, &count, id);
                break;
            case 4:
                printf("Enter item id to search: ");
                scanf("%d", &id);
                searchItem(items, count, id);
                break;
            case 5:
                displayItems(items, count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
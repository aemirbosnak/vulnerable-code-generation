//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
// C Medical Store Management System
// Written by Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum items in stock

// Structure to define an item
struct Item {
    int id; // Item id
    char name[50]; // Item name
    float price; // Item price
    int quantity; // Quantity in stock
};

// Function to print the menu
void printMenu() {
    printf("\nC Medical Store Management System\n");
    printf("----------------------\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Edit item\n");
    printf("4. Search item\n");
    printf("5. List all items\n");
    printf("6. Exit\n");
    printf("----------------------\n");
}

// Function to add an item
void addItem(struct Item items[], int *numItems) {
    if (*numItems == MAX_ITEMS) {
        printf("Stock is full. Cannot add item.\n");
        return;
    }
    struct Item item;
    item.id = *numItems + 1;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    items[*numItems] = item;
    (*numItems)++;
    printf("Item added.\n");
}

// Function to remove an item
void removeItem(struct Item items[], int *numItems) {
    int id;
    printf("Enter item id to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < *numItems; i++) {
        if (items[i].id == id) {
            for (int j = i; j < (*numItems)-1; j++) {
                items[j] = items[j+1];
            }
            (*numItems)--;
            printf("Item removed.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to edit an item
void editItem(struct Item items[], int numItems) {
    int id;
    printf("Enter item id to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < numItems; i++) {
        if (items[i].id == id) {
            printf("Enter new item name: ");
            scanf("%s", items[i].name);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Item edited.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to search an item
void searchItem(struct Item items[], int numItems) {
    char name[50];
    printf("Enter item name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item id: %d\n", items[i].id);
            printf("Item name: %s\n", items[i].name);
            printf("Item price: %.2f\n", items[i].price);
            printf("Item quantity: %d\n", items[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
}

// Function to list all items
void listItems(struct Item items[], int numItems) {
    printf("Item id | Item name | Item price | Item quantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%-7d | %-9s | %-10.2f | %d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

// Main function
int main() {
    struct Item items[MAX_ITEMS];
    int numItems = 0;
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                removeItem(items, &numItems);
                break;
            case 3:
                editItem(items, numItems);
                break;
            case 4:
                searchItem(items, numItems);
                break;
            case 5:
                listItems(items, numItems);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
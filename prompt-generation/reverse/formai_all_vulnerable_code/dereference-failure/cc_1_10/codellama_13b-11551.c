//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
/*
 * Warehouse Management System - Romeo and Juliet Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a warehouse item
typedef struct {
    char name[32];
    int quantity;
    double price;
} Item;

// Function to display the items in the warehouse
void displayItems(Item items[], int n) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d units at $%.2f each\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to add a new item to the warehouse
void addItem(Item items[], int *n, char *name, int quantity, double price) {
    // Check if the item is already in the warehouse
    for (int i = 0; i < *n; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            items[i].price = price;
            return;
        }
    }

    // If the item is not in the warehouse, add it
    strcpy(items[*n].name, name);
    items[*n].quantity = quantity;
    items[*n].price = price;
    (*n)++;
}

// Function to remove an item from the warehouse
void removeItem(Item items[], int *n, char *name, int quantity) {
    // Check if the item is in the warehouse
    for (int i = 0; i < *n; i++) {
        if (strcmp(items[i].name, name) == 0) {
            // If the item is in the warehouse, remove it
            if (items[i].quantity > quantity) {
                items[i].quantity -= quantity;
            } else {
                (*n)--;
                for (int j = i; j < *n; j++) {
                    items[j] = items[j + 1];
                }
            }
            return;
        }
    }

    // If the item is not in the warehouse, do nothing
}

int main() {
    // Initialize the warehouse with 3 items
    Item items[3];
    strcpy(items[0].name, "apple");
    items[0].quantity = 10;
    items[0].price = 2.5;
    strcpy(items[1].name, "banana");
    items[1].quantity = 5;
    items[1].price = 3.5;
    strcpy(items[2].name, "orange");
    items[2].quantity = 8;
    items[2].price = 4.5;
    int n = 3;

    // Add a new item to the warehouse
    addItem(items, &n, "cherry", 15, 5.5);

    // Remove an item from the warehouse
    removeItem(items, &n, "banana", 3);

    // Display the items in the warehouse
    displayItems(items, n);

    return 0;
}
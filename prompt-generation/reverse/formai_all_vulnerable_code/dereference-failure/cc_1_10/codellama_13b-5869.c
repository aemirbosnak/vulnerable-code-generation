//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for inventory items
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Define struct for inventory system
struct Inventory {
    struct Item* items;
    int capacity;
    int size;
};

// Function to create a new inventory
struct Inventory* createInventory(int capacity) {
    struct Inventory* inv = (struct Inventory*)malloc(sizeof(struct Inventory));
    inv->capacity = capacity;
    inv->size = 0;
    inv->items = (struct Item*)malloc(capacity * sizeof(struct Item));
    return inv;
}

// Function to add an item to the inventory
void addItem(struct Inventory* inv, char* name, int quantity, float price) {
    struct Item item = {name, quantity, price};
    inv->items[inv->size] = item;
    inv->size++;
}

// Function to remove an item from the inventory
void removeItem(struct Inventory* inv, char* name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            inv->items[i] = inv->items[inv->size - 1];
            inv->size--;
            break;
        }
    }
}

// Function to print the inventory
void printInventory(struct Inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->size; i++) {
        printf("%s: %d, %.2f\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

int main() {
    struct Inventory* inv = createInventory(10);
    addItem(inv, "Apples", 10, 1.5);
    addItem(inv, "Bananas", 5, 2.0);
    addItem(inv, "Oranges", 20, 3.0);
    addItem(inv, "Milk", 10, 5.0);
    removeItem(inv, "Apples");
    removeItem(inv, "Bananas");
    printInventory(inv);
    return 0;
}
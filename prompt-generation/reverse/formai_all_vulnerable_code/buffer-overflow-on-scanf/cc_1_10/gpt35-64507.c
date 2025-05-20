//FormAI DATASET v1.0 Category: Data mining ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold data for each item
typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Item;

// Function prototypes
void generateData(Item* items, int count);
float calculateTotal(Item* items, int count);
int findMostExpensive(Item* items, int count);
int findLeastExpensive(Item* items, int count);
int findItemByName(Item* items, int count, char* name);
int findItemById(Item* items, int count, int id);
void printInventory(Item* items, int count);

int main() {
    srand(time(NULL)); // Initialize random seed
    
    // Generate 10 random items
    Item items[10];
    generateData(items, 10);
    printf("Initial inventory:\n");
    printInventory(items, 10);
    
    // Calculate total inventory value
    float total = calculateTotal(items, 10);
    printf("\nTotal inventory value: $%.2f\n", total);
    
    // Find most expensive item
    int mostExpensive = findMostExpensive(items, 10);
    printf("\nMost expensive item: %s ($%.2f)\n", items[mostExpensive].name, items[mostExpensive].price);
    
    // Find least expensive item
    int leastExpensive = findLeastExpensive(items, 10);
    printf("\nLeast expensive item: %s ($%.2f)\n", items[leastExpensive].name, items[leastExpensive].price);
    
    // Find item by name
    char name[20];
    printf("\nEnter item name to search for: ");
    scanf("%s", name);
    int itemByName = findItemByName(items, 10, name);
    if (itemByName == -1) {
        printf("Item %s not found\n", name);
    } else {
        printf("Item %s found with ID %d\n", name, items[itemByName].id);
    }
    
    // Find item by ID
    int id;
    printf("\nEnter item ID to search for: ");
    scanf("%d", &id);
    int itemById = findItemById(items, 10, id);
    if (itemById == -1) {
        printf("Item with ID %d not found\n", id);
    } else {
        printf("Item with ID %d found: %s\n", id, items[itemById].name);
    }
    
    return 0;
}

// Function to randomly generate data for each item
void generateData(Item* items, int count) {
    for (int i = 0; i < count; i++) {
        items[i].id = i + 1; // Start with ID 1
        sprintf(items[i].name, "Item %d", i + 1); // Name format: Item N
        items[i].quantity = rand() % 10 + 1; // Random quantity from 1-10
        items[i].price = (float) (rand() % 100) + ((float) (rand() % 100) / 100); // Random price from 0-99.99
    }
}

// Function to calculate total inventory value
float calculateTotal(Item* items, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

// Function to find index of most expensive item
int findMostExpensive(Item* items, int count) {
    int mostExpensive = 0;
    for (int i = 1; i < count; i++) {
        if (items[i].price > items[mostExpensive].price) {
            mostExpensive = i;
        }
    }
    return mostExpensive;
}

// Function to find index of least expensive item
int findLeastExpensive(Item* items, int count) {
    int leastExpensive = 0;
    for (int i = 1; i < count; i++) {
        if (items[i].price < items[leastExpensive].price) {
            leastExpensive = i;
        }
    }
    return leastExpensive;
}

// Function to find index of item by name
int findItemByName(Item* items, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to find index of item by ID
int findItemById(Item* items, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to print inventory
void printInventory(Item* items, int count) {
    printf("%4s %-20s %5s %6s\n", "ID", "Name", "Qty", "Price");
    for (int i = 0; i < count; i++) {
        printf("%4d %-20s %5d $%5.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}
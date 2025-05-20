//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Struct to store item information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float cost;
    int quantity;
} Item;

// Function to read items from a file
void readItems(Item items[], int *numItems) {
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items file.\n");
        exit(1);
    }

    *numItems = 0;
    while (fscanf(fp, "%s %f %d\n", items[*numItems].name, &items[*numItems].cost, &items[*numItems].quantity) == 3) {
        (*numItems)++;
    }

    fclose(fp);
}

// Function to write items to a file
void writeItems(Item items[], int numItems) {
    FILE *fp = fopen("items.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open items file.\n");
        exit(1);
    }

    for (int i = 0; i < numItems; i++) {
        fprintf(fp, "%s %f %d\n", items[i].name, items[i].cost, items[i].quantity);
    }

    fclose(fp);
}

// Function to sort items by cost
void sortItems(Item items[], int numItems) {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = i + 1; j < numItems; j++) {
            if (items[j].cost < items[i].cost) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to calculate total cost of items
float calculateTotalCost(Item items[], int numItems) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].cost * items[i].quantity;
    }
    return totalCost;
}

// Main function
int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    // Read items from file
    readItems(items, &numItems);

    // Sort items by cost
    sortItems(items, numItems);

    // Calculate total cost of items
    float totalCost = calculateTotalCost(items, numItems);

    // Print results
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}
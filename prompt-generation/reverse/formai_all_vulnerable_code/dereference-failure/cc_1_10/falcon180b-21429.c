//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Define the structure for each item
typedef struct {
    char name[50];
    double price;
    char category[50];
} Item;

// Function to compare two items based on their names
int compareItems(const void* a, const void* b) {
    const Item* item1 = (const Item*) a;
    const Item* item2 = (const Item*) b;
    return strcmp(item1->name, item2->name);
}

// Function to calculate the total cost of all items
double calculateTotalCost(Item* items, int numItems) {
    double totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price;
    }
    return totalCost;
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    // Read in the items from a file
    FILE* file = fopen("items.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        strcpy(items[numItems].name, strtok(line, ","));
        strcpy(items[numItems].category, strtok(NULL, ","));
        items[numItems].price = atof(strtok(NULL, ","));
        numItems++;
    }
    fclose(file);

    // Sort the items by name
    qsort(items, numItems, sizeof(Item), compareItems);

    // Calculate the total cost of all items
    double totalCost = calculateTotalCost(items, numItems);

    // Print the results
    printf("Total cost: $%.2f\n", totalCost);
    printf("Item count: %d\n", numItems);

    return 0;
}
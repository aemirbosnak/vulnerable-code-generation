//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Peaceful structure representing a node in the array
typedef struct {
    int value;
    char description[50];
} Item;

// Function to create a database of items
void createItemDatabase(Item *items, int size) {
    for (int i = 0; i < size; i++) {
        items[i].value = (i + 1) * 10; // Simple values for demonstration
        snprintf(items[i].description, sizeof(items[i].description), "Item %d", i + 1);
    }
}

// Function to display all items
void displayItems(Item *items, int size) {
    printf("Items in the database:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Description: %s\n", items[i].value, items[i].description);
    }
}

// Peaceful binary search algorithm
int peacefulBinarySearch(Item *items, int size, int targetValue) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Returning the index when the peaceful target is found
        if (items[mid].value == targetValue) {
            return mid; // Target found
        }

        // Peacefully adjusting the search boundaries
        if (items[mid].value < targetValue) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Peacefully indicating that the target is not found
}

int main() {
    const int databaseSize = 10;
    Item items[databaseSize];

    // Create and display the peaceful item database
    createItemDatabase(items, databaseSize);
    displayItems(items, databaseSize);

    // Peaceful user input
    int targetValue;
    printf("Enter a value to search for (multiples of 10 only): ");
    scanf("%d", &targetValue);

    // Executing the peaceful search
    int result = peacefulBinarySearch(items, databaseSize, targetValue);

    // Peaceful output of search result
    if (result != -1) {
        printf("Peacefully found: %s with a value of %d at index %d\n", items[result].description, items[result].value, result);
    } else {
        printf("Alas, the peaceful target value %d was not found in the database.\n", targetValue);
    }

    return 0;
}
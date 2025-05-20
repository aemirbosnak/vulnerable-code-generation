//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char itemName[MAX_ITEM_NAME_LENGTH];
    int quantity;
} Item;

int main() {
    Item warehouse[MAX_ITEMS];
    int itemCount = 0;
    int i, j;

    // Adding items to the warehouse
    printf("Welcome to our Warehouse Management System!\n");
    printf("Please enter the item name and quantity (separated by a space)\n");
    printf("Type 'done' when you're finished adding items\n");

    char input[MAX_ITEM_NAME_LENGTH + 5];
    while (itemCount < MAX_ITEMS) {
        printf("Item %d: ", itemCount + 1);
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        // Get quantity
        scanf("%d", &warehouse[itemCount].quantity);

        // Copy item name to struct
        strncpy(warehouse[itemCount].itemName, input, MAX_ITEM_NAME_LENGTH);
        warehouse[itemCount].itemName[MAX_ITEM_NAME_LENGTH - 1] = '\0';

        itemCount++;
    }

    // Print out the items in alphabetical order
    printf("\n\nWarehouse Inventory:\n");
    for (i = 'a'; i <= 'z'; i++) {
        for (j = 0; j < itemCount; j++) {
            if (tolower(warehouse[j].itemName[0]) == i) {
                printf("%s: %d\n", warehouse[j].itemName, warehouse[j].quantity);
            }
        }
    }

    // Search the warehouse for a specific item
    char searchItem[MAX_ITEM_NAME_LENGTH];
    printf("\n\nPlease enter an item to search for: ");
    scanf("%s", searchItem);

    for (i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].itemName, searchItem) == 0) {
            printf("Found %s: %d\n", searchItem, warehouse[i].quantity);
            break;
        }
    }

    if (i == itemCount) {
        printf("Sorry, %s is not in stock at this time.\n", searchItem);
    }

    return 0;
}
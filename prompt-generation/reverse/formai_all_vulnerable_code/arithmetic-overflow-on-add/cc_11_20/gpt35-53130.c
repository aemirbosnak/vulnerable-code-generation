//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
// Welcome to the Warehouse Management System!
// This program helps you track your inventory in a fun and cheerful way!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

int main() {
    int numItems, choice, i, j;
    float total = 0;
    char input[10];
    Item *items;

    printf("Welcome to the Warehouse Management System!\n\n");

    // Get number of items to track
    printf("How many items do you want to track? ");
    scanf("%d", &numItems);

    // Create dynamic array to store items
    items = (Item*)malloc(numItems * sizeof(Item));

    // Prompt user to enter item info
    printf("\nGreat! Let's start tracking your inventory.\n");
    printf("Please enter the name, quantity, and price of each item.\n");

    // Loop through array and get item info
    for (i = 0; i < numItems; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%f", &items[i].price);
    }

    // Display menu options
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. View inventory\n");
        printf("2. Add items\n");
        printf("3. Remove items\n");
        printf("4. Calculate total value\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display current inventory
                printf("\nCurrent inventory:\n");
                for (i = 0; i < numItems; i++) {
                    printf("%d %s @ $%.2f each\n", items[i].quantity, items[i].name, items[i].price);
                }
                break;
            case 2:
                // Add items to inventory
                printf("\nHow many items would you like to add? ");
                scanf("%d", &j);
                items = realloc(items, (numItems+j) * sizeof(Item));
                for (i = numItems; i < numItems+j; i++) {
                    printf("\nItem %d:\n", i + 1);
                    printf("Name: ");
                    scanf("%s", items[i].name);
                    printf("Quantity: ");
                    scanf("%d", &items[i].quantity);
                    printf("Price: ");
                    scanf("%f", &items[i].price);
                }
                numItems += j;
                break;
            case 3:
                // Remove items from inventory
                printf("\nWhich item would you like to remove? ");
                scanf("%s", input);
                for (i = 0; i < numItems; i++) {
                    if (strcmp(items[i].name,input) == 0) {
                        printf("\n%d %s @ $%.2f each has been removed from inventory.\n", items[i].quantity, items[i].name, items[i].price);
                        for (j = i; j < numItems - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        numItems--;
                        items = realloc(items, numItems * sizeof(Item));
                        break;
                    }
                }
                break;
            case 4:
                // Calculate total value of inventory
                total = 0;
                printf("\nThe total value of your inventory is:\n");
                for (i = 0; i < numItems; i++) {
                    total += (items[i].quantity * items[i].price);
                }
                printf("$%.2f\n", total);
                break;
            case 5:
                // Exit program
                printf("\nGoodbye!\n");
                free(items);
                return 0;
            default:
                // Invalid input
                printf("\nInvalid input. Please try again.\n");
        }
    }
    return 0;
}
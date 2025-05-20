//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
/*
 * C Cafe Billing System Program
 * By [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants
#define MAX_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 20

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int numOfItems = 0;
    float totalCost = 0.0;

    printf("***Welcome to C Cafe***\n");

    while (1) { // Main loop
        printf("Enter item name (or 'q' to quit): ");
        char input[MAX_ITEM_NAME_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break; // Exiting loop
        }

        printf("Enter price: ");
        float price;
        scanf("%f", &price);

        Item newItem;
        strcpy(newItem.name, input);
        newItem.price = price;

        items[numOfItems++] = newItem;
    }

    printf("\n------------------------------\n");
    printf("Your Order:\n");

    for (int i = 0; i < numOfItems; i++) { // Displaying order
        printf("%s - $%.2f\n", items[i].name, items[i].price);
        totalCost += items[i].price;
    }

    printf("------------------------------\n");
    printf("Total Cost: $%.2f\n", totalCost);
    printf("Thank you for choosing C Cafe! Have a nice day!\n");

    return 0;
}
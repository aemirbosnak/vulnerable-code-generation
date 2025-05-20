//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem {
    char name[20];
    int quantity;
    double price;
    double totalCost;
} ExpenseItem;

int main() {
    ExpenseItem items[MAX_EXPENSE_ITEMS];
    int numItems = 0;

    // Create a loop to add items until the user enters a negative number
    while (1) {
        printf("Enter the name of the item: ");
        scanf("%s", items[numItems].name);

        printf("Enter the quantity of the item: ");
        scanf("%d", &items[numItems].quantity);

        printf("Enter the price of the item: ");
        scanf("%lf", &items[numItems].price);

        items[numItems].totalCost = items[numItems].quantity * items[numItems].price;
        numItems++;

        printf("Enter the next item (or a negative number to quit): ");
        int nextItem = scanf("%d");

        if (nextItem < 0) {
            break;
        }
    }

    // Calculate the total cost of all items
    double totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].totalCost;
    }

    // Print the total cost
    printf("Total cost: $%.2lf\n", totalCost);

    return 0;
}
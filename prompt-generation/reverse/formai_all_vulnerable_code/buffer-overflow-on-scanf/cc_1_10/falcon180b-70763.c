//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

int main() {
    int numItems = 0;
    Item items[MAX_ITEMS];

    printf("Welcome to the Expense Tracker!\n");

    // Add items
    while(1) {
        printf("\nAdd an item (type 'done' to finish):\n");
        printf("Name: ");
        scanf("%s", items[numItems].name);

        if(strcmp(items[numItems].name, "done") == 0) {
            break;
        }

        printf("Price: ");
        scanf("%f", &items[numItems].price);

        numItems++;

        if(numItems >= MAX_ITEMS) {
            printf("\nError: Maximum number of items reached.\n");
            exit(1);
        }
    }

    // Display items
    printf("\nItems:\n");
    for(int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }

    // Calculate total cost
    float totalCost = 0;
    for(int i = 0; i < numItems; i++) {
        totalCost += items[i].price;
    }

    printf("\nTotal cost: $%.2f\n", totalCost);

    return 0;
}
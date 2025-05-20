//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_QUANTITY 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int numItems, char name[], int quantity, float price) {
    if (numItems >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[numItems].name, name);
    items[numItems].quantity = quantity;
    items[numItems].price = price;

    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculateTotal(Item items[], int numItems, float total) {
    for (int i = 0; i < numItems; i++) {
        total += items[i].quantity * items[i].price;
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;

    printf("Welcome to the Cafe Billing System!\n");

    int numItems = 0;
    Item items[MAX_ITEMS];

    while (1) {
        printf("Enter item name (or 'done' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price: ");
        scanf("%f", &price);

        addItem(items, numItems, name, quantity, price);
    }

    printf("\nOrder Summary:\n");
    displayItems(items, numItems);

    float total = 0;
    calculateTotal(items, numItems, total);

    printf("\nTotal: $%.2f\n", total);

    return 0;
}
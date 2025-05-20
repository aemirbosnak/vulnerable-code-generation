//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} Item;

void addItem(Item items[], int count, char name[], char price[], int quantity) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached\n");
        return;
    }

    strcpy(items[count].name, name);
    strcpy(items[count].price, price);
    items[count].quantity = quantity;
    count++;
}

void displayItems(Item items[], int count) {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int count) {
    double totalCost = 0;
    for (int i = 0; i < count; i++) {
        double itemCost = atof(items[i].price) * items[i].quantity;
        totalCost += itemCost;
    }
    printf("Total Cost: $%.2f\n", totalCost);
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;

    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;

    do {
        printf("Enter item name (or type 'done' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "done")!= 0) {
            printf("Enter item price: ");
            scanf("%s", price);

            printf("Enter item quantity: ");
            scanf("%d", &quantity);

            addItem(items, count, name, price, quantity);
            count++;
        }
    } while (strcmp(name, "done")!= 0);

    displayItems(items, count);
    calculateTotal(items, count);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 0, 5.0},
    {"Tea", 0, 3.0},
    {"Juice", 0, 4.0},
    {"Soda", 0, 2.0},
    {"Water", 0, 1.0}
};

void updateItemQuantity(char *itemName, int quantity) {
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            items[i].quantity = quantity;
            break;
        }
    }
}

double calculateTotal(int numItems) {
    double total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

int main() {
    char itemName[20];
    int itemQuantity;
    double totalCost;
    int numItems = 0;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop until the customer enters "quit"
    while (strcmp(itemName, "quit") != 0) {
        printf("Enter item name: ");
        scanf("%s", itemName);

        printf("Enter item quantity: ");
        scanf("%d", &itemQuantity);

        updateItemQuantity(itemName, itemQuantity);

        numItems++;
    }

    totalCost = calculateTotal(numItems);

    printf("Total cost: $%.2lf\n", totalCost);

    return 0;
}
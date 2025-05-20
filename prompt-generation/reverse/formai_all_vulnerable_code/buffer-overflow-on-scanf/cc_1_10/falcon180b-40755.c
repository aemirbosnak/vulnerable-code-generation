//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 20
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} item;

void addItem(item *menu, int *numItems) {
    printf("Enter name of item: ");
    scanf("%s", menu[*numItems].name);
    printf("Enter price of item: $");
    scanf("%f", &menu[*numItems].price);
    printf("\n");
    (*numItems)++;
}

void displayMenu(item *menu, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("\n");
}

void takeOrder(item *menu, int numItems, float *total) {
    char order[MAX_NAME];
    int itemIndex;
    float itemPrice;

    printf("Enter order (name of item): ");
    scanf("%s", order);

    itemIndex = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(menu[i].name, order) == 0) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Item not found.\n");
        return;
    }

    itemPrice = menu[itemIndex].price;
    (*total) += itemPrice;

    printf("Order placed: %s $%.2f\n", order, itemPrice);
    printf("Total bill: $%.2f\n", *total);
    printf("\n");
}

int main() {
    item menu[MAX_ITEMS];
    int numItems = 0;
    float total = 0;

    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    displayMenu(menu, numItems);

    takeOrder(menu, numItems, &total);

    return 0;
}
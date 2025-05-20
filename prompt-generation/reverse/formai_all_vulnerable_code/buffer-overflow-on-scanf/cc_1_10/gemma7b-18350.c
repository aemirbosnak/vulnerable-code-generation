//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_STOCK 10

typedef struct Item {
    char name[50];
    int stock;
    double price;
} Item;

Item items[MAX_ITEMS];

void manageItems(void) {
    int i, itemNo = 0;

    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].stock = 0;
        items[i].price = 0.0;
    }

    itemNo = addItem();

    if (itemNo != -1) {
        printf("Item %s added successfully.\n", items[itemNo].name);
    }
}

int addItem(void) {
    int i;

    for (i = 0; items[i].name[0] != '\0'; i++) {
        ;
    }

    if (i == MAX_ITEMS) {
        return -1;
    }

    printf("Enter item name: ");
    scanf("%s", items[i].name);

    printf("Enter item stock: ");
    scanf("%d", &items[i].stock);

    printf("Enter item price: ");
    scanf("%lf", &items[i].price);

    return i;
}

int main(void) {
    manageItems();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

void addItem(Item* menu, int* numItems) {
    printf("Enter item name: ");
    scanf("%s", menu[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &menu[*numItems].price);
    (*numItems)++;
}

void displayMenu(Item* menu, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void takeOrder(Item* menu, int numItems, float* totalPrice) {
    int numOrders = 0;
    float orderPrice[MAX_ITEMS];

    printf("Enter order:\n");
    while (numOrders < MAX_ITEMS && scanf("%d", &orderPrice[numOrders]) == 1) {
        numOrders++;
    }

    for (int i = 0; i < numOrders; i++) {
        for (int j = 0; j < numItems; j++) {
            if (menu[j].price == orderPrice[i]) {
                printf("Ordering %s...\n", menu[j].name);
                (*totalPrice) += menu[j].price;
                break;
            }
        }
    }
}

int main() {
    Item menu[MAX_ITEMS];
    int numItems = 0;

    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    displayMenu(menu, numItems);

    float totalPrice = 0;
    takeOrder(menu, numItems, &totalPrice);

    printf("Total price: $%.2f\n", totalPrice);

    return 0;
}
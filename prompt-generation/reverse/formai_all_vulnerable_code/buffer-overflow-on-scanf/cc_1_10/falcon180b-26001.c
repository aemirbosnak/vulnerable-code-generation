//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} item;

void addItem(item *items, int *numItems) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*numItems].name);

    printf("Enter the price of the item: ");
    scanf("%f", &items[*numItems].price);

    (*numItems)++;
}

void printMenu(item *items, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void placeOrder(item *items, int numItems) {
    int choice;
    float totalPrice = 0;

    printf("Enter your order (1-%d): ", numItems);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numItems) {
        totalPrice += items[choice-1].price;
        printf("Your order of %s has been placed. Your total is $%.2f.\n", items[choice-1].name, totalPrice);
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    item menu[MAX_ITEMS];
    int numItems = 0;

    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    printf("Welcome to the cafe! Here's our menu:\n");
    printMenu(menu, numItems);

    int choice;
    while (1) {
        printf("Enter 1 to place an order, 2 to add an item, or any other key to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            placeOrder(menu, numItems);
        } else if (choice == 2) {
            addItem(menu, &numItems);
            printf("Menu updated:\n");
            printMenu(menu, numItems);
        } else {
            break;
        }
    }

    return 0;
}
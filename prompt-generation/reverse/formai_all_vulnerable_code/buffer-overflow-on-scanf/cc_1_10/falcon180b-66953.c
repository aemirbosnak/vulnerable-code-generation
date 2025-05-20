//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double price;
    int quantity;
} item;

void addItem(item* items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[numItems].name);
    printf("Enter item price: ");
    scanf("%lf", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
}

void displayItems(item* items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: %s - $%.2lf - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(item* items, int numItems) {
    double total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("Total cost: $%.2lf\n", total);
}

int main() {
    item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("Do you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            addItem(items, numItems);
            numItems++;
        } else {
            printf("Calculating total...\n");
            calculateTotal(items, numItems);
            break;
        }
    }

    return 0;
}
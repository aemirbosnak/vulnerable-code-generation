//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int count, char name[], int quantity, double price) {
    if (count < MAX_ITEMS) {
        strcpy(items[count].name, name);
        items[count].quantity = quantity;
        items[count].price = price;
        count++;
    }
}

void displayItems(Item items[], int count) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculateTotal(Item items[], int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;

    char name[50];
    int quantity;
    double price;

    printf("Welcome to the Cafe Billing System!\n");

    while (1) {
        printf("Enter item name: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price: ");
        scanf("%lf", &price);

        addItem(items, count, name, quantity, price);
        count++;
    }

    displayItems(items, count);
    calculateTotal(items, count);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void addItem(item *list, int *count) {
    char name[50];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%f", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    strcpy(list[*count].name, name);
    list[*count].price = price;
    list[*count].quantity = quantity;

    (*count)++;
}

void displayItems(item *list, int count) {
    int i;

    printf("\nItem Name\tPrice\tQuantity\n");

    for (i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", list[i].name, list[i].price, list[i].quantity);
    }
}

void calculateTotalCost(item *list, int count) {
    int i;
    float totalCost = 0.0;

    for (i = 0; i < count; i++) {
        totalCost += list[i].price * list[i].quantity;
    }

    printf("\nTotal cost: $%.2f\n", totalCost);
}

int main() {
    item list[MAX_ITEMS];
    int count = 0;

    printf("Enter number of items: ");
    scanf("%d", &count);

    printf("\nEnter item details:\n");

    while (count > 0 && count <= MAX_ITEMS) {
        addItem(list, &count);
    }

    printf("\nItems added:\n");
    displayItems(list, count);

    calculateTotalCost(list, count);

    return 0;
}
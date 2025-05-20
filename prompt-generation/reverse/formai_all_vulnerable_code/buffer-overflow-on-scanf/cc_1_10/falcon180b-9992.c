//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int price;
} Item;

void readItems(Item items[], int *numItems) {
    printf("Enter the number of items: ");
    scanf("%d", numItems);

    for (int i = 0; i < *numItems; i++) {
        printf("Enter item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Description: ");
        scanf("%s", items[i].description);
        printf("Price: ");
        scanf("%d", &items[i].price);
    }
}

void calculateTotal(Item items[], int numItems, int quantity[], float *total) {
    *total = 0.0;

    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < numItems; j++) {
            if (i!= j) {
                *total += items[i].price * quantity[i];
            }
        }
    }
}

void printBill(Item items[], int numItems, int quantity[], float total) {
    printf("Item\tDescription\tQuantity\tPrice\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t%s\t%d\t%d\n", items[i].name, items[i].description, quantity[i], items[i].price);
    }

    printf("\nTotal: %.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    int quantity[MAX_ITEMS] = {0};
    float total = 0.0;

    readItems(items, &numItems);
    calculateTotal(items, numItems, quantity, &total);
    printBill(items, numItems, quantity, total);

    return 0;
}
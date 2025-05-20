//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50
#define MAX_PRICE_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    char price[MAX_PRICE_SIZE];
} Item;

void addItem(Item items[], int count, char name[], char price[]) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[count].name, name);
    strcpy(items[count].price, price);

    count++;
}

void printItems(Item items[], int count) {
    printf("Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%s\n", items[i].name, items[i].price);
    }
}

int main() {
    char name[MAX_NAME_SIZE];
    char price[MAX_PRICE_SIZE];
    int count = 0;
    Item items[MAX_ITEMS];

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%s", price);

    addItem(items, count, name, price);

    printf("Do you want to add another item? (Y/N): ");
    char choice;
    scanf("%c", &choice);

    while (choice == 'Y' || choice == 'y') {
        printf("Enter item name: ");
        scanf("%s", name);

        printf("Enter item price: ");
        scanf("%s", price);

        addItem(items, count, name, price);

        printf("Do you want to add another item? (Y/N): ");
        scanf("%c", &choice);
    }

    printItems(items, count);

    return 0;
}
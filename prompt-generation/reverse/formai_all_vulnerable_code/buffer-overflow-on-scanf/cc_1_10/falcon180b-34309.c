//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} Item;

void addItem(Item *items, int count, char name[], float price) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].price = price;
    count++;
}

void removeItem(Item *items, int count) {
    if (count <= 0) {
        printf("Error: No items to remove.\n");
        return;
    }
    count--;
}

void displayItems(Item *items, int count) {
    printf("Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void calculateTotal(Item *items, int count, float *total) {
    *total = 0;
    for (int i = 0; i < count; i++) {
        *total += items[i].price;
    }
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    char name[MAX_NAME];
    float price;
    float total = 0;

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Calculate total\n5. Exit\n");
        scanf("%d", &count);

        switch (count) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: $");
                scanf("%f", &price);
                addItem(items, count, name, price);
                break;
            case 2:
                removeItem(items, count);
                break;
            case 3:
                displayItems(items, count);
                break;
            case 4:
                calculateTotal(items, count, &total);
                printf("Total: $%.2f\n", total);
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid option.\n");
        }
    }

    return 0;
}
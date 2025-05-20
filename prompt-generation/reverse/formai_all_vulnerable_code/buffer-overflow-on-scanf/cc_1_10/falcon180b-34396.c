//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100
#define MAX_QTY_ON_HAND 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int qty_on_hand;
    double price;
} Item;

void add_item(Item *items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the description of the item: ");
    scanf("%s", items[num_items].description);
    printf("Enter the quantity on hand: ");
    scanf("%d", &items[num_items].qty_on_hand);
    printf("Enter the price of the item: $");
    scanf("%lf", &items[num_items].price);
}

void display_items(Item *items, int num_items) {
    printf("\nName\tDescription\tQty on Hand\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s", items[i].name);
        printf("%-30s", items[i].description);
        printf("%-10d", items[i].qty_on_hand);
        printf("%-10.2lf\n", items[i].price);
    }
}

int main() {
    Item items[MAX_NUM_ITEMS];
    int num_items = 0;

    while (num_items < MAX_NUM_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_item(items, num_items);
            num_items++;
        } else {
            break;
        }
    }

    printf("\nItems in the store:\n");
    display_items(items, num_items);

    return 0;
}
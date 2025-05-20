//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_DESC_LEN 200
#define MAX_QTY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int qty;
    float price;
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter item name (or 'done' to finish): ");
        scanf("%s", items[num_items].name);

        if (strcmp(items[num_items].name, "done") == 0) {
            break;
        }

        printf("Enter item description: ");
        scanf("%s", items[num_items].description);

        printf("Enter item quantity: ");
        scanf("%d", &items[num_items].qty);

        printf("Enter item price: ");
        scanf("%f", &items[num_items].price);

        num_items++;
    }

    printf("Product Inventory:\n");
    printf("-----------------\n");
    printf("Name\tDescription\tQty\tPrice\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%d\t%.2f\n", items[i].name, items[i].description, items[i].qty, items[i].price);
    }

    return 0;
}
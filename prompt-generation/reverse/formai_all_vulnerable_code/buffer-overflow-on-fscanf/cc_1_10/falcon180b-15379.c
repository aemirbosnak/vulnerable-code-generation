//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} Item;

int main() {
    int numItems = 0;
    Item items[MAX_ITEMS];
    FILE *fp;

    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read items from file
    while (fscanf(fp, "%s %s %s %s %s %d", items[numItems].name, items[numItems].description, items[numItems].category, items[numItems].price, items[numItems].price, &items[numItems].quantity) == 6) {
        numItems++;
        if (numItems >= MAX_ITEMS) {
            printf("Maximum number of items reached.\n");
            break;
        }
    }

    fclose(fp);

    if (numItems == 0) {
        printf("No items found in file.\n");
        return 1;
    }

    // Display items
    printf("Item Name\tItem Description\tItem Category\tItem Price\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%s\t\t%s\t\t$%s\t\t%d\n", items[i].name, items[i].description, items[i].category, items[i].price, items[i].quantity);
    }

    return 0;
}
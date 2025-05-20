//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_BRAND_LENGTH 50
#define MAX_QUANTITY_LENGTH 10
#define MAX_PRICE_LENGTH 10

struct item {
    char name[MAX_NAME_LENGTH];
    char brand[MAX_BRAND_LENGTH];
    int quantity;
    float price;
};

void add_item(struct item* items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the brand of the item: ");
    scanf("%s", items[num_items].brand);
    printf("Enter the quantity of the item: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_items(struct item* items, int num_items) {
    printf("\nItem Name\tItem Brand\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s\t%-20s\t\t%10d\t\t$%10.2f\n", items[i].name, items[i].brand, items[i].quantity, items[i].price);
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter the number of items you want to add: ");
    scanf("%d", &num_items);

    printf("\nEnter the details of the items:\n");
    for (int i = 0; i < num_items; i++) {
        add_item(items, num_items);
    }

    printf("\nThe items added are:\n");
    display_items(items, num_items);

    return 0;
}
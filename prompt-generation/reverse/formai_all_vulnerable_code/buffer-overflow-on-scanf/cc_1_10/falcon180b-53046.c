//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QTY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char qty[MAX_QTY_LEN];
    char price[MAX_PRICE_LEN];
} item_t;

void add_item(item_t *items, int n_items, char *name, char *qty, char *price) {
    strcpy(items[n_items].name, name);
    strcpy(items[n_items].qty, qty);
    strcpy(items[n_items].price, price);
}

void display_items(item_t *items, int n_items) {
    printf("Item\tQuantity\tPrice\n");
    for (int i = 0; i < n_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].qty, items[i].price);
    }
}

void calculate_total(item_t *items, int n_items) {
    float total = 0.0;
    for (int i = 0; i < n_items; i++) {
        total += atof(items[i].price) * atoi(items[i].qty);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    item_t items[MAX_ITEMS];
    int n_items = 0;

    printf("Enter name of item 1: ");
    scanf("%s", items[n_items].name);
    printf("Enter quantity of item 1: ");
    scanf("%s", items[n_items].qty);
    printf("Enter price of item 1: ");
    scanf("%s", items[n_items].price);
    n_items++;

    printf("Enter name of item 2: ");
    scanf("%s", items[n_items].name);
    printf("Enter quantity of item 2: ");
    scanf("%s", items[n_items].qty);
    printf("Enter price of item 2: ");
    scanf("%s", items[n_items].price);
    n_items++;

    printf("Enter name of item 3: ");
    scanf("%s", items[n_items].name);
    printf("Enter quantity of item 3: ");
    scanf("%s", items[n_items].qty);
    printf("Enter price of item 3: ");
    scanf("%s", items[n_items].price);
    n_items++;

    display_items(items, n_items);
    calculate_total(items, n_items);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Item;

void add_item(Item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void print_items(Item *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void print_bill(Item *items, int num_items) {
    printf("Bill:\n");
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    print_items(items, num_items);
    print_bill(items, num_items);

    return 0;
}
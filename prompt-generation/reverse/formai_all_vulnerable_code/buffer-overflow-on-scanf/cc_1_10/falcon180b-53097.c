//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

void add_item(item* items, int count, char* name, char* price) {
    strcpy(items[count].name, name);
    strcpy(items[count].price, price);
}

void print_item(item item) {
    printf("Name: %s\nPrice: %s\n", item.name, item.price);
}

void print_items(item items[], int count) {
    for (int i = 0; i < count; i++) {
        print_item(items[i]);
    }
}

int main() {
    item items[MAX_ITEMS];
    int count = 0;
    char input[MAX_PRICE_LEN];

    printf("Enter the name and price of an item (name price):\n");
    scanf("%s %s", input, input);
    add_item(items, count++, input, input);

    while (1) {
        printf("Enter the name and price of an item (name price):\n");
        scanf("%s %s", input, input);

        if (strlen(input) == 0) {
            printf("Invalid input.\n");
            continue;
        }

        add_item(items, count++, input, input);
    }

    printf("Items:\n");
    print_items(items, count);

    return 0;
}
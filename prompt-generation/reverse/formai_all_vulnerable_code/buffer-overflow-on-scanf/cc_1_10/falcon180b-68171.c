//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} item_t;

void add_item(item_t *items, int num_items, char *name, char *amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strncpy(items[num_items].name, name, MAX_NAME_LENGTH);
    strncpy(items[num_items].amount, amount, MAX_AMOUNT_LENGTH);

    num_items++;
}

void display_items(item_t *items, int num_items) {
    printf("Name\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];

    while (1) {
        printf("\nEnter name of expense (or type 'display' to view expenses): ");
        scanf("%s", name);

        if (strcmp(name, "display") == 0) {
            display_items(items, num_items);
        } else {
            printf("\nEnter amount of expense: ");
            scanf("%s", amount);

            add_item(items, num_items, name, amount);
        }
    }

    return 0;
}
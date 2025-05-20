//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: automated
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
        printf("Error: Too many items\n");
        return;
    }

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].amount, amount);

    num_items++;
}

void print_items(item_t *items, int num_items) {
    printf("Name\tAmount\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

void calculate_total(item_t *items, int num_items, char *result) {
    int total = 0;

    for (int i = 0; i < num_items; i++) {
        total += atoi(items[i].amount);
    }

    sprintf(result, "Total: $%d", total);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;
    char input[100];

    while (num_items < MAX_ITEMS) {
        printf("Enter item name (or 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter item amount: ");
        scanf("%s", input);

        add_item(items, num_items, input, input);
    }

    print_items(items, num_items);
    calculate_total(items, num_items, input);

    printf("%s\n", input);

    return 0;
}
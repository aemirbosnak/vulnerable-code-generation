//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
} item_t;

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter name of item (or 'done' to finish): ");
        scanf("%s", items[num_items].name);

        if (strcmp(items[num_items].name, "done") == 0) {
            break;
        }

        printf("Enter price of %s: ", items[num_items].name);
        scanf("%lf", &items[num_items].price);

        printf("Enter quantity of %s: ", items[num_items].name);
        scanf("%d", &items[num_items].quantity);

        num_items++;
    }

    printf("\nExpense Tracker\n");
    printf("================\n");

    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2lf\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }

    double total_expense = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_expense += items[i].price * items[i].quantity;
    }

    printf("\nTotal Expense: $%.2lf\n", total_expense);

    return 0;
}
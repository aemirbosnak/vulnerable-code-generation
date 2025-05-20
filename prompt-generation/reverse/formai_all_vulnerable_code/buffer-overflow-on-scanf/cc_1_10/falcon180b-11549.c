//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    double cost;
} item_t;

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter item name (or 'done' to finish): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);

        if (!strcmp(name, "done")) {
            break;
        }

        printf("Enter item description: ");
        char description[MAX_DESC_LEN];
        scanf("%s", description);

        printf("Enter item cost: ");
        double cost;
        scanf("%lf", &cost);

        strcpy(items[num_items].name, name);
        strcpy(items[num_items].description, description);
        items[num_items].cost = cost;
        num_items++;
    }

    printf("Expense tracker\n");
    printf("=================\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f - %s\n", items[i].name, items[i].cost, items[i].description);
    }

    return 0;
}
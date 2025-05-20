//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
} item_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_items;
    item_t items[MAX_ITEMS];
} category_t;

int main() {
    int num_categories;
    category_t categories[MAX_CATEGORIES];
    int i, j, k;

    num_categories = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("Enter category name (or 'done'): ");
        scanf("%s", categories[num_categories].name);

        if (strcmp(categories[num_categories].name, "done") == 0) {
            break;
        }

        num_categories++;
    }

    for (i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        categories[i].num_items = 0;
    }

    while (1) {
        printf("Enter item name: ");
        scanf("%s", categories[0].items[categories[0].num_items].name);
        printf("Enter item amount: ");
        scanf("%lf", &categories[0].items[categories[0].num_items].amount);

        for (i = 1; i < num_categories; i++) {
            for (j = 0; j < categories[i].num_items; j++) {
                if (strcmp(categories[i].items[j].name, categories[0].items[categories[0].num_items].name) == 0) {
                    printf("Item already exists in category '%s'.\n", categories[i].name);
                    break;
                }
            }
        }

        if (i == num_categories) {
            categories[0].num_items++;
        }
    }

    for (i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (j = 0; j < categories[i].num_items; j++) {
            printf("- %s: $%.2f\n", categories[i].items[j].name, categories[i].items[j].amount);
        }
    }

    return 0;
}
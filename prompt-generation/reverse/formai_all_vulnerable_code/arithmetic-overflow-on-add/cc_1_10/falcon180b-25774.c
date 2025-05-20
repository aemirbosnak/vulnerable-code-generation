//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} item_t;

void add_item(item_t *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item category: ");
    scanf("%s", items[*num_items].category);
    printf("Enter item amount: ");
    scanf("%s", items[*num_items].amount);

    (*num_items)++;
}

void display_items(item_t *items, int num_items) {
    printf("\nItem Name\tItem Category\tItem Amount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].category, items[i].amount);
    }
}

void calculate_total(item_t *items, int num_items, char *category, float *total) {
    int count = 0;
    float amount_total = 0.0;

    *total = 0.0;

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].category, category) == 0) {
            amount_total += atof(items[i].amount);
            count++;
        }
    }

    *total = amount_total / count;
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        add_item(items, &num_items);
    }

    char category[MAX_NAME_LENGTH];
    float total = 0.0;

    printf("\nEnter category to calculate total: ");
    scanf("%s", category);

    calculate_total(items, num_items, category, &total);

    printf("\nTotal for %s: $%.2f\n", category, total);

    return 0;
}
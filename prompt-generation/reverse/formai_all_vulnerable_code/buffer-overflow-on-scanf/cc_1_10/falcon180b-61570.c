//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} item;

void add_item(item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item category: ");
    scanf("%s", items[*num_items].category);
    printf("Enter item amount: ");
    scanf("%s", items[*num_items].amount);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("\nItem Name\t\tItem Category\t\tItem Amount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%s\t\t%s\n", items[i].name, items[i].category, items[i].amount);
    }
}

void calculate_total_expenses(item *items, int num_items, char *category, float *total_expenses) {
    int count = 0;
    float expenses = 0.0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].category, category) == 0) {
            expenses += atof(items[i].amount);
            count++;
        }
    }
    if (count > 0) {
        *total_expenses = expenses / count;
    } else {
        *total_expenses = 0.0;
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    char category[MAX_CATEGORY_LEN];
    float total_expenses;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        add_item(items, &num_items);
    }

    printf("\nEnter category to calculate total expenses: ");
    scanf("%s", category);

    calculate_total_expenses(items, num_items, category, &total_expenses);

    printf("\nTotal expenses for %s: $%.2f\n", category, total_expenses);

    display_items(items, num_items);

    return 0;
}
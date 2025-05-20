//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

void add_item(item *list, int num_items, char *name, float amount, int category) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Cannot add more than %d items.\n", MAX_ITEMS);
        return;
    }
    strcpy(list[num_items].name, name);
    list[num_items].amount = amount;
    list[num_items].category = category;
    num_items++;
}

void display_items(item *list, int num_items) {
    printf("Item\tAmount\tCategory\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", list[i].name, list[i].amount, list[i].category);
    }
}

void calculate_total(item *list, int num_items, int category, float *total) {
    *total = 0;
    for (int i = 0; i < num_items; i++) {
        if (list[i].category == category) {
            *total += list[i].amount;
        }
    }
}

int main() {
    item list[MAX_ITEMS];
    int num_items = 0;
    char name[50];
    float amount;
    int category;

    printf("Personal Finance Planner\n");
    printf("Enter item name, amount and category (1: Income, 2: Expense)\n");

    while (1) {
        printf("Enter 'q' to quit or any other key to continue: ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }
        printf("Enter amount: ");
        scanf("%f", &amount);
        printf("Enter category (1: Income, 2: Expense): ");
        scanf("%d", &category);
        add_item(list, num_items, name, amount, category);
        num_items++;
    }

    printf("\nItem\tAmount\tCategory\n");
    display_items(list, num_items);

    float income_total, expense_total;
    calculate_total(list, num_items, 1, &income_total);
    calculate_total(list, num_items, 2, &expense_total);

    printf("\nTotal Income: %.2f\nTotal Expense: %.2f\n", income_total, expense_total);

    return 0;
}
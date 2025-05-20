//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    double price;
} item_t;

void add_item(item_t* items, int* num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);

    printf("Enter item description: ");
    scanf("%s", items[*num_items].description);

    printf("Enter item price: $");
    scanf("%lf", &items[*num_items].price);

    (*num_items)++;
}

void display_items(item_t* items, int num_items) {
    printf("\nItem List:\n");
    printf("-----------------------------------------------------\n");
    printf("Name\t\tDescription\tPrice\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-40s $%.2lf\n", items[i].name, items[i].description, items[i].price);
    }

    printf("-----------------------------------------------------\n");
}

void sort_items(item_t* items, int num_items, int sort_by) {
    int i, j;
    item_t temp;

    for (i = 0; i < num_items - 1; i++) {
        for (j = i + 1; j < num_items; j++) {
            if (sort_by == 1) { // sort by name
                if (strcmp(items[i].name, items[j].name) > 0) {
                    temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            } else if (sort_by == 2) { // sort by description
                if (strcmp(items[i].description, items[j].description) > 0) {
                    temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            } else if (sort_by == 3) { // sort by price
                if (items[i].price > items[j].price) {
                    temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            }
        }
    }
}

void calculate_total_expense(item_t* items, int num_items) {
    double total_expense = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_expense += items[i].price;
    }

    printf("\nTotal Expense: $%.2lf\n", total_expense);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    display_items(items, num_items);
    sort_items(items, num_items, 1); // sort by name
    display_items(items, num_items);
    calculate_total_expense(items, num_items);

    return 0;
}
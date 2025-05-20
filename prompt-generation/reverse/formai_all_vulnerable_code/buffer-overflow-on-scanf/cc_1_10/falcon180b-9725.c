//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} item;

void add_item(item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[*num_items].amount);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("\nItem Name\tItem Amount\n");
    for(int i=0; i<num_items; i++) {
        printf("%s\t\t%s\n", items[i].name, items[i].amount);
    }
}

void calculate_total_expense(item *items, int num_items) {
    float total_expense=0.0;
    for(int i=0; i<num_items; i++) {
        total_expense += atof(items[i].amount);
    }
    printf("\nTotal Expense: %.2f", total_expense);
}

int main() {
    item items[MAX_ITEMS];
    int num_items=0;

    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    display_items(items, num_items);

    calculate_total_expense(items, num_items);

    return 0;
}
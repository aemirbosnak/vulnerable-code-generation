//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double amount;
} item;

void add_item(item* items, int* num_items, char* name, char* category, double amount) {
    strncpy(items[*num_items].name, name, MAX_NAME_LEN);
    strncpy(items[*num_items].category, category, MAX_CATEGORY_LEN);
    items[*num_items].amount = amount;
    (*num_items)++;
}

void display_items(item* items, int num_items) {
    printf("Item Name | Category | Amount\n");
    for(int i = 0; i < num_items; i++) {
        printf("%-20s | %-20s | $%.2f\n", items[i].name, items[i].category, items[i].amount);
    }
}

void calculate_total(item* items, int num_items, double* total) {
    *total = 0;
    for(int i = 0; i < num_items; i++) {
        *total += items[i].amount;
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    double total = 0;

    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double amount;

    printf("Personal Finance Planner\n");

    while(1) {
        printf("Enter item name (press enter to finish): ");
        scanf("%s", name);

        if(name[0] == '\0') {
            break;
        }

        printf("Enter item category: ");
        scanf("%s", category);

        printf("Enter item amount: ");
        scanf("%lf", &amount);

        add_item(items, &num_items, name, category, amount);
    }

    display_items(items, num_items);

    printf("\nTotal: $%.2f\n", total);

    return 0;
}
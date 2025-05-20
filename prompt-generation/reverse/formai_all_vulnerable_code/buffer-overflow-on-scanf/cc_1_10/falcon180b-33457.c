//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} item;

void add_item(item* list, int num_items, char* name, char* amount) {
    if (num_items == MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(list[num_items].name, name);
    strcpy(list[num_items].amount, amount);
    num_items++;
}

void display_items(item* list, int num_items) {
    printf("Item\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", list[i].name, list[i].amount);
    }
}

void calculate_total(item* list, int num_items, float* total) {
    for (int i = 0; i < num_items; i++) {
        *total += atof(list[i].amount);
    }
}

int main() {
    item expenses[MAX_ITEMS];
    int num_expenses = 0;
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
    float total = 0.0;

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("Enter item name: ");
        scanf("%s", name);
        if (strlen(name) == 0) {
            printf("Error: Empty name.\n");
            continue;
        }
        printf("Enter item amount: ");
        scanf("%s", amount);
        if (strlen(amount) == 0) {
            printf("Error: Empty amount.\n");
            continue;
        }
        add_item(expenses, num_expenses, name, amount);
        num_expenses++;
    }

    display_items(expenses, num_expenses);
    calculate_total(expenses, num_expenses, &total);

    printf("\nTotal expenses: $%.2f\n", total);

    return 0;
}
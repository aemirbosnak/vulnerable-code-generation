//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float cost;
};

void add_item(struct item *items, int *num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);
    printf("Enter the cost of the item: $");
    scanf("%f", &items[*num_items].cost);
    (*num_items)++;
}

void display_items(struct item *items, int num_items) {
    printf("Item\t\tCost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t$%.2f\n", items[i].name, items[i].cost);
    }
}

void calculate_total_cost(struct item *items, int num_items, float *total_cost) {
    *total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        *total_cost += items[i].cost;
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    float total_cost = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (num_items < MAX_ITEMS) {
        printf("\nEnter 1 to add an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_item(items, &num_items);
        } else if (choice!= 0) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nExpense Report:\n");
    display_items(items, num_items);

    calculate_total_cost(items, num_items, &total_cost);
    printf("\nTotal cost: $%.2f\n", total_cost);

    return 0;
}
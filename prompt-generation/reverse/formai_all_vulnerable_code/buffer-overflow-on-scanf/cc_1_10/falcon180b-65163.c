//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

void add_item(item *items, int num_items, char *name, float amount, int category) {
    if (num_items == MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    items[num_items].category = category;

    num_items++;
}

void print_items(item *items, int num_items) {
    printf("Items:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].amount, items[i].category);
    }
}

void calculate_total(item *items, int num_items, float *total, int category) {
    *total = 0;

    for (int i = 0; i < num_items; i++) {
        if (items[i].category == category) {
            *total += items[i].amount;
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    char name[50];
    float amount;
    int category;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("Enter item name: ");
        scanf("%s", name);

        printf("Enter item amount: ");
        scanf("%f", &amount);

        printf("Enter item category (1 - Food, 2 - Clothing, 3 - Entertainment): ");
        scanf("%d", &category);

        add_item(items, num_items, name, amount, category);

        printf("\nItem added.\n");

        printf("Press 1 to add another item, 2 to view items, 3 to calculate total, or 4 to exit: ");
        scanf("%d", &category);

        switch (category) {
            case 1:
                break;
            case 2:
                print_items(items, num_items);
                break;
            case 3:
                calculate_total(items, num_items, &amount, category);
                printf("Total spent on %s: $%.2f\n", (category == 1)? "Food" : (category == 2)? "Clothing" : "Entertainment", amount);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_ITEMS 100

struct Item {
    char name[MAX_LINE_LEN];
    double cost;
};

// function prototypes
int add_item(struct Item items[MAX_ITEMS], int num_items);
void print_items(struct Item items[MAX_ITEMS], int num_items);
double total_expenses(struct Item items[MAX_ITEMS], int num_items);

int main() {
    struct Item items[MAX_ITEMS];
    int num_items = 0;
    char option;

    while (1) {
        printf("Enter option (a=add, p=print, t=total, q=quit): ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                num_items = add_item(items, num_items);
                break;
            case 'p':
                print_items(items, num_items);
                break;
            case 't':
                printf("Total expenses: %.2lf\n", total_expenses(items, num_items));
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

// function to add an item to the expense tracker
int add_item(struct Item items[MAX_ITEMS], int num_items) {
    if (num_items == MAX_ITEMS) {
        printf("Sorry, you have reached the maximum number of items.\n");
        return num_items;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]s", items[num_items].name);
    printf("Enter item cost: ");
    scanf(" %lf", &items[num_items].cost);

    num_items++;
    printf("Item added successfully!\n");
    return num_items;
}

// function to print all items in the expense tracker
void print_items(struct Item items[MAX_ITEMS], int num_items) {
    if (num_items == 0) {
        printf("No items to display.\n");
        return;
    }

    printf("List of items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2lf\n", items[i].name, items[i].cost);
    }
}

// function to calculate the total expenses in the expense tracker
double total_expenses(struct Item items[MAX_ITEMS], int num_items) {
    double total = 0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].cost;
    }

    return total;
}
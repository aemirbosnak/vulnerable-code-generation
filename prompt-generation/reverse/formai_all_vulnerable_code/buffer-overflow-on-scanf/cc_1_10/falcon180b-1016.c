//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    float cost;
} item_t;

void add_item(item_t items[], int num_items) {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    float cost;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item description: ");
    scanf("%s", description);

    printf("Enter item cost: ");
    scanf("%f", &cost);

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].description, description);
    items[num_items].cost = cost;

    num_items++;
}

void display_items(item_t items[], int num_items) {
    int i;

    printf("Item Name | Item Description | Cost\n");
    for (i = 0; i < num_items; i++) {
        printf("%-20s | %-40s | $%7.2f\n", items[i].name, items[i].description, items[i].cost);
    }
}

void calculate_total_cost(item_t items[], int num_items) {
    int i;
    float total_cost = 0.0;

    for (i = 0; i < num_items; i++) {
        total_cost += items[i].cost;
    }

    printf("\nTotal cost: $%7.2f\n", total_cost);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Expense Tracker\n");
    printf("==============\n");

    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Calculate total cost\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_items);

        switch (num_items) {
        case 1:
            if (num_items >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                add_item(items, num_items);
            }
            break;

        case 2:
            if (num_items == 0) {
                printf("No items added.\n");
            } else {
                display_items(items, num_items);
            }
            break;

        case 3:
            if (num_items == 0) {
                printf("No items added.\n");
            } else {
                calculate_total_cost(items, num_items);
            }
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
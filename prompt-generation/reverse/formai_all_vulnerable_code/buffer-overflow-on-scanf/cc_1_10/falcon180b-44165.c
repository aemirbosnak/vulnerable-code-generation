//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void add_item(item *items, int num_items) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
}

void display_items(item *items, int num_items) {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(item *items, int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("\nTotal Cost: $%.2f\n", total_cost);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Item\n2. Display Items\n3. Calculate Total Cost\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_items >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                add_item(items, num_items);
                num_items++;
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
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
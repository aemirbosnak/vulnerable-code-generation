//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void add_item(item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(item *items, int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("\nTotal cost: $%.2f", total_cost);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Expense Tracker!\n");
    while (num_items < MAX_ITEMS) {
        printf("\nEnter 1 to add an item or 0 to display items and calculate total cost:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_item(items, &num_items);
        } else if (choice == 0) {
            display_items(items, num_items);
            calculate_total_cost(items, num_items);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
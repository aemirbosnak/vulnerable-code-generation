//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item_t;

void add_item(item_t *items, int count) {
    printf("Enter the name of the item: ");
    scanf("%s", &items[count].name);
    printf("Enter the price of the item: ");
    scanf("%f", &items[count].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &items[count].quantity);
}

void display_items(item_t *items, int count) {
    for (int i = 0; i < count; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Price: $%.2f\n", items[i].price);
        printf("Quantity: %d\n\n", items[i].quantity);
    }
}

void calculate_total_cost(item_t *items, int count) {
    float total_cost = 0;
    for (int i = 0; i < count; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("Total cost: $%.2f\n", total_cost);
}

int main() {
    item_t items[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("Enter 1 to add an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_item(items, count);
            count++;
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("List of items:\n");
    display_items(items, count);

    calculate_total_cost(items, count);

    return 0;
}
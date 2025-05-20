//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    double price;
    int quantity;
};

void add_item(struct item *items, int num_items) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%lf", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items(struct item *items, int num_items) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2lf\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(struct item *items, int num_items) {
    double total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("Total cost: $%.2lf\n", total_cost);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Enter 1 to add an item, 2 to display items, 3 to calculate total cost, or any other key to exit:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                calculate_total_cost(items, num_items);
                break;
            default:
                printf("Exiting...\n");
                exit(0);
        }
    }

    return 0;
}
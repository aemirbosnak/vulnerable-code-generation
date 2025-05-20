//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[30];
    float price;
    int quantity;
};

void add_item(struct item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: $");
    scanf("%f", &items[*num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void display_items(struct item *items, int num_items) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(struct item *items, int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("\nTotal cost: $%.2f\n", total_cost);
}

int main() {
    srand(time(NULL));
    struct item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("How many items do you want to track? (Max %d): ", MAX_ITEMS);
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        add_item(items, &num_items);
    }

    display_items(items, num_items);
    calculate_total_cost(items, num_items);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void add_item(item* items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);

    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);

    printf("Enter the quantity of the item: ");
    scanf("%d", &items[num_items].quantity);
}

void display_items(item* items, int num_items) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(item* items, int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("The total cost of all items is: $%.2f\n", total_cost);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Enter 1 to add an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_item(items, num_items);
            num_items++;
        } else {
            break;
        }
    }

    display_items(items, num_items);
    calculate_total_cost(items, num_items);

    return 0;
}
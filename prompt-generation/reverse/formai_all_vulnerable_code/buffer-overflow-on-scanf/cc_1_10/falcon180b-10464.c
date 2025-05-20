//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void add_item(Item *items, int num_items) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items(Item *items, int num_items) {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(Item *items, int num_items) {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("Total Expense: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Enter 1 to add an item or 0 to display items and calculate total expense: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_item(items, num_items);
        } else if (choice == 0) {
            display_items(items, num_items);
            calculate_total(items, num_items);
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
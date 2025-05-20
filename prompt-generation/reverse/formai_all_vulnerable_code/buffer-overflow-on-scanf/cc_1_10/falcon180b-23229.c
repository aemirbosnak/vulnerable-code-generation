//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double price;
    int quantity;
} item_t;

void add_item(item_t *items, int num_items) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%lf", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items(item_t *items, int num_items) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2lf\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(item_t *items, int num_items) {
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal expense: $%.2lf", total);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (num_items < MAX_ITEMS) {
        printf("\nEnter 'a' to add an item or 'd' to display items: ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                add_item(items, num_items);
                break;
            case 'd':
                display_items(items, num_items);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    calculate_total(items, num_items);

    return 0;
}
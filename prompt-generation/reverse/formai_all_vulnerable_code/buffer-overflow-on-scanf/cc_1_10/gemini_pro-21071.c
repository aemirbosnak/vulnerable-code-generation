//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[32];
    float price;
    int quantity;
};

struct order {
    struct item items[100];
    int num_items;
    float total_price;
};

void print_menu() {
    printf("Menu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Cake - $3.00\n");
    printf("4. Pie - $3.50\n\n");
}

void add_item(struct order *order, int item_num, int quantity) {
    struct item *item = &order->items[order->num_items];
    switch (item_num) {
        case 1:
            strcpy(item->name, "Coffee");
            item->price = 2.50;
            break;
        case 2:
            strcpy(item->name, "Tea");
            item->price = 1.50;
            break;
        case 3:
            strcpy(item->name, "Cake");
            item->price = 3.00;
            break;
        case 4:
            strcpy(item->name, "Pie");
            item->price = 3.50;
            break;
    }
    item->quantity = quantity;
    order->num_items++;
    order->total_price += (item->price * quantity);
}

void print_order(struct order *order) {
    printf("\nOrder:\n");
    for (int i = 0; i < order->num_items; i++) {
        struct item *item = &order->items[i];
        printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, item->name, item->price, item->quantity, (item->price * item->quantity));
    }
    printf("Total: $%.2f\n\n", order->total_price);
}

int main() {
    struct order order;
    order.num_items = 0;
    order.total_price = 0.0;

    int choice;
    int quantity;
    do {
        print_menu();
        printf("Enter your choice (1-4) or 0 to quit: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            add_item(&order, choice, quantity);
        }
    } while (choice != 0);

    print_order(&order);

    return 0;
}
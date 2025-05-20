//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    float price;
};

struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

void add_item(struct order* order) {
    printf("Enter item name: ");
    scanf("%s", order->items[order->num_items].name);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->num_items].price);
    order->num_items++;
}

void remove_item(struct order* order) {
    printf("Enter item index to remove: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < order->num_items) {
        order->num_items--;
        for (int i = index; i < order->num_items; i++) {
            strcpy(order->items[i].name, order->items[i+1].name);
            order->items[i].price = order->items[i+1].price;
        }
    } else {
        printf("Invalid index\n");
    }
}

void display_order(struct order* order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
}

void calculate_total(struct order* order) {
    float total = 0.0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    struct order order;
    order.num_items = 0;

    int choice;
    do {
        printf("1. Add item\n2. Remove item\n3. Display order\n4. Calculate total\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&order);
                break;
            case 2:
                remove_item(&order);
                break;
            case 3:
                display_order(&order);
                break;
            case 4:
                calculate_total(&order);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}
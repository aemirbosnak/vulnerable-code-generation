//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[50];
    float price;
};

struct order {
    int num_items;
    struct item items[10];
};

void add_item(struct order* order) {
    int i;
    printf("Enter item name: ");
    scanf("%s", order->items[order->num_items].name);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->num_items].price);
    order->num_items++;
}

void display_order(struct order order) {
    int i;
    printf("Order:\n");
    for (i = 0; i < order.num_items; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
}

void calculate_total(struct order order) {
    int i;
    float total = 0.0;
    for (i = 0; i < order.num_items; i++) {
        total += order.items[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    struct order order;
    order.num_items = 0;
    while (1) {
        printf("1. Add item\n2. Display order\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&order);
                break;
            case 2:
                display_order(order);
                break;
            case 3:
                calculate_total(order);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
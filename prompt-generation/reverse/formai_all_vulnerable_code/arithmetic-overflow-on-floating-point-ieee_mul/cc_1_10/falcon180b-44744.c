//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int quantity;
    float total_price;
} Order;

void add_item(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void display_menu(Item items[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void place_order(Order order, Item items[], int size) {
    printf("\nEnter quantity for each item:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s: ", i+1, items[i].name);
        scanf("%d", &order.quantity);
        order.total_price += items[i].price * order.quantity;
    }
}

void print_receipt(Order order, Item items[], int size) {
    printf("\nReceipt:\n");
    printf("Item\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t$%.2f\n", items[i].name, order.quantity, items[i].price);
    }
    printf("Total Price: $%.2f\n", order.total_price);
}

int main() {
    Item items[MAX_ITEMS];
    int size = 0;

    add_item(items, &size);
    add_item(items, &size);
    add_item(items, &size);

    Order order;
    place_order(order, items, size);

    print_receipt(order, items, size);

    return 0;
}
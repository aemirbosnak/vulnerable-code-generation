//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Order;

void add_item(Order* order) {
    printf("Enter item name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    printf("Enter item price: ");
    float price;
    scanf("%f", &price);

    for (int i = 0; i < order->num_items; i++) {
        if (strcmp(name, order->items[i].name) == 0) {
            printf("Item already exists.\n");
            return;
        }
    }

    strcpy(order->items[order->num_items].name, name);
    order->items[order->num_items].price = price;
    order->num_items++;
    printf("Item added.\n");
}

void remove_item(Order* order) {
    printf("Enter item index to remove: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= order->num_items) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < order->num_items - 1; i++) {
        strcpy(order->items[i].name, order->items[i+1].name);
        order->items[i].price = order->items[i+1].price;
    }

    order->num_items--;
    printf("Item removed.\n");
}

void print_items(Order* order) {
    printf("Items:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
}

void calculate_total(Order* order) {
    float total = 0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }
    order->total_price = total;
}

int main() {
    Order order = {0};
    char choice;

    do {
        printf("Cafe Billing System\n");
        printf("1. Add item\n2. Remove item\n3. Print items\n4. Calculate total\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            add_item(&order);
            break;
        case '2':
            remove_item(&order);
            break;
        case '3':
            print_items(&order);
            break;
        case '4':
            calculate_total(&order);
            printf("Total price: $%.2f\n", order.total_price);
            break;
        case '5':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}
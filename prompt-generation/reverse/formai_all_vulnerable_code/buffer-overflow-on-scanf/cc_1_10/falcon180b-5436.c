//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

void addItem(Order *order) {
    int i;
    for (i = 0; i < order->numItems; i++) {
        if (strcmp(order->items[i].name, "") == 0) {
            printf("Enter name of item: ");
            scanf("%s", order->items[i].name);
            printf("Enter quantity: ");
            scanf("%d", &order->items[i].quantity);
            printf("Enter price: ");
            scanf("%lf", &order->items[i].price);
            return;
        }
    }
    printf("Error: Maximum number of items reached.\n");
}

void removeItem(Order *order) {
    int i, j;
    char name[MAX_NAME_LENGTH];
    printf("Enter name of item to remove: ");
    scanf("%s", name);
    for (i = 0; i < order->numItems; i++) {
        if (strcmp(order->items[i].name, name) == 0) {
            for (j = i; j < order->numItems - 1; j++) {
                strcpy(order->items[j].name, order->items[j + 1].name);
                order->items[j].quantity = order->items[j + 1].quantity;
                order->items[j].price = order->items[j + 1].price;
            }
            order->numItems--;
            return;
        }
    }
    printf("Error: Item not found.\n");
}

void printOrder(Order *order) {
    int i;
    double totalPrice = 0;
    printf("Order:\n");
    for (i = 0; i < order->numItems; i++) {
        printf("%s - %d - $%.2lf\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
        totalPrice += order->items[i].price * order->items[i].quantity;
    }
    printf("Total price: $%.2lf\n", totalPrice);
}

int main() {
    Order order;
    order.numItems = 0;
    while (1) {
        printf("1. Add item\n2. Remove item\n3. Print order\n4. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addItem(&order);
            break;
        case 2:
            removeItem(&order);
            break;
        case 3:
            printOrder(&order);
            break;
        case 4:
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}
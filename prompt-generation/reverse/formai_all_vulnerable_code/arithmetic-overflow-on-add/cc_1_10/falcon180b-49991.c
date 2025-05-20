//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} Item;

typedef struct {
    int size;
    Item items[10];
} Order;

void addItem(Order* order) {
    printf("Enter item name: ");
    scanf("%s", order->items[order->size].name);
    printf("Enter item quantity: ");
    scanf("%d", &order->items[order->size].quantity);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->size].price);
    order->size++;
}

void displayOrder(Order order) {
    printf("Order details:\n");
    for (int i = 0; i < order.size; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", order.items[i].name);
        printf("Quantity: %d\n", order.items[i].quantity);
        printf("Price: %.2f\n\n", order.items[i].price);
    }
}

float calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.size; i++) {
        total += order.items[i].quantity * order.items[i].price;
    }
    return total;
}

int main() {
    Order order;
    int choice;

    while (true) {
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. Place an order\n");
        printf("2. Display order details\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order size (max 10 items): ");
                scanf("%d", &order.size);
                for (int i = 0; i < order.size; i++) {
                    addItem(&order);
                }
                break;
            case 2:
                displayOrder(order);
                break;
            case 3:
                printf("Total amount: %.2f\n", calculateTotal(order));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
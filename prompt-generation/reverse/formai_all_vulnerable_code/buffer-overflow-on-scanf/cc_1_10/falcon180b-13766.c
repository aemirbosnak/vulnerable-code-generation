//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

void addItem(Order *order) {
    printf("Enter item name: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->numItems].price);
    order->numItems++;
}

void removeItem(Order *order) {
    printf("Enter item number to remove: ");
    int num;
    scanf("%d", &num);
    if (num >= 0 && num < order->numItems) {
        for (int i = num; i < order->numItems - 1; i++) {
            strcpy(order->items[i].name, order->items[i + 1].name);
            order->items[i].price = order->items[i + 1].price;
        }
        order->numItems--;
    } else {
        printf("Invalid item number.\n");
    }
}

void displayItems(Order order) {
    printf("Items:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
}

void calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Order order;
    order.numItems = 0;

    int choice;
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Calculate total\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                removeItem(&order);
                break;
            case 3:
                displayItems(order);
                break;
            case 4:
                calculateTotal(order);
                break;
            case 5:
                printf("Thank you for using our Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}
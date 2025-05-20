//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char size;
    int price;
    int quantity;
} Item;

typedef struct {
    Item items[100];
    int numItems;
    char name[50];
    char phone[20];
    char address[100];
} Order;

void printMenu() {
    printf("Welcome to our cafe!\n");
    printf("=========================\n");
    printf("1. Small Coffee (2 oz) - $2.00\n");
    printf("2. Medium Coffee (4 oz) - $2.50\n");
    printf("3. Large Coffee (8 oz) - $3.00\n");
    printf("4. Small Tea (2 oz) - $1.50\n");
    printf("5. Medium Tea (4 oz) - $2.00\n");
    printf("6. Large Tea (8 oz) - $2.50\n");
    printf("7. Pastries - $1.00 each\n");
    printf("=========================\n");
}

void takeOrder(Order *order) {
    printf("Please enter your name: ");
    scanf("%s", order->name);
    printf("Please enter your phone number: ");
    scanf("%s", order->phone);
    printf("Please enter your address: ");
    scanf("%s", order->address);
    printf("How many items would you like to order? ");
    scanf("%d", &order->numItems);
    for (int i = 0; i < order->numItems; i++) {
        printf("Item %d:\n", i + 1);
        printf(" - Name: ");
        scanf("%s", order->items[i].name);
        printf(" - Size (S/M/L): ");
        scanf(" %c", &order->items[i].size);
        printf(" - Quantity: ");
        scanf("%d", &order->items[i].quantity);
        switch (order->items[i].size) {
            case 'S':
                order->items[i].price = 2;
                break;
            case 'M':
                order->items[i].price = 2.50;
                break;
            case 'L':
                order->items[i].price = 3;
                break;
        }
    }
}

double calculateTotal(Order order) {
    double total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}

void printReceipt(Order order) {
    printf("=========================\n");
    printf("Order Summary\n");
    printf("=========================\n");
    printf("Customer Name: %s\n", order.name);
    printf("Customer Phone: %s\n", order.phone);
    printf("Customer Address: %s\n", order.address);
    printf("=========================\n");
    printf("Items Ordered:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf(" - %s (%c) x %d = $%.2f\n", order.items[i].name, order.items[i].size, order.items[i].quantity, order.items[i].price * order.items[i].quantity);
    }
    printf("=========================\n");
    printf("Total: $%.2f\n", calculateTotal(order));
    printf("=========================\n");
}

int main() {
    Order order;
    printMenu();
    takeOrder(&order);
    printReceipt(order);
    return 0;
}
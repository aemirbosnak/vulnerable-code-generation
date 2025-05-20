//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} MenuItem;

typedef struct {
    MenuItem items[100];
    int numItems;
} Menu;

typedef struct {
    int tableNumber;
    Menu menu;
    float total;
} Order;

void printMenu(Menu menu) {
    printf("Menu:\n");
    for (int i = 0; i < menu.numItems; i++) {
        printf("%d. %s: $%.2f\n", i + 1, menu.items[i].name, menu.items[i].price);
    }
}

void takeOrder(Order *order) {
    printf("Enter table number: ");
    scanf("%d", &order->tableNumber);

    printf("How many items would you like to order? ");
    scanf("%d", &order->menu.numItems);

    for (int i = 0; i < order->menu.numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", order->menu.items[i].name);

        printf("Enter quantity: ");
        scanf("%d", &order->menu.items[i].quantity);

        printf("Enter price: ");
        scanf("%f", &order->menu.items[i].price);
    }
}

void calculateTotal(Order *order) {
    order->total = 0;
    for (int i = 0; i < order->menu.numItems; i++) {
        order->total += order->menu.items[i].quantity * order->menu.items[i].price;
    }
}

void printBill(Order order) {
    printf("\nBill for table %d:\n", order.tableNumber);
    for (int i = 0; i < order.menu.numItems; i++) {
        printf("%s x %d: $%.2f\n", order.menu.items[i].name, order.menu.items[i].quantity, order.menu.items[i].quantity * order.menu.items[i].price);
    }
    printf("Total: $%.2f\n", order.total);
}

int main() {
    Menu menu;
    menu.numItems = 5;
    strcpy(menu.items[0].name, "Pizza");
    menu.items[0].price = 10.00;
    strcpy(menu.items[1].name, "Burger");
    menu.items[1].price = 8.00;
    strcpy(menu.items[2].name, "Fries");
    menu.items[2].price = 3.00;
    strcpy(menu.items[3].name, "Soda");
    menu.items[3].price = 2.00;
    strcpy(menu.items[4].name, "Water");
    menu.items[4].price = 1.00;

    Order order;
    takeOrder(&order);
    calculateTotal(&order);
    printBill(order);

    return 0;
}
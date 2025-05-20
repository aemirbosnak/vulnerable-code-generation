//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

struct MenuItem {
    char name[50];
    float price;
};

struct OrderItem {
    struct MenuItem item;
    int quantity;
};

struct Order {
    struct OrderItem items[MAX_ITEMS];
    int count;
};

struct MenuItem menu[3] = {
    {"Coffee", 2.00},
    {"Sandwich", 3.50},
    {"Cake", 2.50}
};

void displayMenu() {
    printf("Menu:\n");
    for(int i=0; i<3; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int getOrderChoice() {
    int choice;
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

int getOrderQuantity() {
    int quantity;
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    return quantity;
}

void addToOrder(struct Order* order, int choice, int quantity) {
    struct OrderItem item;
    item.item = menu[choice-1];
    item.quantity = quantity;
    order->items[order->count] = item;
    order->count++;
    printf("%d x %s added to order.\n", quantity, item.item.name);
}

void displayOrder(struct Order* order) {
    printf("Order:\n");
    for(int i=0; i<order->count; i++) {
        struct OrderItem item = order->items[i];
        printf("%d x %s - $%.2f each\n", item.quantity, item.item.name, item.item.price);
    }
}

float calculateTotal(struct Order* order) {
    float total = 0.0;
    for(int i=0; i<order->count; i++) {
        struct OrderItem item = order->items[i];
        total += (item.item.price * item.quantity);
    }
    return total;
}

int main() {
    struct Order order;
    order.count = 0;
    int choice, quantity;
    do {
        displayMenu();
        choice = getOrderChoice();
        quantity = getOrderQuantity();
        addToOrder(&order, choice, quantity);
        displayOrder(&order);
        printf("Total: $%.2f\n", calculateTotal(&order));
        printf("Enter 1 to add another item or 0 to checkout: ");
        scanf("%d", &choice);
    } while(choice != 0);
    return 0;
}
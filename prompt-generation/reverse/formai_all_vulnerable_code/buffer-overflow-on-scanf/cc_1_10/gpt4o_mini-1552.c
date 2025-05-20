//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Order;

void displayMenu(MenuItem menu[], int size) {
    printf("\n--- Café Menu ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("0. Finish Order\n");
}

float calculateTotal(Order *order) {
    float total = 0.0;
    for (int i = 0; i < order->count; i++) {
        total += order->items[i].price;
    }
    return total;
}

void addItemToOrder(Order *order, MenuItem menu[], int itemIndex) {
    if (order->count < MAX_ITEMS) {
        order->items[order->count] = menu[itemIndex];
        order->count++;
        printf("Added: %s\n", menu[itemIndex].name);
    } else {
        printf("Order is full! Cannot add more items.\n");
    }
}

void printBill(Order *order) {
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < order->count; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", calculateTotal(order));
}

void initializeMenu(MenuItem menu[]) {
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 3.00;
    
    strcpy(menu[1].name, "Tea");
    menu[1].price = 2.50;
    
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 5.50;
    
    strcpy(menu[3].name, "Cake");
    menu[3].price = 4.00;
    
    strcpy(menu[4].name, "Juice");
    menu[4].price = 3.50;
    
    // More items can be added here...
}

int main() {
    MenuItem menu[5];
    Order order;
    order.count = 0;
    int choice;

    initializeMenu(menu);

    do {
        displayMenu(menu, 5);
        printf("Select an item (1-%d): ", 5);
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= 5) {
            addItemToOrder(&order, menu, choice - 1);
        } else if (choice != 0) {
            printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 0);

    printBill(&order);
    
    return 0;
}
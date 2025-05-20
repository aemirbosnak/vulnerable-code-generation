//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
    float total;
} Order;

void printMenu() {
    printf("\n\tMenu:");
    printf("\n\t1. Add item to order");
    printf("\n\t2. Print order");
    printf("\n\t3. Confirm order");
    printf("\n\t4. Exit");
    printf("\n\tEnter choice: ");
}

void addItem(Order* order) {
    if(order->itemCount < MAX_ITEMS) {
        Item item;
        printf("\nEnter name of item: ");
        scanf("%s", item.name);
        printf("Enter quantity: ");
        scanf("%d", &item.quantity);
        printf("Enter price: ");
        scanf("%f", &item.price);
        order->items[order->itemCount] = item;
        order->itemCount++;
        printf("\nItem added to order.");
    } else {
        printf("\nOrder is full. Cannot add more items.");
    }
}

void printOrder(Order order) {
    printf("\n\n\tOrder:");
    printf("\n\t%s\t%s\t%s\n", "Name", "Quantity", "Price");
    for(int i=0; i<order.itemCount; i++) {
        printf("\t%s:\t%d\t%.2f\n", order.items[i].name, order.items[i].quantity, order.items[i].price);
    }
    printf("\tTotal: %.2f", order.total);
}

void confirmOrder(Order* order) {
    printf("\n\n\tOrder confirmed!");
    for(int i=0; i<order->itemCount; i++) {
        order->total += (order->items[i].quantity * order->items[i].price);
    }
    order->itemCount = 0;
}

int main() {
    Order order = { .itemCount=0, .total=0 };
    int choice = 0; 
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                printOrder(order);
                break;
            case 3:
                confirmOrder(&order);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice. Try again.");
        }
    } while(choice != 4);
    return 0;
}
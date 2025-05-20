//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Order;

void addItem(Item* items, int* numItems) {
    printf("Enter item id: ");
    scanf("%d", &items[*numItems].id);
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item description: ");
    scanf("%s", items[*numItems].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void viewItems(Item* items, int numItems) {
    printf("ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", items[i].id, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void placeOrder(Order* order, Item* items, int numItems) {
    printf("Enter customer name: ");
    scanf("%s", order->name);
    printf("Enter customer description: ");
    scanf("%s", order->description);
    printf("Enter order quantity: ");
    scanf("%d", &order->quantity);
    printf("Enter order price: ");
    scanf("%f", &order->price);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, order->name) == 0) {
            order->id = items[i].id;
            break;
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    addItem(items, &numItems);
    viewItems(items, numItems);

    Order order;
    placeOrder(&order, items, numItems);

    printf("Order placed for %d items of %s at a cost of $%.2f\n", order.quantity, items[order.id].name, order.price);

    return 0;
}
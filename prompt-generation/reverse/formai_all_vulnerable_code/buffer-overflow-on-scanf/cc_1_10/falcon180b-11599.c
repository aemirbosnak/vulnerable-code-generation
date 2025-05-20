//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    char description[MAX_SIZE];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Order;

void createItem(Item* item) {
    printf("Enter item ID: ");
    scanf("%d", &item->id);
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item description: ");
    scanf("%s", item->description);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item price: ");
    scanf("%f", &item->price);
}

void displayItem(Item item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: $%.2f\n", item.price);
}

void createOrder(Order* order) {
    printf("Enter order name: ");
    scanf("%s", order->name);
    printf("Enter order quantity: ");
    scanf("%d", &order->quantity);
    printf("Enter order price: ");
    scanf("%f", &order->price);
}

void displayOrder(Order order) {
    printf("Name: %s\n", order.name);
    printf("Quantity: %d\n", order.quantity);
    printf("Price: $%.2f\n", order.price);
}

int main() {
    Item item;
    Order order;

    int choice;
    while(1) {
        printf("\nWarehouse Management System\n");
        printf("1. Create Item\n2. Display Item\n3. Create Order\n4. Display Order\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createItem(&item);
                break;
            case 2:
                displayItem(item);
                break;
            case 3:
                createOrder(&order);
                break;
            case 4:
                displayOrder(order);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
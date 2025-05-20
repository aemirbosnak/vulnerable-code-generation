//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_ORDERS 100

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} CafeMenu;

typedef struct {
    int orderNumber;
    MenuItem orderedItems[MAX_ITEMS];
    int quantity[MAX_ITEMS];
    int itemsCount;
} Order;

void initializeMenu(CafeMenu *menu) {
    menu->itemCount = 0;

    // Sample menu items
    MenuItem item1 = {"Coffee", 2.5};
    MenuItem item2 = {"Tea", 1.5};
    MenuItem item3 = {"Sandwich", 5.0};
    MenuItem item4 = {"Cake", 3.0};
    MenuItem item5 = {"Pasta", 7.0};

    menu->items[menu->itemCount++] = item1;
    menu->items[menu->itemCount++] = item2;
    menu->items[menu->itemCount++] = item3;
    menu->items[menu->itemCount++] = item4;
    menu->items[menu->itemCount++] = item5;
}

void displayMenu(CafeMenu *menu) {
    printf("\n-------- Cafe Menu -------\n");
    for(int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu->items[i].name, menu->items[i].price);
    }
    printf("--------------------------\n");
}

void takeOrder(CafeMenu *menu, Order *order) {
    order->orderNumber = rand() % 1000; // Random order number
    order->itemsCount = 0;
    
    printf("\nEnter the number of items you want to order: ");
    scanf("%d", &(order->itemsCount));
    
    for (int i = 0; i < order->itemsCount; i++) {
        int itemIndex;
        printf("Enter the item number to order (1 to %d): ", menu->itemCount);
        scanf("%d", &itemIndex);

        if (itemIndex < 1 || itemIndex > menu->itemCount) {
            printf("Invalid item number. Please try again.\n");
            i--; // repeat this iteration
            continue;
        }

        order->orderedItems[i] = menu->items[itemIndex - 1];
        printf("Enter quantity for %s: ", order->orderedItems[i].name);
        scanf("%d", &(order->quantity[i]));
    }
}

void printBill(Order order) {
    printf("\n-------- Bill for Order #%d -------\n", order.orderNumber);
    float total = 0.0;

    for (int i = 0; i < order.itemsCount; i++) {
        float itemTotal = order.orderedItems[i].price * order.quantity[i];
        printf("%s x %d - $%.2f\n", order.orderedItems[i].name, order.quantity[i], itemTotal);
        total += itemTotal;
    }

    printf("-------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("-------------------------------\n");
}

int main() {
    CafeMenu menu;
    Order order;
    int choice;
    
    initializeMenu(&menu);
    
    do {
        printf("\nWelcome to the Cafe Billing System\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(&menu);
                break;
            case 2:
                takeOrder(&menu, &order);
                printBill(order);
                break;
            case 3:
                printf("Thank you for visiting! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
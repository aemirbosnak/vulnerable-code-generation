//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ORDERS 100

typedef struct {
    int itemId;
    char name[30];
    float price;
} MenuItem;

typedef struct {
    int orderId;
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Order;

MenuItem menu[] = {
    {1, "Espresso", 3.00},
    {2, "Latte", 4.50},
    {3, "Cappuccino", 4.00},
    {4, "Black Coffee", 2.50},
    {5, "Tea", 2.00},
};

int menuSize = sizeof(menu) / sizeof(menu[0]);
Order orders[MAX_ORDERS];
int orderCount = 0;

void displayMenu() {
    printf("\nMenu:\n");
    printf("ID\tItem\t\tPrice\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d\t%s\t\t$%.2f\n", menu[i].itemId, menu[i].name, menu[i].price);
    }
    printf("--------------------------------------\n");
}

void addItemToOrder(Order *order) {
    int itemId;
    printf("Enter item ID to add to order: ");
    scanf("%d", &itemId);

    for (int i = 0; i < menuSize; i++) {
        if (menu[i].itemId == itemId) {
            order->items[order->itemCount++] = menu[i];
            printf("Added %s to your order.\n", menu[i].name);
            return;
        }
    }
    printf("Item ID not found!\n");
}

float calculateTotal(Order *order) {
    float total = 0.0;
    for (int i = 0; i < order->itemCount; i++) {
        total += order->items[i].price;
    }
    return total;
}

void generateBill(Order *order) {
    printf("\n----- Bill -----\n");
    printf("Item\t\tPrice\n");
    printf("------------------------\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s\t\t$%.2f\n", order->items[i].name, order->items[i].price);
    }
    float total = calculateTotal(order);
    printf("------------------------\n");
    printf("Total: $%.2f\n", total);
    printf("------------------------\n");
}

int main() {
    int choice;

    printf("Welcome to the C Cafe Billing System!\n");
    
    while (1) {
        printf("\n1. Display Menu\n");
        printf("2. Create New Order\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                if (orderCount >= MAX_ORDERS) {
                    printf("Maximum number of orders reached!\n");
                    break;
                }
                
                printf("Creating order #%d...\n", orderCount + 1);
                Order newOrder;
                newOrder.orderId = orderCount + 1;
                newOrder.itemCount = 0;

                while (1) {
                    addItemToOrder(&newOrder);
                    char moreItems;
                    printf("Add another item? (y/n): ");
                    scanf(" %c", &moreItems);
                    if (moreItems != 'y') {
                        break;
                    }
                }
                
                generateBill(&newOrder);
                orders[orderCount++] = newOrder;
                break;
            case 3:
                printf("Thank you for using the C Cafe Billing System!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
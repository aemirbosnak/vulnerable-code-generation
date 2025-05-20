//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Order;

void addItem(Order *order) {
    if (order->itemCount >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", order->items[order->itemCount].name);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->itemCount].price);
    printf("Enter item quantity: ");
    scanf("%d", &order->items[order->itemCount].quantity);
    order->itemCount++;
    printf("Item added successfully!\n");
}

void displayOrder(const Order *order) {
    printf("\nYour Order:\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s (%.2f) x %d = %.2f\n", 
            order->items[i].name, 
            order->items[i].price, 
            order->items[i].quantity, 
            order->items[i].price * order->items[i].quantity);
    }
}

float calculateTotal(const Order *order) {
    float total = 0;
    for (int i = 0; i < order->itemCount; i++) {
        total += order->items[i].price * order->items[i].quantity;
    }
    return total;
}

float applyDiscount(float total, float discount) {
    return total - (total * (discount / 100));
}

void printBill(const Order *order) {
    printf("\n--- BILL ---\n");
    displayOrder(order);
    float total = calculateTotal(order);
    printf("Total: %.2f\n", total);
    
    float discount;
    printf("Enter discount percentage: ");
    scanf("%f", &discount);
    
    total = applyDiscount(total, discount);
    printf("Total after discount: %.2f\n", total);
    
    printf("Thank you for visiting!\n");
}

void clearOrder(Order *order) {
    order->itemCount = 0;
    printf("Order has been cleared!\n");
}

int main() {
    Order order;
    order.itemCount = 0;
    int choice;

    while (1) {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Order\n");
        printf("3. Print Bill\n");
        printf("4. Clear Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                displayOrder(&order);
                break;
            case 3:
                printBill(&order);
                break;
            case 4:
                clearOrder(&order);
                break;
            case 5:
                printf("Exiting the Cafe Billing System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
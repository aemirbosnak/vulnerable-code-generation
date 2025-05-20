//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[50];
    float price;
} MenuItem;

typedef struct {
    char customerName[50];
    int itemCount;
    MenuItem orderedItems[10];
} Order;

void displayMenu(MenuItem menu[], int size) {
    printf("O! Fair Verona Cafe Menu:\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].itemName, menu[i].price);
    }
    printf("------------------------------------------\n");
}

void placeOrder(Order* order, MenuItem menu[], int menuSize) {
    printf("Enter your name, O Sweet Patron: ");
    scanf("%s", order->customerName);
    order->itemCount = 0;

    int choice;
    do {
        printf("Select an item (1-%d) to add to your order or 0 to finish: ", menuSize);
        scanf("%d", &choice);
        if (choice > 0 && choice <= menuSize) {
            order->orderedItems[order->itemCount] = menu[choice - 1];
            order->itemCount++;
            printf("%s placed in thine order! \n", menu[choice - 1].itemName);
        }
    } while (choice != 0 && order->itemCount < 10);
    
    printf("Thy order is taken, sweet %s!\n", order->customerName);
}

void printBill(Order order) {
    float total = 0.0;

    printf("\n=== Your Bill, O Lovable Customer ===\n");
    printf("Name: %s\n", order.customerName);
    printf("------------------------------------------\n");
    for (int i = 0; i < order.itemCount; i++) {
        printf("%s - $%.2f\n", order.orderedItems[i].itemName, order.orderedItems[i].price);
        total += order.orderedItems[i].price;
    }
    printf("------------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("Thank thee for thy patronage!\n");
}

int main() {
    MenuItem menu[] = {
        {"Capulet's Coffee", 3.50},
        {"Montague's Mocha", 4.00},
        {"Verona's Vanilla Latte", 4.50},
        {"Romeo's Raspberry Scone", 2.75},
        {"Juliet's Joyful Jam", 1.25},
        {"Banishment Biscuit", 1.50}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    
    Order order;
    displayMenu(menu, menuSize);
    placeOrder(&order, menu, menuSize);
    printBill(order);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 20

struct MenuItem {
    char name[MAX_NAME_LEN];
    float price;
};

struct Order {
    struct MenuItem items[MAX_ITEMS];
    int itemCount;
};

void displayMenu(struct MenuItem menu[], int itemCount) {
    printf("Welcome to the Wacky Cafe!\n");
    printf("Here's our menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("Please enter the number of the item (0 to finish):\n");
}

void takeOrder(struct Order *order, struct MenuItem menu[], int itemCount) {
    int choice;
    while (1) {
        displayMenu(menu, itemCount);
        scanf("%d", &choice);
        if (choice == 0) {
            break; // Finish the order
        }
        if (choice < 1 || choice > itemCount) {
            printf("Invalid choice! Please select a valid item or 0 to finish.\n");
            continue;
        }
        order->items[order->itemCount] = menu[choice - 1];
        order->itemCount++;
        printf("You added %s to your order!\n", menu[choice - 1].name);
        if (order->itemCount >= MAX_ITEMS) {
            printf("You have reached the maximum number of items! Time to pay!\n");
            break;
        }
    }
}

void printBill(struct Order *order) {
    printf("\nYour Order Summary:\n");
    float total = 0.0;
    for (int i = 0; i < order->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, order->items[i].name, order->items[i].price);
        total += order->items[i].price;
    }
    printf("Total amount due: $%.2f\n", total);
    printf("Thank you for eating with us! Please come again or we will send a rabid raccoon to collect!\n");
}

int main() {
    struct MenuItem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Donut", 1.00},
        {"Sandwich", 5.00},
        {"Pasta", 6.50},
        {"Burger", 8.00},
        {"Salad", 4.25},
        {"Juice", 3.00},
        {"Chocolate Cake", 3.50},
        {"Ice Cream", 2.00}
    };
    int itemCount = sizeof(menu) / sizeof(menu[0]);

    struct Order order;
    order.itemCount = 0;

    takeOrder(&order, menu, itemCount);
    printBill(&order);
    
    return 0;
}
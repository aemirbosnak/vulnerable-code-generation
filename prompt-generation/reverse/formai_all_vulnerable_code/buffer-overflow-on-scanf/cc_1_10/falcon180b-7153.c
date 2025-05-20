//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for menu items
struct menuItem {
    char name[50];
    int price;
};

// Define structure for orders
struct order {
    int orderNumber;
    int quantity;
    struct menuItem *item;
};

// Function to display menu
void displayMenu() {
    printf("Welcome to the Cafe!\n");
    printf("--------------------\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Pastry\n");
    printf("5. Exit\n");
}

// Function to take order
void takeOrder() {
    int choice;
    struct order order;

    printf("Enter your order number: ");
    scanf("%d", &order.orderNumber);

    printf("Enter the quantity: ");
    scanf("%d", &order.quantity);

    printf("Enter the item number: ");
    scanf("%d", &choice);

    if(choice == 1) {
        strcpy(order.item->name, "Coffee");
        order.item->price = 50;
    } else if(choice == 2) {
        strcpy(order.item->name, "Tea");
        order.item->price = 30;
    } else if(choice == 3) {
        strcpy(order.item->name, "Sandwich");
        order.item->price = 100;
    } else if(choice == 4) {
        strcpy(order.item->name, "Pastry");
        order.item->price = 80;
    } else {
        printf("Invalid choice!\n");
        return;
    }

    printf("Your order is: %s - %d quantity - %d price\n", order.item->name, order.quantity, order.item->price);
}

// Function to print bill
void printBill(struct order *orders, int numOrders) {
    int i, totalPrice = 0;

    printf("--------------------\n");
    printf("Your bill:\n");

    for(i = 0; i < numOrders; i++) {
        printf("%d. %s - %d quantity - %d price\n", orders[i].orderNumber, orders[i].item->name, orders[i].quantity, orders[i].item->price);
        totalPrice += orders[i].quantity * orders[i].item->price;
    }

    printf("Total price: %d\n", totalPrice);
}

int main() {
    int choice, numOrders = 0;
    struct order orders[10];

    while(1) {
        displayMenu();

        scanf("%d", &choice);

        if(choice == 1) {
            takeOrder();
            numOrders++;
        } else if(choice == 5) {
            if(numOrders > 0) {
                printBill(orders, numOrders);
            } else {
                printf("You have not placed any orders.\n");
            }
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
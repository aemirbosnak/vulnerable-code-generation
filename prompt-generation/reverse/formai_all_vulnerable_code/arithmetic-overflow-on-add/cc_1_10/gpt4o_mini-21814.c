//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int order[MAX_ITEMS]; // quantity ordered of each item
    int total_items; // total different menu items
} Order;

void initializeMenu(MenuItem menu[]) {
    strcpy(menu[0].name, "Espresso");
    menu[0].price = 3.00;
    strcpy(menu[1].name, "Cappuccino");
    menu[1].price = 4.00;
    strcpy(menu[2].name, "Latte");
    menu[2].price = 4.50;
    strcpy(menu[3].name, "Mocha");
    menu[3].price = 5.00;
    strcpy(menu[4].name, "Tea");
    menu[4].price = 2.50;
    strcpy(menu[5].name, "Croissant");
    menu[5].price = 2.00;
    strcpy(menu[6].name, "Muffin");
    menu[6].price = 2.50;
    strcpy(menu[7].name, "Sandwich");
    menu[7].price = 5.50;
    strcpy(menu[8].name, "Smoothie");
    menu[8].price = 4.00;
    strcpy(menu[9].name, "Brownie");
    menu[9].price = 3.50;
}

void displayMenu(MenuItem menu[], int size) {
    printf("\nWelcome to our Cafe!\n");
    printf("Here's our menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder(MenuItem menu[], Order *order) {
    int choice, quantity;
    printf("\nEnter your order (1-%d to select item, 0 to finish):\n", order->total_items);
    while (1) {
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        if (choice < 1 || choice > order->total_items) {
            printf("Invalid choice, please try again.\n");
            continue;
        }
        
        printf("How many %s would you like? ", menu[choice - 1].name);
        scanf("%d", &quantity);
        
        // Updating the order
        order->order[choice - 1] += quantity;
    }
}

float calculateTotal(MenuItem menu[], Order *order) {
    float total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        total += menu[i].price * order->order[i];
    }
    return total;
}

void printReceipt(MenuItem menu[], Order *order) {
    printf("\n********** Your Receipt **********\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (order->order[i] > 0) {
            printf("%s (x%d) - $%.2f\n", menu[i].name, order->order[i], menu[i].price * order->order[i]);
        }
    }
    float total = calculateTotal(menu, order);
    printf("Total Amount Due: $%.2f\n", total);
    printf("Thank you for visiting our cafe! Come back soon!\n");
    printf("**********************************\n");
}

int main() {
    MenuItem menu[MAX_ITEMS];
    Order order = { .total_items = MAX_ITEMS }; // Initialize total items to max
    memset(order.order, 0, sizeof(order.order)); // Initialize order quantities to 0

    initializeMenu(menu);
    displayMenu(menu, MAX_ITEMS);
    takeOrder(menu, &order);
    printReceipt(menu, &order);

    return 0;
}
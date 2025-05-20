//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ORDERS 50

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int itemId;
    int quantity;
} Order;

MenuItem menu[MAX_ITEMS];
Order orders[MAX_ORDERS];
int totalOrders = 0;

void initializeMenu() {
    menu[0] = (MenuItem){1, "Coffee", 2.50};
    menu[1] = (MenuItem){2, "Tea", 1.50};
    menu[2] = (MenuItem){3, "Sandwich", 3.00};
    menu[3] = (MenuItem){4, "Pastry", 2.00};
    menu[4] = (MenuItem){5, "Juice", 2.75};
}

void displayMenu() {
    printf("======== Cafe Menu ========\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("============================\n");
}

void addOrder() {
    int itemId, quantity;
    printf("Enter item ID to order: ");
    scanf("%d", &itemId);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (itemId < 1 || itemId > 5) {
        printf("Invalid item ID.\n");
        return;
    }

    orders[totalOrders++] = (Order){itemId, quantity};
    printf("Added %d x %s to your order.\n", quantity, menu[itemId - 1].name);
}

float calculateTotal() {
    float total = 0;
    for (int i = 0; i < totalOrders; i++) {
        total += menu[orders[i].itemId - 1].price * orders[i].quantity;
    }
    return total;
}

void printBill() {
    printf("======== Your Bill ========\n");
    for (int i = 0; i < totalOrders; i++) {
        int itemId = orders[i].itemId - 1;
        printf("%d x %s - $%.2f\n", orders[i].quantity, menu[itemId].name, menu[itemId].price * orders[i].quantity);
    }
    printf("Total Amount: $%.2f\n", calculateTotal());
    printf("============================\n");
}

void clearOrders() {
    totalOrders = 0;
}

int main() {
    int choice;

    initializeMenu();

    do {
        printf("======== Cafe Billing System ========\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Print Bill\n");
        printf("4. Clear Orders\n");
        printf("5. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                addOrder();
                break;
            case 3:
                printBill();
                break;
            case 4:
                clearOrders();
                printf("Orders cleared.\n");
                break;
            case 5:
                printf("Thank you for visiting!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
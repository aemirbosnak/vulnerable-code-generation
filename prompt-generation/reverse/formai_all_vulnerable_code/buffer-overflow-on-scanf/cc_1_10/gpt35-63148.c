//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing items in the menu
typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

// Structure for storing information about each order
typedef struct {
    int id;
    char itemName[50];
    float price;
    int quantity;
    float total;
} Order;

int main() {
    int menuSize = 5;
    MenuItem menu[menuSize];
    menu[0] = (MenuItem) {1, "Coffee", 1.50};
    menu[1] = (MenuItem) {2, "Tea", 1.00};
    menu[2] = (MenuItem) {3, "Sandwich", 3.50};
    menu[3] = (MenuItem) {4, "Cake", 2.50};
    menu[4] = (MenuItem) {5, "Juice", 2.00};

    int maxOrders = 10;
    int orderCount = 0;
    Order orders[maxOrders];

    printf("Welcome to Cafe Billing System!\n");

    while (1) {
        // Display the menu
        printf("\n--------MENU--------\n");
        printf("ID\tITEM\tPRICE\n");
        for (int i = 0; i < menuSize; i++) {
            printf("%d\t%s\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
        }

        int choice;
        printf("\nEnter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > menuSize) {
            printf("Invalid choice!\n");
            continue;
        }

        // Get the quantity of the selected item
        int quantity;
        printf("Enter the quantity for %s: ", menu[choice-1].name);
        scanf("%d", &quantity);

        // Calculate the total price and add the order to the list
        float total = quantity * menu[choice-1].price;
        orders[orderCount] = (Order) {orderCount+1, menu[choice-1].name, menu[choice-1].price, quantity, total};
        orderCount++;

        printf("Order added!\n");
    }

    // Display the final bill
    printf("--------BILL--------\n");
    printf("ID\tITEM\tPRICE\tQUANTITY\tTOTAL\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d\t%s\t%.2f\t%d\t\t%.2f\n", orders[i].id, orders[i].itemName, orders[i].price, orders[i].quantity, orders[i].total);
    }

    float grandTotal = 0;
    for (int i = 0; i < orderCount; i++) {
        grandTotal += orders[i].total;
    }
    printf("GRAND TOTAL: %.2f\n", grandTotal);

    return 0;
}
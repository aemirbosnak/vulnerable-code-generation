//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menuItem {
    char itemName[20];
    int itemPrice;
};
typedef struct menuItem MenuItem;

struct order {
    MenuItem menuItems[50];
    int numOfItems;
    int total;
};
typedef struct order Order;

void printMenu(MenuItem menu[], int size) {
    printf("<-----------------Menu----------------->\n");
    for(int i = 0; i < size; i++) {
        printf("%s: $%d\n", menu[i].itemName, menu[i].itemPrice);
    }
    printf("Enter 0 to stop ordering\n");
}

int main() {
    // Initialization
    int numOfItems = 0;
    int total = 0;
    MenuItem menuItems[] = {{"Coffee", 3}, {"Sandwich", 5}, {"Cookie", 2}, {"Muffin", 3}};
    Order currentOrder;
    currentOrder.numOfItems = 0;
    currentOrder.total = 0;
    memset(currentOrder.menuItems, 0, sizeof(currentOrder.menuItems));

    // Main loop
    int option;
    do {
        printMenu(menuItems, sizeof(menuItems)/sizeof(menuItems[0]));
        printf("Enter item: ");
        scanf("%d", &option);
        if(option != 0) {
            if(currentOrder.numOfItems == 50) {
                printf("Maximum items reached. Order processing.\n");
                option = 0;
            } else {
                currentOrder.menuItems[numOfItems] = menuItems[option - 1];
                currentOrder.numOfItems++;
                currentOrder.total += menuItems[option - 1].itemPrice;
                printf("\nOrdered %s - $%d\n\n", menuItems[option - 1].itemName, menuItems[option - 1].itemPrice);
            }
        } else {
            printf("\nOrder processing...\n");
        }
    } while(option != 0);

    // Output order details
    printf("\nYou ordered:\n");
    for(int i = 0; i < currentOrder.numOfItems; i++) {
        printf("%s - $%d\n", currentOrder.menuItems[i].itemName, currentOrder.menuItems[i].itemPrice);
    }
    printf("\nTotal: $%d\n", currentOrder.total);

    return 0;
}
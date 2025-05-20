//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to add items to the menu
void addToMenu(int menu[][4], int menuSize, int menuCount, char itemName[], int itemPrice) {
    menu[menuCount][0] = menuSize;
    menu[menuCount][1] = itemName;
    menu[menuCount][2] = itemPrice;
    menu[menuCount][3] = 0;
    menuSize++;
}

// Function to take customer orders
void takeOrders(int menu[][4], int menuSize, int menuCount) {
    int numItems, itemPrice;
    char itemName[20];
    int i = 0;
    
    printf("Enter the number of items you want to order:\n");
    scanf("%d", &numItems);
    
    while (i < numItems) {
        printf("Enter the name of item %d:\n", i + 1);
        scanf("%s", itemName);
        printf("Enter the price of item %d:\n", i + 1);
        scanf("%d", &itemPrice);
        addToMenu(menu, menuSize, menuCount, itemName, itemPrice);
        i++;
    }
}

// Function to calculate total cost
void calculateTotalCost(int menu[][4], int menuSize, int menuCount) {
    int totalCost = 0;
    int i = 0;
    
    while (i < menuCount) {
        totalCost += menu[i][2];
        i++;
    }
    
    printf("Total cost: %d\n", totalCost);
}

// Function to display customer orders
void displayOrders(int menu[][4], int menuSize, int menuCount) {
    int i = 0;
    
    printf("Customer Orders:\n");
    while (i < menuCount) {
        printf("%s - $%.2f\n", menu[i][1], menu[i][2]);
        i++;
    }
}

int main() {
    int menu[][4] = { { 0, "Sandwich", 5, 0 }, { 0, "Coffee", 2, 0 }, { 0, "Donut", 1, 0 } };
    int menuSize = 3;
    int menuCount = 3;
    
    addToMenu(menu, menuSize, menuCount, "Chicken Sandwich", 6);
    addToMenu(menu, menuSize, menuCount, "BLT", 5);
    addToMenu(menu, menuSize, menuCount, "Latte", 4);
    addToMenu(menu, menuSize, menuCount, "Cappuccino", 3);
    
    takeOrders(menu, menuSize, menuCount);
    calculateTotalCost(menu, menuSize, menuCount);
    displayOrders(menu, menuSize, menuCount);
    
    return 0;
}
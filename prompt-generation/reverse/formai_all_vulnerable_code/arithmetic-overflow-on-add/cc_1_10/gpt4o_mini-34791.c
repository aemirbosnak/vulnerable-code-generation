//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("-----------------\n");
}

int getOrder(MenuItem menu[], int itemCount) {
    int selection = 0;
    printf("Enter the item number to order (0 to finish): ");
    scanf("%d", &selection);
    return selection;
}

void printBill(MenuItem menu[], int orderedItems[], int quantities[], int itemCount) {
    float totalPrice = 0;
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            float itemTotal = menu[i].price * quantities[i];
            printf("%s x%d - $%.2f\n", menu[i].name, quantities[i], itemTotal);
            totalPrice += itemTotal;
        }
    }
    printf("-----------------\n");
    printf("Total Amount: $%.2f\n", totalPrice);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 1.75},
        {3, "Sandwich", 5.00},
        {4, "Burger", 6.50},
        {5, "Pasta", 8.00},
        {6, "Salad", 4.50},
        {7, "Juice", 3.00},
        {8, "Water", 1.00},
        {9, "Cake", 2.75},
        {10, "Ice Cream", 3.50}
    };

    int orderedItems[MAX_ITEMS] = {0}; // Stores the quantities of each item ordered
    int quantities[MAX_ITEMS] = {0};

    while (1) {
        displayMenu(menu, MAX_ITEMS);
        int selection = getOrder(menu, MAX_ITEMS);

        if (selection == 0) {
            // User finished ordering
            break;
        } else if (selection < 1 || selection > MAX_ITEMS) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        int itemIndex = selection - 1;
        printf("How many %s would you like to order? ", menu[itemIndex].name);
        scanf("%d", &quantities[itemIndex]);
        orderedItems[itemIndex] += quantities[itemIndex];
    }

    printBill(menu, orderedItems, quantities, MAX_ITEMS);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to print the menu
void printMenu(MenuItem items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

// Function to scan the menu for a specific item
int findMenuItem(MenuItem items[], int numItems, char* target) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to calculate the total cost of an order
float calculateTotal(MenuItem items[], int numItems, int numOrders, int orders[]) {
    float total = 0.0;
    for (int i = 0; i < numOrders; i++) {
        int index = findMenuItem(items, numItems, items[orders[i]].name);
        if (index!= -1) {
            total += items[index].price;
        } else {
            printf("Invalid item: %s\n", items[orders[i]].name);
        }
    }
    return total;
}

int main() {
    // Define the menu items
    MenuItem menu[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}, {"Sandwich", 4.50}};
    int numItems = sizeof(menu) / sizeof(MenuItem);

    // Define the customer's order
    int numOrders;
    int orders[10];
    printf("Enter the number of items you would like to order (up to 10): ");
    scanf("%d", &numOrders);
    for (int i = 0; i < numOrders; i++) {
        printf("Enter the name of the item you would like to order: ");
        scanf("%s", orders[i]);
    }

    // Calculate the total cost of the order
    float total = calculateTotal(menu, numItems, numOrders, orders);

    // Print the order and total cost
    printf("\nYour order:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%s - $%.2f\n", orders[i], menu[findMenuItem(menu, numItems, orders[i])].price);
    }
    printf("\nTotal cost: $%.2f\n", total);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define structure for menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to display menu
void displayMenu(MenuItem menu[], int numItems) {
    printf("=== Menu ===\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take order
void takeOrder(MenuItem menu[], int numItems, int order[], int *numOrders) {
    int choice;
    printf("\nEnter choice (1-%d): ", numItems);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= numItems) {
        order[*numOrders] = choice;
        (*numOrders)++;
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to calculate total cost of order
float calculateTotal(MenuItem menu[], int numItems, int order[], int numOrders) {
    float total = 0.0;
    for (int i = 0; i < numOrders; i++) {
        total += menu[order[i]-1].price;
    }
    return total;
}

// Function to print receipt
void printReceipt(MenuItem menu[], int numItems, int order[], int numOrders, float total) {
    printf("\n=== Receipt ===\n");
    printf("Order:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%d. %s - $%.2f\n", order[i], menu[order[i]-1].name, menu[order[i]-1].price);
    }
    printf("\nTotal cost: $%.2f\n", total);
}

int main() {
    // Define menu items
    MenuItem menu[MAX_ITEMS] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}, {"Sandwich", 4.50}};
    int numItems = 4;

    // Initialize order and number of items ordered
    int order[MAX_ITEMS];
    int numOrders = 0;

    // Display menu and take order
    displayMenu(menu, numItems);
    while (numOrders < MAX_ITEMS) {
        takeOrder(menu, numItems, order, &numOrders);
    }

    // Calculate total cost of order
    float total = calculateTotal(menu, numItems, order, numOrders);

    // Print receipt
    printReceipt(menu, numItems, order, numOrders, total);

    return 0;
}
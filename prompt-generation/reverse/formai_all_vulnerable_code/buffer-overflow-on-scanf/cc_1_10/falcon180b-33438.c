//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total cost of items
int calculateTotal(int items[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += items[i];
    }
    return total;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Cafe!\n");
    printf("\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Cake\n");
    printf("\n");
}

// Function to take order from customer
void takeOrder(int items[], int n) {
    printf("Enter the items you want to order (1 to %d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
}

// Function to print the bill
void printBill(int items[], int n, int total) {
    printf("\n");
    printf("Your order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, (i == 0? "Coffee" : (i == 1? "Tea" : (i == 2? "Sandwich" : "Cake"))));
    }
    printf("\n");
    printf("Total cost: $%d\n", total);
}

int main() {
    // Initialize the menu items and their prices
    int menuItems[] = {1, 2, 3, 4};
    int prices[] = {50, 30, 100, 60};

    // Initialize the number of items in the menu
    int n = sizeof(menuItems) / sizeof(menuItems[0]);

    // Display the menu
    displayMenu();

    // Take the order from the customer
    int orderItems[n];
    takeOrder(orderItems, n);

    // Calculate the total cost of items
    int total = calculateTotal(orderItems, n);

    // Print the bill
    printBill(orderItems, n, total);

    return 0;
}
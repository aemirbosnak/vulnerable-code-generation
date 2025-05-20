//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][30] = {"Cappuccino", "Latte", "Espresso", "Americano", "Mocha"};
float prices[] = {3.50, 4.00, 2.50, 3.00, 4.50};

// Function to display the menu
void displayMenu() {
    printf("\n\t***** Welcome to the Coffee Shop! *****\n\n");
    for (int i = 0; i < 5; i++) {
        printf("\t%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
    printf("\n\t0. Exit\n");
}

// Function to get the user's order
int getOrder() {
    int choice;
    printf("\nEnter your choice (0-5): ");
    scanf("%d", &choice);
    return choice;
}

// Function to calculate the total bill
float calculateBill(int order[], int quantity[]) {
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += prices[i] * quantity[i];
    }
    return total;
}

// Function to print the receipt
void printReceipt(int order[], int quantity[], float total) {
    printf("\n\t***** Your Receipt *****\n\n");
    for (int i = 0; i < 5; i++) {
        if (quantity[i] > 0) {
            printf("\t%d. %s - $%.2f x %d = $%.2f\n", i + 1, menu[i], prices[i], quantity[i], prices[i] * quantity[i]);
        }
    }
    printf("\n\tTotal: $%.2f\n\n", total);
}

// Main function
int main() {
    int order[5] = {0, 0, 0, 0, 0}; // Array to store the user's order
    int quantity[5] = {0, 0, 0, 0, 0}; // Array to store the quantity of each item ordered
    float total = 0.0; // Variable to store the total bill

    // Display the menu
    displayMenu();

    // Get the user's order
    int choice = getOrder();

    // While the user does not choose to exit
    while (choice != 0) {
        // Get the quantity of the item ordered
        printf("\nEnter the quantity of %s: ", menu[choice - 1]);
        scanf("%d", &quantity[choice - 1]);

        // Increment the order count for the item ordered
        order[choice - 1]++;

        // Display the menu again
        displayMenu();

        // Get the user's next order
        choice = getOrder();
    }

    // Calculate the total bill
    total = calculateBill(order, quantity);

    // Print the receipt
    printReceipt(order, quantity, total);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cheery helper functions
void greetCustomer() {
    printf("Welcome to our delightful cafe! How may we brighten your day?\n");
}

void displayMenu() {
    printf("\nOur tantalizing menu:\n");
    printf("  1. Sparkling Coffee (100)\n");
    printf("  2. Aromatic Tea (75)\n");
    printf("  3. Decadent Chocolate Cake (150)\n");
    printf("  4. Creamy Ice Cream (50)\n");
}

int takeOrder() {
    int choice;
    printf("Please enter the number of the item you'd like to order: ");
    scanf("%d", &choice);
    return choice;
}

void calculateBill(int order, int quantity, int* total) {
    int price = 0;
    switch (order) {
        case 1: price = 100; break;
        case 2: price = 75; break;
        case 3: price = 150; break;
        case 4: price = 50; break;
    }
    *total += price * quantity;
}

void displayBill(int total) {
    printf("\nYour bill, presented with a smile:\n");
    printf("Total: %d\n", total);
}

void wishFarewell() {
    printf("Thank you for choosing our cafe! Have a sunny day!\n");
}

int main() {
    // Let's welcome our cheerful customer!
    greetCustomer();

    // Time to showcase our tempting menu!
    displayMenu();

    // Let's take the customer's order and make them smile!
    int order = takeOrder();
    int quantity = 0;
    printf("How many would you like to order? ");
    scanf("%d", &quantity);

    // Calculating the bill, adding a dash of happiness!
    int total = 0;
    calculateBill(order, quantity, &total);

    // Presenting the bill with a smile!
    displayBill(total);

    // Sending off our customer with warmth and cheer!
    wishFarewell();

    return 0;
}
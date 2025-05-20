//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addItem(char *item);
void displayItems();
void checkout();

// Global variables to track the cafe's inventory and total sales
int itemCount = 0;
char items[100][20];
float prices[100];
float totalSales = 0.0;

int main() {
    char choice;

    // Display the cafe menu
    printf("Welcome to our cafe!\n");
    printf("Here is our menu:\n");
    printf("1. Coffee - $2.00\n");
    printf("2. Tea - $1.50\n");
    printf("3. Pastry - $3.00\n");
    printf("4. Sandwich - $5.00\n");

    // Get the user's choice
    printf("What would you like to order? (1, 2, 3, 4, or Q to quit): ");
    scanf("%c", &choice);

    // Process the user's choice
    while (choice != 'Q') {
        switch (choice) {
            case '1':
                addItem("Coffee");
                break;
            case '2':
                addItem("Tea");
                break;
            case '3':
                addItem("Pastry");
                break;
            case '4':
                addItem("Sandwich");
                break;
            default:
                printf("Invalid choice. Please choose 1, 2, 3, 4, or Q: ");
        }

        // Get the next user's choice
        printf("What else would you like to order? (1, 2, 3, 4, or Q to quit): ");
        scanf(" %c", &choice);
    }

    // Display the items ordered and the total sales
    printf("\nHere is your order:\n");
    displayItems();
    printf("Your total is $%.2f\n", totalSales);

    // Checkout the customer
    checkout();

    return 0;
}

// Add an item to the order
void addItem(char *item) {
    // Check if the item is already in the order
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i], item) == 0) {
            // If the item is already in the order, increment the quantity
            prices[i]++;
            return;
        }
    }

    // If the item is not in the order, add it to the order
    strcpy(items[itemCount], item);
    prices[itemCount] = 1.0;
    itemCount++;
}

// Display the items ordered and the total sales
void displayItems() {
    for (int i = 0; i < itemCount; i++) {
        printf("%s x %.0f - $%.2f\n", items[i], prices[i], prices[i] * 2);
        totalSales += prices[i] * 2;
    }
}

// Checkout the customer
void checkout() {
    float amount = totalSales;
    float payment;

    // Get the payment amount from the customer
    printf("Please enter your payment amount: $");
    scanf("%f", &payment);

    // Check if the customer has paid enough
    while (payment < amount) {
        printf("Error: The payment amount is too low. Please enter the correct payment amount: $");
        scanf("%f", &payment);
    }

    // Calculate the change
    float change = payment - amount;

    // Display the change
    printf("Your change is $%.2f\n", change);

    // Reset the global variables
    itemCount = 0;
    totalSales = 0.0;
}
//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char menu[][100] = {"Espresso", "Americano", "Cappuccino", "Latte", "Mocha", "Tea"};
float prices[] = {1.5, 2.0, 2.5, 3.0, 3.5, 1.0};

// Get the customer's order
void getOrder(char order[][100], int *numItems) {
    *numItems = 0;
    printf("Welcome to our cafe!\n");
    while (1) {
        printf("What would you like to order? (Enter 'q' to quit) ");
        scanf("%s", order[*numItems]);
        if (strcmp(order[*numItems], "q") == 0) {
            break;
        }
        *numItems += 1;
    }
}

// Calculate the total price of the order
float calculateTotal(char order[][100], int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < 6; j++) {
            if (strcmp(order[i], menu[j]) == 0) {
                total += prices[j];
                break;
            }
        }
    }
    return total;
}

// Print the receipt
void printReceipt(char order[][100], int numItems, float total) {
    printf("\nYour order:\n");
    for (int i = 0; i < numItems; i++) {
        printf(" - %s\n", order[i]);
    }
    printf("Total: $%.2f\n", total);
    printf("Thank you for your order!\n");
}

// Main function
int main() {
    // Get the customer's order
    char order[100][100];
    int numItems;
    getOrder(order, &numItems);

    // Calculate the total price of the order
    float total = calculateTotal(order, numItems);

    // Print the receipt
    printReceipt(order, numItems, total);

    return 0;
}
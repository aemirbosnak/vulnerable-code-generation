//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>

// Function to calculate the total bill amount
float calculateBill(int quantity, float price) {
    float total = quantity * price;
    return total;
}

int main() {
    printf("Welcome to the C Cafe!\n");

    // Menu items and prices
    float coffeePrice = 2.5;
    float teaPrice = 1.5;
    float sandwichPrice = 4;
    float pastryPrice = 3.5;

    int coffeeQty, teaQty, sandwichQty, pastryQty;
    float coffeeTotal, teaTotal, sandwichTotal, pastryTotal, totalBill;

    // Take order from customers
    printf("\nEnter the quantity of coffee: ");
    scanf("%d", &coffeeQty);
    coffeeTotal = calculateBill(coffeeQty, coffeePrice);

    printf("Enter the quantity of tea: ");
    scanf("%d", &teaQty);
    teaTotal = calculateBill(teaQty, teaPrice);

    printf("Enter the quantity of sandwich: ");
    scanf("%d", &sandwichQty);
    sandwichTotal = calculateBill(sandwichQty, sandwichPrice);

    printf("Enter the quantity of pastry: ");
    scanf("%d", &pastryQty);
    pastryTotal = calculateBill(pastryQty, pastryPrice);

    // Calculate total bill amount
    totalBill = coffeeTotal + teaTotal + sandwichTotal + pastryTotal;

    printf("\n\nC Cafe Billing Statement\n");
    printf("----------------------------\n");

    // Display order summary
    printf("%d x coffee: $%.2f\n", coffeeQty, coffeeTotal);
    printf("%d x tea: $%.2f\n", teaQty, teaTotal);
    printf("%d x sandwich: $%.2f\n", sandwichQty, sandwichTotal);
    printf("%d x pastry: $%.2f\n", pastryQty, pastryTotal);

    // Display total bill amount
    printf("----------------------------\n");
    printf("Total bill amount: $%.2f\n", totalBill);
    printf("----------------------------\n");

    return 0;
}
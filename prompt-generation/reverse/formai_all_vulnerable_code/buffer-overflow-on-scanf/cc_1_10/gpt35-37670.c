//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>

// function to calculate total cost
void calculateTotal(int quantity, int pricePerItem);

int main() {
    // variables to store orders
    int coffee = 0, tea = 0, sandwich = 0;
    
    // variables to store prices
    int coffeePrice = 20, teaPrice = 15, sandwichPrice = 30;

    // variables to store total cost
    int totalCoffeeCost = 0, totalTeaCost = 0, totalSandwichCost = 0, grandTotal = 0;

    // get input from user
    printf("Enter the number of coffees: ");
    scanf("%d", &coffee);
    
    printf("Enter the number of teas: ");
    scanf("%d", &tea);

    printf("Enter the number of sandwiches: ");
    scanf("%d", &sandwich);

    // calculate the total cost of each order
    calculateTotal(coffee, coffeePrice);
    calculateTotal(tea, teaPrice);
    calculateTotal(sandwich, sandwichPrice);

    // calculate the grand total
    totalCoffeeCost = coffee * coffeePrice;
    totalTeaCost = tea * teaPrice;
    totalSandwichCost = sandwich * sandwichPrice;

    grandTotal = totalCoffeeCost + totalTeaCost + totalSandwichCost;

    // print the bill
    printf("\n\n\n\t\t  C Cafe\n");
    printf("\t----------------------------------\n");
    printf("\tItem \t\tQuantity \tCost\n");
    printf("\t----------------------------------\n");
    printf("\tCoffee \t\t%d \t\t%d\n", coffee, totalCoffeeCost);
    printf("\tTea \t\t%d \t\t%d\n", tea, totalTeaCost);
    printf("\tSandwich \t%d \t\t%d\n", sandwich, totalSandwichCost);
    printf("\t----------------------------------\n");
    printf("\tGrand Total \t\t\t%d\n", grandTotal);

    return 0;
}

// function to calculate total cost
void calculateTotal(int quantity, int pricePerItem) {
    int total = quantity * pricePerItem;
}
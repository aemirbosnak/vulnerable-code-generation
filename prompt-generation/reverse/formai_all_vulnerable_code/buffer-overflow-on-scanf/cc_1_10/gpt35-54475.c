//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

// define the cost of each item
#define COFFEE_COST 50
#define TEA_COST 40
#define SANDWICH_COST 80
#define CAKE_COST 100

// function to get the input from user
void getInput(int *coffeeQty, int *teaQty, int *sandwichQty, int *cakeQty) {
    printf("Enter the quantity of Coffee: ");
    scanf("%d", coffeeQty);
    printf("Enter the quantity of Tea: ");
    scanf("%d", teaQty);
    printf("Enter the quantity of Sandwich: ");
    scanf("%d", sandwichQty);
    printf("Enter the quantity of Cake: ");
    scanf("%d", cakeQty);
}

// function to calculate the total bill amount
int calculateBill(int coffeeQty, int teaQty, int sandwichQty, int cakeQty) {
    int totalBill = 0;
    totalBill += (coffeeQty * COFFEE_COST);
    totalBill += (teaQty * TEA_COST);
    totalBill += (sandwichQty * SANDWICH_COST);
    totalBill += (cakeQty * CAKE_COST);
    return totalBill;
}

int main() {
    int coffeeQty, teaQty, sandwichQty, cakeQty;
    int billAmount;
    
    // get input from user
    getInput(&coffeeQty, &teaQty, &sandwichQty, &cakeQty);
    
    // calculate the bill amount
    billAmount = calculateBill(coffeeQty, teaQty, sandwichQty, cakeQty);
    
    // print the bill amount
    printf("-------------------------------------------\n");
    printf("            CAFE BILLING SYSTEM            \n");
    printf("-------------------------------------------\n");
    printf("\n");
    printf("Quantity of Coffee: %d\n", coffeeQty);
    printf("Quantity of Tea: %d\n", teaQty);
    printf("Quantity of Sandwich: %d\n", sandwichQty);
    printf("Quantity of Cake: %d\n", cakeQty);
    printf("\n");
    printf("Total Bill Amount: %d\n", billAmount);
    
    // exit the program
    return 0;
}
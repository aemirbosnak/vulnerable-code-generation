//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// function prototypes
float calculateBill(int, float);
void printBill(int, float, float);
void updateSales(float);

// global variables
float totalSales = 0;

int main() {

    int quantity;
    float price, billAmount;

    // input quantity
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // input price per item
    printf("Enter the price per item: ");
    scanf("%f", &price);

    // calculate bill
    billAmount = calculateBill(quantity, price);

    // print bill
    printBill(quantity, price, billAmount);

    // update sales total
    updateSales(billAmount);

    return 0;
}

// function to calculate the bill amount
float calculateBill(int quantity, float price) {
    return quantity * price;
}

// function to print the bill
void printBill(int quantity, float price, float billAmount) {
    printf("\n");
    printf("******************************\n");
    printf("          C CAFE\n");
    printf("******************************\n");
    printf("Quantity: %d\n", quantity);
    printf("Price per item: %.2f\n", price);
    printf("----------------------------\n");
    printf("Total: %.2f\n", billAmount);
    printf("******************************\n");
}

// function to update the total sales
void updateSales(float billAmount) {
    totalSales += billAmount;
    printf("Total Sales: %.2f\n", totalSales);
}
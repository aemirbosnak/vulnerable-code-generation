//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a unique order number
int generateOrderNumber() {
    time_t now = time(0);
    return (int)now;
}

// Function to calculate the total cost of all items in the order
float calculateTotalCost(int orderNumber, float *itemPrices, int numItems) {
    float totalCost = 0.0;
    
    for (int i = 0; i < numItems; i++) {
        totalCost += itemPrices[i];
    }
    
    return totalCost;
}

// Function to print the order details
void printOrderDetails(int orderNumber, float totalCost) {
    printf("Order Number: %d\n", orderNumber);
    printf("Total Cost: $%.2f\n", totalCost);
}

// Function to print the menu
void printMenu() {
    printf("Cafe Menu:\n");
    printf("=================\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.75\n");
    printf("3. Pastry - $3.25\n");
    printf("4. Sandwich - $4.50\n");
    printf("5. Salad - $5.75\n");
    printf("6. Soup - $3.75\n");
    printf("7. Smoothie - $4.25\n");
    printf("8. Juice - $3.00\n");
    printf("9. Water - $1.50\n");
    printf("10. Soda - $2.00\n");
    printf("=================\n");
}

// Function to take the order
void takeOrder(int orderNumber, float *itemPrices, int numItems) {
    printf("Enter the item number you want to order (1-10): ");
    int itemNumber;
    scanf("%d", &itemNumber);

    if (itemNumber >= 1 && itemNumber <= 10) {
        for (int i = 0; i < numItems; i++) {
            if (itemNumber == i+1) {
                itemPrices[i] = 0.0;
            }
        }
    } else {
        printf("Invalid item number!\n");
    }
}

// Main function
int main() {
    int numItems = 0;
    float itemPrices[10] = {0.0};
    int orderNumber = generateOrderNumber();

    printf("Welcome to the Cafe! Order number %d.\n", orderNumber);
    printMenu();

    while (numItems < 10) {
        takeOrder(orderNumber, itemPrices, numItems);
        numItems++;
    }

    float totalCost = calculateTotalCost(orderNumber, itemPrices, numItems);
    printOrderDetails(orderNumber, totalCost);

    return 0;
}
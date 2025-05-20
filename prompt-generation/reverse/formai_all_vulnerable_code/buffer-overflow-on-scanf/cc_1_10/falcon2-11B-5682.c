//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define a structure for a stock
typedef struct {
    char symbol[5];
    double price;
    int quantity;
} Stock;

// Function to get stock information from the user
Stock getStockInfo() {
    Stock stock;
    printf("Enter stock symbol: ");
    scanf("%s", stock.symbol);
    printf("Enter current price: ");
    scanf("%lf", &stock.price);
    printf("Enter quantity: ");
    scanf("%d", &stock.quantity);
    return stock;
}

// Function to print stock information
void printStockInfo(Stock stock) {
    printf("Stock Symbol: %s\n", stock.symbol);
    printf("Current Price: %.2lf\n", stock.price);
    printf("Quantity: %d\n", stock.quantity);
}

// Function to update stock price
void updateStockPrice(Stock stock) {
    double newPrice = stock.price * 1.05;
    stock.price = newPrice;
}

// Function to calculate profit or loss
double calculateProfitLoss(Stock stock) {
    double profitLoss = stock.price * stock.quantity - stock.price * stock.quantity;
    return profitLoss;
}

int main() {
    srand(time(0)); // Seed random number generator with current time
    Stock stock = getStockInfo();
    printf("Initial Stock Information:\n");
    printStockInfo(stock);
    printf("\n");

    for (int i = 0; i < 100; i++) {
        updateStockPrice(stock);
        double profitLoss = calculateProfitLoss(stock);
        printf("Iteration %d\n", i+1);
        printf("Current Stock Information:\n");
        printStockInfo(stock);
        printf("\n");
        printf("Profit or Loss: %.2lf\n", profitLoss);
        printf("\n");
    }

    return 0;
}
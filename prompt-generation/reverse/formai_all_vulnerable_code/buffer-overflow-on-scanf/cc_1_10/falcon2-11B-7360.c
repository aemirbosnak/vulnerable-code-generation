//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a stock
typedef struct {
    char symbol[10];
    double price;
} Stock;

// Function to get user input for a stock's symbol and price
Stock getStockInfo(char *symbol, double *price) {
    printf("Enter the symbol of the stock (max 10 characters): ");
    scanf("%s", symbol);

    printf("Enter the current price of the stock: ");
    scanf("%lf", price);

    return (Stock){symbol, *price};
}

// Function to print the information of a stock
void printStock(Stock stock) {
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: %.2f\n", stock.price);
}

// Function to get a random stock price between $10 and $100
double getRandomPrice() {
    srand(time(0));
    double price = (rand() % 91) + 10;
    return price;
}

// Function to update the price of a stock
void updatePrice(Stock *stock, double newPrice) {
    stock->price = newPrice;
}

// Function to main function
int main() {
    Stock apple = getStockInfo("AAPL", &apple.price);
    printf("Apple stock information:\n");
    printStock(apple);

    double randomPrice = getRandomPrice();
    updatePrice(&apple, randomPrice);
    printf("Updated Apple stock information:\n");
    printStock(apple);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stock
typedef struct {
    char name[50];
    float price;
    int quantity;
} Stock;

// Function to create a new stock
Stock* createStock(char* name, float price, int quantity) {
    Stock* stock = (Stock*)malloc(sizeof(Stock));
    strcpy(stock->name, name);
    stock->price = price;
    stock->quantity = quantity;
    return stock;
}

// Function to buy stocks
void buyStock(Stock* stock, int quantity) {
    if (stock->quantity >= quantity) {
        stock->quantity -= quantity;
        printf("You bought %d units of %s at $%.2f each.\n", quantity, stock->name, stock->price);
    } else {
        printf("Not enough stocks available.\n");
    }
}

// Function to sell stocks
void sellStock(Stock* stock, int quantity) {
    if (stock->quantity >= quantity) {
        stock->quantity -= quantity;
        printf("You sold %d units of %s at $%.2f each.\n", quantity, stock->name, stock->price);
    } else {
        printf("Not enough stocks available.\n");
    }
}

// Function to display the current status of all stocks
void displayStocks(Stock* stocks, int numStocks) {
    printf("\nCurrent status:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s - Price: $%.2f - Quantity: %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    // Initialize the stocks
    Stock* stocks[3] = {
        createStock("Apple", 100.00, 1000),
        createStock("Microsoft", 50.00, 2000),
        createStock("Google", 75.00, 1500)
    };

    // Simulate buying and selling of stocks
    buyStock(stocks[0], 200);
    sellStock(stocks[1], 500);
    buyStock(stocks[2], 1000);

    // Display the current status of all stocks
    displayStocks(stocks, 3);

    return 0;
}
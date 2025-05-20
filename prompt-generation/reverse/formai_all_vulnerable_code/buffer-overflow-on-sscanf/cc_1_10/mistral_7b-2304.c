//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[5];
    float price;
    int change;
} Stock;

void getStockData(Stock* stock, char* symbol) {
    FILE* file = fopen("stocks.txt", "r");
    char line[100];
    int index = 0;

    while (fgets(line, sizeof(line), file)) {
        index++;
        if (strncmp(line, symbol, strlen(symbol)) == 0) {
            sscanf(line, "%s%f%d", stock->symbol, &stock->price, &stock->change);
            break;
        }
    }

    fclose(file);
}

void printStockData(Stock stock) {
    printf("| %-4s | %-10.2f | %-5d |\n", stock.symbol, stock.price, stock.change);
}

int main() {
    Stock stocks[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter stock symbol: ");
        char symbol[5];
        scanf("%s", symbol);

        getStockData(&stocks[i], symbol);
        printStockData(stocks[i]);
    }

    return 0;
}

/*
This program reads stock data from a file named "stocks.txt" and tracks the current price and change in price for up to 5 stocks.
The user inputs the stock symbol, and the program retrieves the corresponding data from the file using the getStockData function.
The data is then printed to the console using the printStockData function.
*/
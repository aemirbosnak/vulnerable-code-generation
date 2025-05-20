//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store stock market data
typedef struct StockMarketData {
    char name[20];
    double price;
    double change;
    double previousClose;
} StockMarketData;

// Create a function to get the stock market data from a file
StockMarketData* getStockMarketData(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    StockMarketData* data = malloc(sizeof(StockMarketData));
    data->name[0] = '\0';
    data->price = 0.0;
    data->change = 0.0;
    data->previousClose = 0.0;

    fscanf(file, "%s %lf %lf %lf", data->name, &data->price, &data->change, &data->previousClose);

    fclose(file);
    return data;
}

// Create a function to print the stock market data
void printStockMarketData(StockMarketData* data) {
    printf("Name: %s\n", data->name);
    printf("Price: %.2lf\n", data->price);
    printf("Change: %.2lf%\n", data->change);
    printf("Previous Close: %.2lf\n", data->previousClose);
    printf("\n");
}

int main() {
    // Get the stock market data from a file
    StockMarketData* data = getStockMarketData("stock_market_data.txt");

    // Print the stock market data
    printStockMarketData(data);

    // Free the memory allocated for the data structure
    free(data);

    return 0;
}
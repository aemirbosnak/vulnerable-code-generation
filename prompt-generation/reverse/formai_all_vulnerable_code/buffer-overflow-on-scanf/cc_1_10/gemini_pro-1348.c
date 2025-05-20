//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char symbol[10];
    char name[20];
    double price;
    double change;
} Stock;

// Define the function to compare two stocks
int compare_stocks(const void *a, const void *b) {
    const Stock *stock1 = (const Stock *)a;
    const Stock *stock2 = (const Stock *)b;

    // Compare the stocks by their symbol
    return strcmp(stock1->symbol, stock2->symbol);
}

// Define the function to print a stock
void print_stock(const Stock *stock) {
    printf("%-10s %-20s $%.2f %.2f%%\n", stock->symbol, stock->name, stock->price, stock->change);
}

// Define the main function
int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];

    // Initialize the array of stocks
    for (int i = 0; i < MAX_STOCKS; i++) {
        stocks[i].symbol[0] = '\0';
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].change = 0.0;
    }

    // Get the number of stocks
    int num_stocks;
    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    // Get the data for each stock
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the name for stock %d: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter the price for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the change for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].change);
    }

    // Sort the array of stocks by symbol
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    // Print the array of stocks
    printf("\n%-10s %-20s Price Change\n", "Symbol", "Name");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}
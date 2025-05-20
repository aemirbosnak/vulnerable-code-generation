//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_STOCKS 100

// A simple struct to represent a stock
typedef struct {
    char *name;
    double price;
    int quantity;
} Stock;

// A function to compare two stocks by name
int compare_stocks(const void *a, const void *b) {
    Stock *stock1 = (Stock *)a;
    Stock *stock2 = (Stock *)b;
    return strcmp(stock1->name, stock2->name);
}

// A function to print a stock
void print_stock(Stock *stock) {
    printf("%s: $%.2f (%d)\n", stock->name, stock->price, stock->quantity);
}

// A function to buy a stock
void buy_stock(Stock *stock, int quantity) {
    stock->quantity += quantity;
}

// A function to sell a stock
void sell_stock(Stock *stock, int quantity) {
    stock->quantity -= quantity;
}

int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    // Read in the stock data from a file
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (1) {
        char name[100];
        double price;
        int quantity;
        int num_read = fscanf(file, "%s %lf %d\n", name, &price, &quantity);
        if (num_read != 3) {
            break;
        }
        if (num_stocks == MAX_STOCKS) {
            printf("Error: Too many stocks\n");
            return EXIT_FAILURE;
        }
        stocks[num_stocks].name = strdup(name);
        stocks[num_stocks].price = price;
        stocks[num_stocks].quantity = quantity;
        num_stocks++;
    }
    fclose(file);

    // Sort the stocks by name
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    // Print the stocks
    printf("Current stock portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    // Buy some stocks
    buy_stock(&stocks[0], 100);
    buy_stock(&stocks[1], 50);

    // Sell some stocks
    sell_stock(&stocks[0], 25);
    sell_stock(&stocks[1], 10);

    // Print the stocks again
    printf("\nUpdated stock portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    // Free the memory allocated for the stock names
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }

    return EXIT_SUCCESS;
}
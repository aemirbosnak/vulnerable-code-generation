//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} stock_t;

int main() {
    int num_stocks;
    stock_t stocks[MAX_STOCKS];

    // Read in the number of stocks
    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    // Read in the stock information
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock #%d information:\n", i + 1);
        printf("Name (up to %d characters): ", MAX_NAME_LEN);
        scanf("%s", stocks[i].name);
        printf("Symbol (up to %d characters): ", MAX_SYMBOL_LEN);
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
    }

    // Print the stock information
    printf("\nStock Information:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%d. %s (%s) - $%.2f\n", i + 1, stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    // Allow the user to search for a stock by name or symbol
    char search_input[MAX_SYMBOL_LEN];
    printf("\nEnter a stock name or symbol to search for: ");
    scanf("%s", search_input);

    int found_stock = 0;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, search_input) == 0 || strcmp(stocks[i].symbol, search_input) == 0) {
            printf("\nFound stock:\n");
            printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
            found_stock = 1;
            break;
        }
    }

    if (!found_stock) {
        printf("\nStock not found.\n");
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    if (numStocks > MAX_STOCKS) {
        printf("Error: Maximum number of stocks is %d.\n", MAX_STOCKS);
        return 1;
    }

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock information for %d:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);

        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);

        printf("Price: ");
        scanf("%lf", &stocks[i].price);

        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    printf("\nStock Market Tracker\n");
    printf("=====================\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s (%s) - Price: $%.2f - Quantity: %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}
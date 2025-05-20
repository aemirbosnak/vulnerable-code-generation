//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#define MAX_STOCKS 10
#define PRICE_SIZE 10

typedef struct {
    char symbol[5];
    float price[PRICE_SIZE];
    int index;
} Stock;

void updatePrice(Stock *stock, float newPrice) {
    stock->price[stock->index] = newPrice;
    stock->index++;
    if (stock->index >= PRICE_SIZE) {
        stock->index = 0;
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    while (numStocks < MAX_STOCKS) {
        printf("Enter stock symbol (or 'q' to quit): ");
        scanf("%s", stocks[numStocks].symbol);

        if (stocks[numStocks].symbol[0] == 'q' || numStocks >= MAX_STOCKS) {
            break;
        }

        printf("Enter initial stock price: ");
        scanf("%f", &stocks[numStocks].price[0]);

        numStocks++;
    }

    float totalPrice = 0;
    float averagePrice = 0;
    float minPrice = stocks[0].price[0];
    float maxPrice = stocks[0].price[0];

    for (int i = 0; i < numStocks; i++) {
        printf("\nStock %s\n", stocks[i].symbol);
        for (int j = 0; j < PRICE_SIZE; j++) {
            float newPrice;
            printf("Enter stock price %d: ", j + 1);
            scanf("%f", &newPrice);

            updatePrice(&stocks[i], newPrice);

            stocks[i].price[j] = newPrice;
            totalPrice += newPrice;

            if (newPrice < minPrice) {
                minPrice = newPrice;
            }

            if (newPrice > maxPrice) {
                maxPrice = newPrice;
            }
        }

        averagePrice = totalPrice / (PRICE_SIZE * 1.0);
        printf("Total price: %.2f\n", totalPrice);
        printf("Average price: %.2f\n", averagePrice);
        printf("Minimum price: %.2f\n", minPrice);
        printf("Maximum price: %.2f\n", maxPrice);
        printf("\n");
    }

    return 0;
}
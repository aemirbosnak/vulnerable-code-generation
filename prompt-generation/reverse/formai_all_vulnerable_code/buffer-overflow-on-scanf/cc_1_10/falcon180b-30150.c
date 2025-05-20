//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_SYMBOLS 20
#define MAX_PRICES 1000

typedef struct {
    char symbol[MAX_SYMBOLS];
    float price;
} Stock;

int main() {
    int numStocks;
    printf("Enter number of stocks to track: ");
    scanf("%d", &numStocks);

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock symbol for %d: ", i+1);
        scanf("%s", stocks[i].symbol);
        stocks[i].price = 0.0;
    }

    while (1) {
        printf("\nEnter command:\n");
        printf("1. Update stock prices\n");
        printf("2. Display stock prices\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < numStocks; i++) {
                    printf("Enter new price for %s: ", stocks[i].symbol);
                    scanf("%f", &stocks[i].price);
                }
                break;
            case 2:
                for (int i = 0; i < numStocks; i++) {
                    printf("%s: $%.2f\n", stocks[i].symbol, stocks[i].price);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
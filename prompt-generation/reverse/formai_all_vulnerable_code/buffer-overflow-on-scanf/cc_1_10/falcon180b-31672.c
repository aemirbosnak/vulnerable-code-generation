//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    printf("Enter the number of stocks you want to track (up to %d):\n", MAX_STOCKS);
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("Enter the name of stock %d:\n", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d:\n", i+1);
        scanf("%s", stocks[i].symbol);

        stocks[i].price = 0.0;
    }

    while (1) {
        system("clear");

        printf("Stock Market Tracker\n");

        for (int i = 0; i < numStocks; i++) {
            printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("\nEnter 'q' to quit or any other key to refresh in 5 seconds:\n");
        char choice = getchar();

        if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            sleep(5);
        }
    }

    return 0;
}
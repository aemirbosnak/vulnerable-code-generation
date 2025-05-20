//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];
    char input[100];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock %d name: ", i+1);
        scanf("%s", stocks[i].name);
        printf("Enter stock %d symbol: ", i+1);
        scanf("%s", stocks[i].symbol);
        printf("Enter stock %d price: ", i+1);
        scanf("%s", stocks[i].price);
    }

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "update") == 0) {
            printf("Enter stock symbol to update: ");
            scanf("%s", input);

            for (int i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    printf("Enter new price for %s: ", stocks[i].name);
                    scanf("%s", stocks[i].price);
                    printf("%s price updated.\n", stocks[i].name);
                    break;
                }
            }
        } else if (strcmp(input, "report") == 0) {
            printf("\nStock Report:\n");
            for (int i = 0; i < numStocks; i++) {
                printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price));
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[100];
    char delimiter = ',';

    printf("Enter stock information (name, symbol, price):\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, &delimiter);
        if (token == NULL) {
            break;
        }

        if (numStocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            return 1;
        }

        strcpy(stocks[numStocks].name, token);
        strcpy(stocks[numStocks].symbol, strtok(NULL, &delimiter));
        stocks[numStocks].price = atof(strtok(NULL, &delimiter));

        numStocks++;
    }

    printf("\nStock Market Tracker\n");
    printf("=====================\n");

    while (1) {
        system("clear");
        printf("Enter the stock symbol to track:\n");
        scanf("%s", input);

        int found = 0;
        for (int i = 0; i < numStocks; i++) {
            if (strcmp(stocks[i].symbol, input) == 0) {
                printf("\nStock Information:\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Symbol: %s\n", stocks[i].symbol);
                printf("Price: $%.2f\n", stocks[i].price);

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Stock not found.\n");
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}
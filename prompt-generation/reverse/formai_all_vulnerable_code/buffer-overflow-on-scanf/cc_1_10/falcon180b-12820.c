//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
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
} stock_t;

int main() {
    int num_stocks;
    stock_t stocks[MAX_STOCKS];
    char input_buffer[1000];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%s", stocks[i].price);
    }

    while (1) {
        printf("\nStock market tracker:\n");
        printf("---------------------\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%d. %s (%s) - $%.2f\n", i+1, stocks[i].name, stocks[i].symbol, atof(stocks[i].price));
        }
        printf("\nEnter a stock symbol to track: ");
        scanf("%s", input_buffer);
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].symbol, input_buffer) == 0) {
                printf("\nStock information:\n");
                printf("---------------------\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Symbol: %s\n", stocks[i].symbol);
                printf("Price: $%.2f\n", atof(stocks[i].price));
                break;
            }
        }
        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}
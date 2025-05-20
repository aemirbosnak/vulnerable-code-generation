//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

void read_stocks_csv(stock_t stocks[], int max_stocks) {
    FILE *csv_file = fopen("stocks.csv", "r");
    if (csv_file == NULL) {
        printf("Error: could not open stocks.csv\n");
        exit(1);
    }

    int num_stocks = 0;
    while (num_stocks < max_stocks && fscanf(csv_file, "%s,%s,%s,%s\n", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price, stocks[num_stocks].volume) == 4) {
        num_stocks++;
    }

    fclose(csv_file);
}

void print_stock(stock_t stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%.2f\n", atof(stock.price));
    printf("Volume: %s\n", stock.volume);
    printf("\n");
}

void print_stocks(stock_t stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <stocks.csv>\n", argv[0]);
        return 1;
    }

    stock_t stocks[MAX_STOCKS];
    read_stocks_csv(stocks, MAX_STOCKS);

    int num_stocks = 0;
    while (num_stocks < MAX_STOCKS && stocks[num_stocks].name[0]!= '\0') {
        num_stocks++;
    }

    printf("Stock Market Tracker\n");
    printf("=====================\n");
    print_stocks(stocks, num_stocks);

    return 0;
}
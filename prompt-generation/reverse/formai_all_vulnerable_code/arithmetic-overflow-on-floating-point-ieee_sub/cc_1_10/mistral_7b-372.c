//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    float current_price;
    float previous_close;
    float change_percent;
} Stock;

void get_stock_quote(Stock* stock, char* symbol) {
    FILE* file = fopen("quotes.txt", "r");
    char line[100];
    char symbol_temp[MAX_SYMBOL_LENGTH];
    float current_price, previous_close;

    if (file == NULL) {
        printf("Error: Unable to open quotes file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%f%f%f", symbol_temp, &previous_close, &current_price);

        if (strcmp(symbol_temp, symbol) == 0) {
            stock->current_price = current_price;
            stock->previous_close = previous_close;

            stock->change_percent = ((stock->current_price - stock->previous_close) / stock->previous_close) * 100;

            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Error: Stock symbol %s not found.\n", symbol);
    exit(1);
}

void print_stock_info(Stock stock) {
    printf("\nStock Information:\n");
    printf("Symbol: %s\n", stock.symbol);
    printf("Current Price: %.2f\n", stock.current_price);
    printf("Previous Close: %.2f\n", stock.previous_close);
    printf("Change Percent: %.2f%%\n", stock.change_percent);
}

int main(int argc, char* argv[]) {
    Stock stocks[MAX_STOCKS];
    char symbol[MAX_SYMBOL_LENGTH];
    int num_stocks = 0;

    srand(time(NULL));

    while (num_stocks < MAX_STOCKS && fgets(symbol, sizeof(symbol), stdin)) {
        if (symbol[0] == '\n') break;

        get_stock_quote(&stocks[num_stocks], symbol);
        print_stock_info(stocks[num_stocks]);
        num_stocks++;
    }

    return 0;
}
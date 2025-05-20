//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_SYMBOL_LENGTH 10

struct Stock {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    float current_price;
    float previous_close;
    float change_percent;
};

void get_stock_data(struct Stock *stock, char *symbol) {
    FILE *file;
    char line[100];
    int symbol_length = strlen(symbol);

    file = fopen("stock_data.csv", "r");
    while (fgets(line, sizeof(line), file)) {
        char symbol_found[MAX_SYMBOL_LENGTH + 1];
        sscanf(line, "%s%f%f%f", symbol_found, &stock->previous_close, &stock->current_price, &stock->change_percent);
        if (symbol_length == strlen(symbol_found) && strcmp(symbol_found, symbol) == 0) {
            stock->symbol[strlen(symbol)] = '\0';
            strncpy(stock->symbol, symbol_found, MAX_SYMBOL_LENGTH);
            fclose(file);
            return;
        }
    }
    fclose(file);
    perror("Error reading stock data file");
}

void print_stock(struct Stock stock) {
    printf("%s: %.2f (%.2f%%)\n", stock.symbol, stock.current_price, stock.change_percent);
}

int main() {
    struct Stock stocks[MAX_STOCKS];
    char symbols[MAX_STOCKS][MAX_SYMBOL_LENGTH];

    srand(time(NULL));

    for (int i = 0; i < MAX_STOCKS; i++) {
        char symbol[MAX_SYMBOL_LENGTH];
        sprintf(symbol, "AAPL%d", rand() % 1000);
        strcpy(symbols[i], symbol);
        get_stock_data(&stocks[i], symbol);
    }

    for (int i = 0; i < MAX_STOCKS; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
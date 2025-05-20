//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_SYMBOL_LENGTH 10
#define DELAY_BETWEEN_UPDATES 60 // in seconds

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    float current_price;
    float previous_price;
    float change_percent;
} Stock;

Stock stocks[MAX_COMPANIES];

void print_header() {
    printf("%-10s %-15s %-10s %-10s\n", "Symbol", "Company Name", "Current Price", "Change Percent");
}

void print_stock(Stock stock) {
    printf("%-10s %-15s $%.2f $%.2f%%\n", stock.symbol, "Company Name Here", stock.current_price, stock.change_percent);
}

void update_prices() {
    FILE *file = fopen("stock_prices.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to read stock prices file.\n");
        return;
    }

    int i;
    for (i = 0; i < MAX_COMPANIES && fscanf(file, "%s %f %f", stocks[i].symbol, &stocks[i].current_price, &stocks[i].previous_price) == 3; i++);
    fclose(file);

    for (i = 0; i < MAX_COMPANIES; i++) {
        if (stocks[i].previous_price == 0.0f) { // skip if price not yet available
            continue;
        }

        stocks[i].change_percent = ((stocks[i].current_price - stocks[i].previous_price) / stocks[i].previous_price) * 100.0f;
    }
}

void print_stocks() {
    print_header();

    int i;
    for (i = 0; i < MAX_COMPANIES && stocks[i].symbol[0] != '\0'; i++) {
        print_stock(stocks[i]);
    }
}

void main() {
    srand(time(NULL));

    while (1) {
        update_prices();
        print_stocks();
        sleep(DELAY_BETWEEN_UPDATES);
    }
}
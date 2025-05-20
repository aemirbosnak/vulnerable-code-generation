//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 50
#define PRICE_FILE "prices.txt"
#define THRESHOLD 0.05

typedef struct {
    char symbol[5];
    double price[2];
} Stock;

void read_prices(FILE *fp, Stock stocks[]) {
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%s %lf %lf", stocks[i].symbol, &stocks[i].price[0], &stocks[i].price[1]) != 3) {
            printf("Invalid line: %s\n", line);
            exit(1);
        }
        i++;
        if (i >= MAX_STOCKS) {
            printf("Too many stocks in file\n");
            exit(1);
        }
    }
}

void print_stocks(Stock stocks[]) {
    int i;
    for (i = 0; i < sizeof(stocks) / sizeof(Stock); i++) {
        double percent_change = (stocks[i].price[1] - stocks[i].price[0]) / stocks[i].price[0] * 100;
        if (percent_change > THRESHOLD) {
            printf("%s: %.2f%%\n", stocks[i].symbol, percent_change);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    FILE *fp;

    fp = fopen(PRICE_FILE, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", PRICE_FILE);
        exit(1);
    }

    read_prices(fp, stocks);
    fclose(fp);

    printf("Stock price changes:\n");
    print_stocks(stocks);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    float price;
    float change;
} Stock;

void print_header() {
    printf("%-*s %-*s %10s %10s\n", 20, "NAME", 20, "SYMBOL", "PRICE", "CHANGE");
}

void load_stocks(Stock stocks[], char filename[]) {
    FILE *fp;
    int i = 0;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %f %f", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].change) != EOF) {
        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    int i;

    print_header();

    for (i = 0; i < num_stocks; i++) {
        printf("%-*s %-*s %10.2f %10.2f\n", 20, stocks[i].name, 20, stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    char filename[MAX_NAME_LEN] = "stocks.txt";
    int num_stocks;

    load_stocks(stocks, filename);
    num_stocks = sizeof(stocks) / sizeof(Stock);

    printf("---------------------------------------------------------\n");
    printf("|               Sherlock Holmes Stock Market Tracker       |\n");
    printf("|                         Version 1.0                    |\n");
    printf("---------------------------------------------------------\n");

    print_stocks(stocks, num_stocks);

    return 0;
}
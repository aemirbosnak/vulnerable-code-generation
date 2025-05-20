//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    double change;
    double percentage_change;
} Stock;

void read_stocks_from_file(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open stocks.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %lf %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].percentage_change) == 5 && i < num_stocks) {
        i++;
    }

    fclose(fp);
}

void print_stock_table_header() {
    printf("+--------------------+--------------------+--------------------+\n");
    printf("| Name               | Symbol             | Price              |\n");
    printf("+--------------------+--------------------+--------------------+\n");
}

void print_stock(Stock s) {
    printf("| %-50s | %-10s | $%.2f |\n", s.name, s.symbol, s.price);
}

void print_stock_table_row(Stock s, int row_num) {
    int padding_size = (row_num % 2 == 0)? 50 : 51;
    printf("| %-*s | %-10s | $%.2f |\n", padding_size, s.name, s.symbol, s.price);
}

void print_stock_table(Stock stocks[], int num_stocks) {
    print_stock_table_header();

    for (int i = 0; i < num_stocks; i++) {
        print_stock_table_row(stocks[i], i);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks_from_file(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    print_stock_table(stocks, num_stocks);

    return 0;
}
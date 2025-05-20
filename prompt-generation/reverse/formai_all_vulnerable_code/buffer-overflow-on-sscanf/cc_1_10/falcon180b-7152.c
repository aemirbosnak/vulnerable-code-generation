//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp;
    char line[MAX_NAME_LEN + MAX_SYMBOL_LEN + MAX_PRICE_LEN + 2];
    int i = 0;

    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_stocks) {
            printf("Error: Too many stocks in file.\n");
            fclose(fp);
            exit(1);
        }

        int j = 0;
        while (isspace(line[j])) {
            j++;
        }

        strcpy(stocks[i].name, &line[j]);
        j += strlen(stocks[i].name) + 1;

        while (isspace(line[j])) {
            j++;
        }

        strcpy(stocks[i].symbol, &line[j]);
        j += strlen(stocks[i].symbol) + 1;

        while (isspace(line[j])) {
            j++;
        }

        sscanf(&line[j], "%lf", &stocks[i].price);
        j += strlen(line) - j;

        while (isspace(line[j])) {
            j++;
        }

        if (line[j]!= '\n') {
            printf("Error: Invalid stocks file format.\n");
            fclose(fp);
            exit(1);
        }

        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    printf("Stock Name\tSymbol\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    print_stocks(stocks, num_stocks);

    return 0;
}
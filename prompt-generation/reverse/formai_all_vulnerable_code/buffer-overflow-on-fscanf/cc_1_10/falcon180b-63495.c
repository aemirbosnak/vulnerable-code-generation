//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 30
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price) == 3) {
        i++;
        if (i >= num_stocks) {
            fprintf(stderr, "Error: too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-30s %-10s $%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void sort_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = rand() % MAX_STOCKS + 1;

    printf("Showing %d random stocks:\n", num_stocks);
    for (int i = 0; i < num_stocks; i++) {
        int index = rand() % MAX_STOCKS;
        stocks[i] = stocks[index];
    }

    sort_stocks(stocks, num_stocks);
    printf("Sorted by price:\n");
    print_stocks(stocks, num_stocks);

    return 0;
}
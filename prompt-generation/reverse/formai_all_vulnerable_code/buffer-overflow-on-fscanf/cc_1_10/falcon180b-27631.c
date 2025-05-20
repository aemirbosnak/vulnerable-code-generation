//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    double current_price;
    double previous_price;
    int change;
} Stock;

void read_stocks_from_file(Stock stocks[], int num_stocks) {
    FILE *fp;
    char filename[50] = "stocks.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %lf %lf %d\n", stocks[i].name, &stocks[i].current_price, &stocks[i].previous_price, &stocks[i].change)!= EOF) {
        i++;
        if (i == num_stocks) {
            break;
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tCurrent Price\tPrevious Price\tChange\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%.2lf\t\t%.2lf\t\t%d\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks_from_file(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    print_stocks(stocks, num_stocks);

    return 0;
}
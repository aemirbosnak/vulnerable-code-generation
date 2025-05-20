//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_DATE_LEN 20
#define MAX_TIME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char date[MAX_DATE_LEN];
    char time[MAX_TIME_LEN];
} Stock;

void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: %s\n", s.price);
    printf("Volume: %s\n", s.volume);
    printf("Date: %s\n", s.date);
    printf("Time: %s\n", s.time);
}

int main() {
    FILE *fp;
    char line[1024];
    int num_stocks = 0;

    Stock stocks[MAX_STOCKS];

    fp = fopen("stock_data.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks == MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            exit(1);
        }

        sscanf(line, "%s %s %s %s %s %s",
               stocks[num_stocks].name,
               stocks[num_stocks].symbol,
               stocks[num_stocks].price,
               stocks[num_stocks].volume,
               stocks[num_stocks].date,
               stocks[num_stocks].time);

        num_stocks++;
    }

    fclose(fp);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
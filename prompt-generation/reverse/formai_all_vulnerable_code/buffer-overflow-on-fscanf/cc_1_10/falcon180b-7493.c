//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char date[MAX_DATE_LEN];
} stock_t;

int load_stocks(stock_t stocks[], int max_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s\n", stocks[count].name, stocks[count].symbol, stocks[count].price, stocks[count].volume, stocks[count].date)!= EOF) {
        count++;
        if (count >= max_stocks) {
            break;
        }
    }

    fclose(fp);
    return count;
}

void sort_stocks(stock_t stocks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(stocks[j].price, stocks[i].price) < 0) {
                stock_t temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

void print_stocks(stock_t stocks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s %s %s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].date);
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int count = load_stocks(stocks, MAX_STOCKS);

    sort_stocks(stocks, count);

    printf("Top %d stocks:\n", count);
    print_stocks(stocks, count);

    return 0;
}
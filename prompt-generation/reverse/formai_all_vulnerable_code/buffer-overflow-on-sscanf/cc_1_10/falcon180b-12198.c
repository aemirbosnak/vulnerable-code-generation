//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} Stock;

void read_stocks(Stock stocks[], int count) {
    FILE *fp;
    char line[MAX_NAME_LEN + MAX_SYMBOL_LEN + MAX_PRICE_LEN + MAX_VOLUME_LEN + 2];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open stocks.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= count) {
            printf("Error: Too many stocks in stocks.txt\n");
            exit(1);
        }

        sscanf(line, "%s %s %s %s", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s %s $%.2f %s\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), stocks[i].volume);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count;

    printf("Enter the number of stocks: ");
    scanf("%d", &count);

    if (count > MAX_STOCKS || count < 1) {
        printf("Error: Invalid number of stocks\n");
        exit(1);
    }

    read_stocks(stocks, count);
    print_stocks(stocks, count);

    return 0;
}
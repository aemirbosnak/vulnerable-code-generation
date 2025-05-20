//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_QUOTE_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double quote;
    time_t timestamp;
} Stock;

void load_stocks(Stock stocks[], int count) {
    FILE *fp;
    char line[MAX_QUOTE_LEN];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_QUOTE_LEN, fp)!= NULL) {
        if (i >= count) {
            printf("Error: Too many stocks.\n");
            exit(1);
        }

        sscanf(line, "%s %s %lf %ld", stocks[i].name, stocks[i].symbol, &stocks[i].quote, &stocks[i].timestamp);
        i++;
    }

    fclose(fp);
}

void display_stocks(Stock stocks[], int count) {
    int i;

    printf("Stock Name\tSymbol\tQuote\tTimestamp\n");

    for (i = 0; i < count; i++) {
        printf("%-20s\t%-10s\t%.2lf\t%s\n", stocks[i].name, stocks[i].symbol, stocks[i].quote, ctime(&stocks[i].timestamp));
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count;

    printf("Enter the number of stocks to track: ");
    scanf("%d", &count);

    load_stocks(stocks, count);
    display_stocks(stocks, count);

    return 0;
}
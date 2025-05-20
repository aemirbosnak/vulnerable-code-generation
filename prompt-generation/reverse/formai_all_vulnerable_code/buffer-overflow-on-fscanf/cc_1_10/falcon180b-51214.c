//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[10];
    float price;
    char date[MAX_DATE_LEN];
} Stock;

void loadStocks(Stock stocks[]) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error loading stocks.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %f %s\n", stocks[count].name, stocks[count].symbol, &stocks[count].price, stocks[count].date)!= EOF) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Maximum number of stocks reached.\n");
            exit(1);
        }
    }

    fclose(file);
}

void sortStocks(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS - 1; i++) {
        for (int j = 0; j < MAX_STOCKS - 1 - i; j++) {
            if (strcmp(stocks[j].name, stocks[j + 1].name) > 0) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

void printStocks(Stock stocks[]) {
    printf("Name\tSymbol\tPrice\tDate\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s %-10s $%.2f %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].date);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    loadStocks(stocks);
    sortStocks(stocks);
    printStocks(stocks);

    return 0;
}
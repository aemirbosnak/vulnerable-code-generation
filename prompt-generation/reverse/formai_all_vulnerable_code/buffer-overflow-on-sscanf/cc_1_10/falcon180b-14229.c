//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_PRICE_LEN 10

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[10];
    double price;
};

void load_stocks(struct stock stocks[]) {
    FILE *fp;
    char line[MAX_PRICE_LEN];
    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }
    int count = 0;
    while (fgets(line, MAX_PRICE_LEN, fp)!= NULL) {
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
        sscanf(line, "%s %s %lf", stocks[count].name, stocks[count].symbol, &stocks[count].price);
        count++;
    }
    fclose(fp);
}

void print_stocks(struct stock stocks[]) {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%s\t%s\t%lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }
    }
}

void sort_stocks(struct stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS - 1; i++) {
        for (int j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[j].price < stocks[i].price) {
                struct stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    struct stock stocks[MAX_STOCKS];
    load_stocks(stocks);
    sort_stocks(stocks);
    print_stocks(stocks);
    return 0;
}
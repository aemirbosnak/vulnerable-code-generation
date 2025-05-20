//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[5];
    float price;
} Stock;

void read_stocks(Stock* stocks) {
    FILE* fp = fopen("stocks.txt", "r");
    if (!fp) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %f\n", stocks[count].name, stocks[count].symbol, &stocks[count].price) == 3) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void print_stocks(Stock* stocks) {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s\t%s\t%-.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }
    }
}

void sort_stocks(Stock* stocks) {
    for (int i = 0; i < MAX_STOCKS - 1; i++) {
        for (int j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    read_stocks(stocks);
    printf("Unsorted stocks:\n");
    print_stocks(stocks);
    sort_stocks(stocks);
    printf("\nSorted by price:\n");
    print_stocks(stocks);

    return 0;
}
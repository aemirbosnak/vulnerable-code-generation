//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE 1000000

struct stock {
    char name[MAX_NAME_LEN + 1];
    char symbol[MAX_SYMBOL_LEN + 1];
    int price;
};

int load_stocks(struct stock* stocks) {
    FILE* fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d\n", stocks[count].name, stocks[count].symbol, &stocks[count].price) == 3 && count < MAX_STOCKS) {
        count++;
    }

    fclose(fp);
    return count;
}

int main() {
    struct stock stocks[MAX_STOCKS];
    int count = load_stocks(stocks);

    while (1) {
        printf("Stock Market Tracker - Ken Thompson Style\n");
        printf("----------------------------------------\n");
        printf("| %-20s | %-10s | %10s |\n", "Name", "Symbol", "Price");
        printf("----------------------------------------\n");

        for (int i = 0; i < count; i++) {
            printf("| %-20s | %-10s | %10d |\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("----------------------------------------\n");
        printf("Press any key to update prices...\n");
        getchar();

        count = load_stocks(stocks);
    }

    return 0;
}
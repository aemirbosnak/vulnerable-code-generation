//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_CHANGE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char change[MAX_CHANGE_LEN];
} Stock;

void readStocks(Stock stocks[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            exit(1);
        }

        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        char *price = strtok(NULL, ",");
        char *volume = strtok(NULL, ",");
        char *change = strtok(NULL, ",");

        strcpy(stocks[i].name, name);
        strcpy(stocks[i].symbol, symbol);
        strcpy(stocks[i].price, price);
        strcpy(stocks[i].volume, volume);
        strcpy(stocks[i].change, change);

        i++;
    }

    fclose(fp);
}

void displayStocks(Stock stocks[]) {
    int i;

    for (i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("Name: %s\n", stocks[i].name);
            printf("Symbol: %s\n", stocks[i].symbol);
            printf("Price: $%s\n", stocks[i].price);
            printf("Volume: %s\n", stocks[i].volume);
            printf("Change: %s\n\n", stocks[i].change);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);
    displayStocks(stocks);

    return 0;
}
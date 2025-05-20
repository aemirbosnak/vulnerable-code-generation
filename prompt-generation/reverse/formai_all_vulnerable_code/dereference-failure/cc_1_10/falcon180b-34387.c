//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void initStock(Stock* s) {
    strcpy(s->name, "");
    strcpy(s->symbol, "");
    s->price = 0;
    s->quantity = 0;
}

int main() {
    FILE* fp;
    char line[100];
    int count = 0;
    Stock stocks[MAX_STOCKS];

    initStock(&stocks[0]);

    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            fclose(fp);
            exit(1);
        }

        char* name = strtok(line, ",");
        char* symbol = strtok(NULL, ",");
        double price = strtod(strtok(NULL, ","), NULL);
        int quantity = strtol(strtok(NULL, ","), NULL, 10);

        strcpy(stocks[count].name, name);
        strcpy(stocks[count].symbol, symbol);
        stocks[count].price = price;
        stocks[count].quantity = quantity;

        count++;
    }

    fclose(fp);

    printf("\nStock Market Tracker\n");
    printf("---------------------\n");
    printf("Name\tSymbol\tPrice\tQuantity\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}
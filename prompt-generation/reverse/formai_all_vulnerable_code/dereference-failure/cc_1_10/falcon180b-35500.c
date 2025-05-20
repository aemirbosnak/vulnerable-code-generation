//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN+1];
    char symbol[MAX_SYMBOL_LEN+1];
    double price;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(0);
    }

    while (fgets(line, sizeof(line), fp)!= NULL && i < num_stocks) {
        char *token = strtok(line, ",");
        strcpy(stocks[i].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[i].symbol, token);
        token = strtok(NULL, ",");
        stocks[i].price = atof(token);
        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    int i;

    for (i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks;

    printf("Enter number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    read_stocks(stocks, num_stocks);
    print_stocks(stocks, num_stocks);

    return 0;
}
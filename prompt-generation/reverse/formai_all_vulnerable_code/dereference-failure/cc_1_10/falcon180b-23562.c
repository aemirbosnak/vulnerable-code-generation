//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    double price;
    int volume;
} Stock;

void readStocks(Stock stocks[], int n) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= n) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }

        sscanf(line, "%s %s %lf %d", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].volume);
        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%-20s %-20s $%.2lf %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n;

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    readStocks(stocks, n);
    printStocks(stocks, n);

    return 0;
}
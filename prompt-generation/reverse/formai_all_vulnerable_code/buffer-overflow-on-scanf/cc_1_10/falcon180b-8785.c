//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[10];
    double price;
} Stock;

void readStocks(Stock stocks[], int numStocks) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= numStocks) {
            printf("Error: Too many stocks in file.\n");
            fclose(fp);
            exit(1);
        }

        sscanf(line, "%s %s %lf", stocks[i].name, stocks[i].symbol, &stocks[i].price);
        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int numStocks) {
    int i;

    for (i = 0; i < numStocks; i++) {
        printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void sortStocks(Stock stocks[], int numStocks) {
    int i, j;
    Stock temp;

    for (i = 0; i < numStocks - 1; i++) {
        for (j = i + 1; j < numStocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks;

    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    readStocks(stocks, numStocks);
    sortStocks(stocks, numStocks);
    printStocks(stocks, numStocks);

    return 0;
}
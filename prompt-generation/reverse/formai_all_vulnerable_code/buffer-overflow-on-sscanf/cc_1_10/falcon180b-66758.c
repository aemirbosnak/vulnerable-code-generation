//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[10];
    float price;
} Stock;

void readStocks(Stock stocks[], int numStocks) {
    FILE *fp;
    char line[100];

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < numStocks; i++) {
        fgets(line, sizeof(line), fp);
        strcpy(stocks[i].name, line);
        strcpy(stocks[i].symbol, line + strlen(stocks[i].name) + 1);
        sscanf(line, "%s %f", stocks[i].symbol, &stocks[i].price);
    }

    fclose(fp);
}

void displayStocks(Stock stocks[], int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void sortStocks(Stock stocks[], int numStocks) {
    for (int i = 0; i < numStocks - 1; i++) {
        for (int j = i + 1; j < numStocks; j++) {
            if (stocks[j].price > stocks[i].price) {
                Stock temp = stocks[i];
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
    displayStocks(stocks, numStocks);

    return 0;
}
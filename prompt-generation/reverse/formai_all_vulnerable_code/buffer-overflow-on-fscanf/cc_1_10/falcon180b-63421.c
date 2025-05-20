//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 10
#define MAX_DAYS 365

typedef struct {
    char name[50];
    double price;
    int day;
} Stock;

void readStocks(Stock stocks[], int numStocks) {
    FILE *file;
    file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < numStocks; i++) {
        fscanf(file, "%s %lf %d\n", stocks[i].name, &stocks[i].price, &stocks[i].day);
    }
    fclose(file);
}

void writeStocks(Stock stocks[], int numStocks) {
    FILE *file;
    file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < numStocks; i++) {
        fprintf(file, "%s %lf %d\n", stocks[i].name, stocks[i].price, stocks[i].day);
    }
    fclose(file);
}

void calculatePercentChange(Stock stocks[], int numStocks) {
    int i;
    for (i = 0; i < numStocks; i++) {
        int j;
        for (j = i + 1; j < numStocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                double tempPrice = stocks[i].price;
                stocks[i].price = stocks[j].price;
                stocks[j].price = tempPrice;
            }
        }
    }
    for (i = 0; i < numStocks; i++) {
        if (stocks[i].day > 0) {
            double percentChange = ((stocks[i].price - stocks[i].day) / stocks[i].day) * 100;
            printf("%s: %.2lf%%\n", stocks[i].name, percentChange);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks;
    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);
    readStocks(stocks, numStocks);
    calculatePercentChange(stocks, numStocks);
    return 0;
}
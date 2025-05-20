//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct Stock {
    char name[25];
    float price;
    float change;
} Stock;

void printStock(Stock s) {
    printf("%-25s $%.2f %+5.2f%%\n", s.name, s.price, s.change);
}

void printHeading() {
    printf("%-25s %-10s %s\n", "Name", "Price", "Change");
    printf("%-25s %-10s %s\n", "-------------------------", "----------", "----------");
}

void printSummary(Stock *stocks, int numStocks) {
    float avgChange = 0.0f;
    for (int i = 0; i < numStocks; i++) {
        avgChange += stocks[i].change;
    }
    avgChange /= numStocks;

    printf("Average Change: %+5.2f%%\n", avgChange);

    Stock maxChangeStock = stocks[0];
    for (int i = 1; i < numStocks; i++) {
        if (stocks[i].change > maxChangeStock.change) {
            maxChangeStock = stocks[i];
        }
    }
    printf("Biggest Gainer: ");
    printStock(maxChangeStock);

    Stock minChangeStock = stocks[0];
    for (int i = 1; i < numStocks; i++) {
        if (stocks[i].change < minChangeStock.change) {
            minChangeStock = stocks[i];
        }
    }
    printf("Biggest Loser: ");
    printStock(minChangeStock);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, 100, file)) {
        char *name = strtok(buffer, ",");
        float price = strtof(strtok(NULL, ","), NULL);

        stocks[numStocks].price = price;
        stocks[numStocks].change = (price - 10) / 10 * 100; // calculate change from initial value of $10
        strcpy(stocks[numStocks].name, name);
        numStocks++;
    }
    fclose(file);

    printHeading();
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    printf("\n");
    printSummary(stocks, numStocks);

    return 0;
}
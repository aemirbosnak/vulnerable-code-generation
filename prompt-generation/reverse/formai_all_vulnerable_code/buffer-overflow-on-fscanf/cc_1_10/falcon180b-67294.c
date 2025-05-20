//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_DAYS 365

typedef struct {
    char name[30];
    double price;
} Stock;

Stock stocks[MAX_STOCKS];
double prices[MAX_STOCKS][MAX_DAYS];
int numStocks = 0;

void readStocks() {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %lf", stocks[numStocks].name, &stocks[numStocks].price) == 2) {
        numStocks++;
    }

    fclose(file);

    printf("Number of Stocks: %d\n", numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("%s - $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void generatePrices() {
    srand(time(NULL));

    for (int i = 0; i < numStocks; i++) {
        for (int j = 0; j < MAX_DAYS; j++) {
            prices[i][j] = stocks[i].price + (rand() % 50 - 25) / 100.0;
        }
    }
}

void printPrices() {
    for (int i = 0; i < numStocks; i++) {
        printf("%s Prices:\n", stocks[i].name);

        for (int j = 0; j < MAX_DAYS; j++) {
            printf("Day %d: $%.2f\n", j+1, prices[i][j]);
        }

        printf("\n");
    }
}

int main() {
    readStocks();
    generatePrices();
    printPrices();

    return 0;
}
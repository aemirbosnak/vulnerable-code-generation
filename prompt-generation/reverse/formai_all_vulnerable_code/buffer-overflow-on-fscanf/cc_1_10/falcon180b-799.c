//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    double price;
    int volume;
} Stock;

void readStocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %lf %d\n", stocks[count].name, &stocks[count].price, &stocks[count].volume)!= EOF) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void writeStocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            fprintf(fp, "%s %lf %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
        }
    }

    fclose(fp);
}

void updateStockPrices(Stock stocks[]) {
    time_t now = time(NULL);
    double changePercentage;

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            changePercentage = ((double)rand() / RAND_MAX) * 0.1 - 0.05;
            stocks[i].price += stocks[i].price * changePercentage;
            stocks[i].volume += (int)((double)stocks[i].volume * 0.1);
            stocks[i].price = round(stocks[i].price * 100) / 100;
            stocks[i].volume = round(stocks[i].volume);
        }
    }
}

void displayStocks(Stock stocks[]) {
    printf("Stock Name\tPrice\tVolume\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s $%-9.2f %10d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);

    while (1) {
        updateStockPrices(stocks);
        displayStocks(stocks);
        sleep(5);
    }

    return 0;
}
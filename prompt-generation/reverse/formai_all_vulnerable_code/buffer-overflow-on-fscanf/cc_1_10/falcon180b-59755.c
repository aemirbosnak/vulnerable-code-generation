//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    double price;
    double change;
} Stock;

void read_stock_data(Stock stocks[], int num_stocks) {
    FILE *fp;
    char filename[50];
    int i;

    for (i = 0; i < num_stocks; i++) {
        sprintf(filename, "stock_%d.txt", i+1);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: Could not open file %s\n", filename);
            exit(1);
        }

        fscanf(fp, "%s %lf %lf", stocks[i].name, &stocks[i].price, &stocks[i].change);
        fclose(fp);
    }
}

void display_stock_data(Stock stocks[], int num_stocks) {
    int i;

    for (i = 0; i < num_stocks; i++) {
        printf("%-20s $%.2f (+/-$%.2f)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void update_stock_prices(Stock stocks[], int num_stocks, int num_days) {
    int i, j;
    double change;

    for (i = 0; i < num_stocks; i++) {
        for (j = 0; j < num_days; j++) {
            change = rand() % 101 - 50; // Random change between -50 and 50 cents
            stocks[i].price += change / 100.0; // Convert cents to dollars
            stocks[i].change = change;
        }
    }
}

int main() {
    int num_stocks, num_days;
    Stock stocks[MAX_STOCKS];

    printf("Enter number of stocks to track: ");
    scanf("%d", &num_stocks);

    printf("Enter number of days to track: ");
    scanf("%d", &num_days);

    read_stock_data(stocks, num_stocks);
    printf("Initial stock data:\n");
    display_stock_data(stocks, num_stocks);

    update_stock_prices(stocks, num_stocks, num_days);
    printf("\nStock data after %d days:\n", num_days);
    display_stock_data(stocks, num_stocks);

    return 0;
}
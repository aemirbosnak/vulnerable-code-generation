//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];
    char filename[MAX_NAME_LEN];
    FILE *file;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", t);
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }
    while (fscanf(file, "%s,%s,%lf,%d\n", stocks[numStocks].name, stocks[numStocks].symbol, &stocks[numStocks].price, &stocks[numStocks].quantity)!= EOF) {
        numStocks++;
        if (numStocks >= MAX_STOCKS) {
            printf("Error: Too many stocks.\n");
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    printf("Stock Market Tracker\n");
    printf("Date: %s\n", date);
    printf("Number of stocks: %d\n", numStocks);
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s\t%-10s\t%.2lf\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
    return 0;
}
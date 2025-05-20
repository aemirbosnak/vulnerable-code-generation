//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 20
#define MAX_VOLUME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int volume;
} stock_t;

int main() {
    int num_stocks = 0;
    stock_t stocks[MAX_STOCKS];
    FILE *fp = NULL;
    char filename[MAX_NAME_LENGTH];
    char line[MAX_PRICE_LENGTH];
    char *token = NULL;
    int i = 0;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);

    printf("Enter the name of the stock data file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_PRICE_LENGTH, fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Maximum number of stocks reached.\n");
            break;
        }
        token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].symbol, token);
        stocks[num_stocks].price = atof(strtok(NULL, ","));
        stocks[num_stocks].volume = atoi(strtok(NULL, ","));
        num_stocks++;
    }

    fclose(fp);

    printf("Stock data for %s:\n", date);
    for (i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s $%.2f %10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    return 0;
}
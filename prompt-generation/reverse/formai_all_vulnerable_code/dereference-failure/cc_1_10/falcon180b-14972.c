//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SYMBOLS 100
#define MAX_HISTORY 1000

typedef struct {
    char symbol[10];
    double price;
    double change;
    double percent_change;
} stock_t;

stock_t stocks[MAX_SYMBOLS];
int num_stocks;

void load_stocks() {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error loading stocks file.\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_SYMBOLS) {
            printf("Maximum number of stocks reached.\n");
            break;
        }
        char *token = strtok(line, ",");
        strcpy(stocks[i].symbol, token);
        token = strtok(NULL, ",");
        stocks[i].price = atof(token);
        stocks[i++].change = 0.0;
        stocks[i].percent_change = 0.0;
    }
    num_stocks = i;
    fclose(fp);
}

void save_stocks() {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error saving stocks file.\n");
        exit(1);
    }

    for (int i = 0; i < num_stocks; i++) {
        fprintf(fp, "%s,%.2f,%.2f,%.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
    fclose(fp);
}

void update_stocks() {
    time_t now = time(NULL);
    for (int i = 0; i < num_stocks; i++) {
        if (stocks[i].price > 0.0) {
            stocks[i].change = stocks[i].price - stocks[i].price / (double)now;
            stocks[i].percent_change = stocks[i].change / stocks[i].price * 100.0;
        }
    }
}

void print_stocks() {
    printf("Stock Market Tracker\n");
    printf("---------------------\n");
    printf("Symbol\tPrice\tChange\tChange %\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-10s\t%.2f\t\t%.2f\t\t%.2f %%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
}

int main() {
    load_stocks();
    while (1) {
        print_stocks();
        update_stocks();
        sleep(60);
    }
    return 0;
}
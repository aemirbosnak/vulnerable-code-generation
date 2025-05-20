//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

struct stock {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
};

void read_stocks(struct stock stocks[], int n) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= n) {
            printf("Too many stocks in file\n");
            exit(1);
        }

        sscanf(line, "%s %s %lf %d", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity);
        i++;
    }

    fclose(fp);
}

void print_stocks(struct stock stocks[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%s %s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    struct stock stocks[MAX_STOCKS];
    int n;

    printf("Enter number of stocks (max %d): ", MAX_STOCKS);
    scanf("%d", &n);

    read_stocks(stocks, n);
    print_stocks(stocks, n);

    return 0;
}
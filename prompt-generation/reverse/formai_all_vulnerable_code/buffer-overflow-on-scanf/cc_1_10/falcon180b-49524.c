//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        if (i >= num_stocks) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }

        strcpy(stocks[i].name, line);
        i++;
    }

    fclose(fp);
}

void calculate_total_value(Stock stocks[], int num_stocks, double *total_value) {
    int i;

    *total_value = 0.0;

    for (i = 0; i < num_stocks; i++) {
        *total_value += stocks[i].price * stocks[i].quantity;
    }
}

void display_stocks(Stock stocks[], int num_stocks) {
    int i;

    for (i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s %10.2f %10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks;
    double total_value;

    printf("Enter the number of stocks (maximum %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    read_stocks(stocks, num_stocks);
    calculate_total_value(stocks, num_stocks, &total_value);
    display_stocks(stocks, num_stocks);

    printf("\nTotal value of stocks: $%.2f\n", total_value);

    return 0;
}
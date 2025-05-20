//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STOCKS 100
#define MAX_SYMBOL_LEN 10
#define BUFFER_SIZE 1024

typedef struct {
    char symbol[MAX_SYMBOL_LEN + 1];
    float price;
} Stock;

void read_stock_data(Stock stocks[MAX_STOCKS]);
void print_stocks(Stock stocks[MAX_STOCKS]);

int main() {
    Stock stocks[MAX_STOCKS];
    read_stock_data(stocks);
    print_stocks(stocks);
    return 0;
}

void read_stock_data(Stock stocks[]) {
    char line[BUFFER_SIZE];
    FILE *fp = fopen("stocks.txt", "r");
    int i = 0;
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUFFER_SIZE, fp)) {
        if (sscanf(line, "%s %f", stocks[i].symbol, &stocks[i].price) != 2) {
            printf("Invalid data in line: %s\n", line);
            continue;
        }
        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[]) {
    int i;
    printf("%-10s %-15s\n", "Symbol", "Price");
    printf("-------------------- --------------------");

    for (i = 0; i < i; i++) {
        printf("%-10s %-11.2f\n", stocks[i].symbol, stocks[i].price);
    }
}
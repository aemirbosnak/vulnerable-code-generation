//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_CHARACTERS 100

typedef struct {
    char symbol[MAX_CHARACTERS];
    double price;
} stock;

void initialize_stocks(stock* stocks) {
    int i;
    for (i = 0; i < MAX_STOCKS; i++) {
        stocks[i].symbol[0] = '\0';
        stocks[i].price = 0.0;
    }
}

int read_stocks(FILE* file, stock* stocks) {
    int i = 0;
    char symbol[MAX_CHARACTERS];
    double price;

    while (fscanf(file, "%s %lf", symbol, &price) == 2) {
        if (i >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            return 1;
        }
        strcpy(stocks[i].symbol, symbol);
        stocks[i].price = price;
        i++;
    }

    return 0;
}

int main() {
    FILE* file;
    char filename[MAX_CHARACTERS];
    stock stocks[MAX_STOCKS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_stocks(file, stocks);
    fclose(file);

    printf("Stock Prices:\n");
    printf("--------------------\n");
    int i;
    for (i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].symbol[0]!= '\0') {
            printf("%s: $%.2lf\n", stocks[i].symbol, stocks[i].price);
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_VALUE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    double price;
    int quantity;
} Stock;

void print_header(FILE *fp) {
    fprintf(fp, "Name\tValue\tPrice\tQuantity\n");
}

void print_stock(Stock s, FILE *fp) {
    fprintf(fp, "%s\t%s\t%.2f\t%d\n", s.name, s.value, s.price, s.quantity);
}

void print_stocks(Stock *stocks, int n, FILE *fp) {
    print_header(fp);
    for (int i = 0; i < n; i++) {
        print_stock(stocks[i], fp);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n = 0;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %lf %d", stocks[n].name, stocks[n].value, &stocks[n].price, &stocks[n].quantity) == 4) {
        n++;
        if (n == MAX_STOCKS) {
            printf("Warning: reached maximum number of stocks.\n");
            break;
        }
    }

    fclose(fp);

    FILE *out_fp = fopen("output.txt", "w");
    if (out_fp == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    print_stocks(stocks, n, out_fp);

    fclose(out_fp);

    return 0;
}
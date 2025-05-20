//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} Stock;

void read_stocks(Stock stocks[], int n) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %lf\n", stocks[i].name, &stocks[i].price)!= EOF) {
        i++;
        if (i >= n) {
            break;
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void sort_stocks(Stock stocks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n = 0;

    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &n);

    read_stocks(stocks, n);
    sort_stocks(stocks, n);
    print_stocks(stocks, n);

    return 0;
}
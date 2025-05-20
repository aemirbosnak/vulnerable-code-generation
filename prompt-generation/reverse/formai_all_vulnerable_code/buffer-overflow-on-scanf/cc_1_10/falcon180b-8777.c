//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
    time_t timestamp;
} Stock;

void print_header(FILE *fp) {
    fprintf(fp, "Name\tSymbol\tPrice\tQuantity\tTimestamp\n");
}

void print_stock(Stock s, FILE *fp) {
    fprintf(fp, "%-20s\t%-10s\t%.2f\t%d\t%s\n", s.name, s.symbol, s.price, s.quantity, ctime(&s.timestamp));
}

int compare_stocks(const void *a, const void *b) {
    const Stock *s1 = a;
    const Stock *s2 = b;

    if (s1->price > s2->price)
        return -1;
    else if (s1->price < s2->price)
        return 1;
    else
        return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the name of the stock file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %.2f %d %s", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price, &stocks[num_stocks].quantity, &stocks[num_stocks].timestamp)!= EOF) {
        num_stocks++;
    }

    fclose(fp);

    if (num_stocks == 0) {
        printf("Error: file is empty.\n");
        return 1;
    }

    print_header(stdout);
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i], stdout);
    }

    return 0;
}
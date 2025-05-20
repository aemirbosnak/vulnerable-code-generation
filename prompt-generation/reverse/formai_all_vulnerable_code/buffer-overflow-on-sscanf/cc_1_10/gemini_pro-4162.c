//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LEN 30

typedef struct {
    char name[MAX_STOCK_NAME_LEN];
    double price;
    double change;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void load_stocks() {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("Error opening stocks file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        Stock stock;
        sscanf(line, "%s %lf %lf", stock.name, &stock.price, &stock.change);
        stocks[num_stocks++] = stock;
    }

    fclose(fp);
}

void print_stocks() {
    printf("%-30s %-10s %-10s\n", "Name", "Price", "Change");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-30s $%.2f %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void update_stocks() {
    // ...
}

int main() {
    load_stocks();
    print_stocks();
    update_stocks();
    print_stocks();
    return 0;
}
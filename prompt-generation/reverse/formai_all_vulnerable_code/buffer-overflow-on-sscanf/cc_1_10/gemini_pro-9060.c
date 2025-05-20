//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAX_NAME 32
#define MAX_TICKERS 100
#define MAX_DAYS 252

typedef struct {
    char name[MAX_NAME];
    double price;
    double change;
} Stock;

typedef struct {
    Stock stocks[MAX_TICKERS];
    int num_stocks;
} Portfolio;

Portfolio portfolio = {
    .num_stocks = 0,
};

void load_portfolio() {
    FILE *fp = fopen("portfolio.txt", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        Stock stock;
        if (sscanf(line, "%s %lf %lf", stock.name, &stock.price, &stock.change) == 3) {
            portfolio.stocks[portfolio.num_stocks++] = stock;
        }
    }

    fclose(fp);
}

void print_portfolio() {
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Change");
    for (int i = 0; i < portfolio.num_stocks; i++) {
        printf("%-20s %-10.2f %-10.2f\n", portfolio.stocks[i].name, portfolio.stocks[i].price, portfolio.stocks[i].change);
    }
}

void update_portfolio() {
    for (int i = 0; i < portfolio.num_stocks; i++) {
        double change = (rand() % 21) - 10;
        portfolio.stocks[i].price += portfolio.stocks[i].price * change / 100;
    }
}

int main() {
    srand(time(NULL));
    load_portfolio();
    print_portfolio();
    update_portfolio();
    print_portfolio();
    return 0;
}
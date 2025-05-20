//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>

#define MAX_STOCKS 10
#define MAX_DAYS 100

typedef struct {
    char name[50];
    int price;
} Stock;

void read_stocks(Stock stocks[MAX_STOCKS]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d\n", stocks[count].name, &stocks[count].price)!= EOF) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[MAX_STOCKS]) {
    printf("Stock Name\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price!= 0) {
            printf("%s\t%d\n", stocks[i].name, stocks[i].price);
        }
    }
}

void update_stocks(Stock stocks[MAX_STOCKS], int num_days) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price!= 0) {
            stocks[i].price += (rand() % 10) - 5;
            if (stocks[i].price < 0) {
                stocks[i].price = 0;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    read_stocks(stocks);

    int num_days = 0;
    while (num_days < MAX_DAYS) {
        printf("Day %d:\n", num_days + 1);
        print_stocks(stocks);
        update_stocks(stocks, 1);
        num_days++;
    }

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char name[50];
    float current_price;
    float buy_price;
    float change_percent;
} Stock;

void print_header() {
    printf("%-20s %-10s %-10s %-10s\n", "Stock Name", "Current Price", "Buy Price", "Change %");
}

void print_stock(Stock stock) {
    printf("%-20s $%-9.2f $%-9.2f %5.2f%%\n", stock.name, stock.current_price, stock.buy_price, stock.change_percent);
}

void update_stocks(Stock stocks[]) {
    float total_value = 0;

    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("\nEnter name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter current price of %s: $", stocks[i].name);
        scanf("%f", &stocks[i].current_price);

        printf("Enter buy price of %s: $", stocks[i].name);
        scanf("%f", &stocks[i].buy_price);

        stocks[i].change_percent = ((stocks[i].current_price - stocks[i].buy_price) / stocks[i].buy_price) * 100;
        total_value += stocks[i].current_price * stocks[i].change_percent / 100;
    }

    printf("\nTotal portfolio value: $%.2f\n", total_value);
}

int main() {
    Stock stocks[MAX_STOCKS];

    print_header();
    update_stocks(stocks);

    for (int i = 0; i < MAX_STOCKS; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
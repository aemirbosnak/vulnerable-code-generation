//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double current_price;
    double previous_price;
    int is_updated;
} Stock;

void update_stock_prices(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].is_updated = 0;
    }

    printf("Enter updated stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s %lf", stocks[i].name, &stocks[i].current_price);
        stocks[i].is_updated = 1;
    }
}

void print_stock_changes(Stock stocks[], int num_stocks) {
    printf("Stock price changes:\n");
    for (int i = 0; i < num_stocks; i++) {
        if (stocks[i].is_updated) {
            printf("%s: %.2f -> %.2f\n", stocks[i].name, stocks[i].previous_price, stocks[i].current_price);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    printf("Enter stock names:\n");
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s", stocks[i].name);
    }

    printf("Enter initial stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s %lf", stocks[i].name, &stocks[i].previous_price);
    }

    while (1) {
        update_stock_prices(stocks, num_stocks);
        print_stock_changes(stocks, num_stocks);

        printf("\nDo you want to update stock prices again? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    return 0;
}
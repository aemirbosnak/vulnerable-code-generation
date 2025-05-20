//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    double price;
    int day;
} Stock;

void init_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price = rand() % 1000;
        stocks[i].day = 0;
    }
}

void print_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void update_prices(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price += rand() % 50 - 25;
    }
}

int main() {
    srand(time(NULL));

    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    printf("Enter the names of the stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s", stocks[i].name);
    }

    init_stocks(stocks, num_stocks);

    int days = 0;
    while (days < MAX_DAYS) {
        printf("\nDay %d:\n", days + 1);
        print_stocks(stocks, num_stocks);
        update_prices(stocks, num_stocks);
        days++;

        if (days % 7 == 0) {
            printf("\nWeekly summary:\n");
            for (int i = 0; i < num_stocks; i++) {
                printf("%s: $%.2f (%+.2f%%)\n", stocks[i].name, stocks[i].price, (stocks[i].price - stocks[i].price / 7) * 100);
            }
        }

        if (days % 30 == 0) {
            printf("\nMonthly summary:\n");
            for (int i = 0; i < num_stocks; i++) {
                printf("%s: $%.2f (%+.2f%%)\n", stocks[i].name, stocks[i].price, (stocks[i].price - stocks[i].price / 30) * 100);
            }
        }
    }

    return 0;
}
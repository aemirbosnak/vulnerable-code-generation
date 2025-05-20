//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
} Stock;

void print_stock(Stock *s) {
    printf("%-20s %-10s $%.2f %10d\n", s->name, s->symbol, s->price, s->volume);
}

int main() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    Stock *stocks = malloc(num_stocks * sizeof(Stock));

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: $");
        scanf("%lf", &stocks[i].price);
        printf("Volume: ");
        scanf("%d", &stocks[i].volume);
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");
        for (int i = 0; i < num_stocks; i++) {
            print_stock(&stocks[i]);
        }
        printf("\nPress any key to update...\n");
        getchar();
    }

    free(stocks);
    return 0;
}
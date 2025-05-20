//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SYMBOLS 100
#define MAX_HISTORY 1000
#define MAX_NAME 20

typedef struct {
    char symbol[MAX_NAME];
    double price;
    int history_size;
    double history[MAX_HISTORY];
    double avg_price;
} Stock;

void init_stock(Stock* s, char* name) {
    strcpy(s->symbol, name);
    s->price = 0.0;
    s->history_size = 0;
    s->avg_price = 0.0;
}

void add_history(Stock* s, double price) {
    if (s->history_size >= MAX_HISTORY) {
        s->history_size = MAX_HISTORY;
    }
    s->history[s->history_size++] = price;
    s->avg_price = 0.0;
    for (int i = 0; i < s->history_size; i++) {
        s->avg_price += s->history[i];
    }
    s->avg_price /= s->history_size;
}

void print_stock(Stock* s) {
    printf("Symbol: %s\n", s->symbol);
    printf("Price: $%.2f\n", s->price);
    printf("Average Price: $%.2f\n", s->avg_price);
}

int main() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    Stock stocks[num_stocks];
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i+1);
        char symbol[MAX_NAME];
        scanf("%s", symbol);
        init_stock(&stocks[i], symbol);
    }

    while (1) {
        printf("Enter the symbol of the stock to update: ");
        char symbol[MAX_NAME];
        scanf("%s", symbol);

        int index = -1;
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(symbol, stocks[i].symbol) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Invalid stock symbol.\n");
            continue;
        }

        printf("Enter the new price for %s: ", stocks[index].symbol);
        double price;
        scanf("%lf", &price);

        add_history(&stocks[index], price);
        stocks[index].price = price;

        print_stock(&stocks[index]);
    }

    return 0;
}
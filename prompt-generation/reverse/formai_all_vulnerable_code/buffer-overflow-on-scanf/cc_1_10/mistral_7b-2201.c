//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char symbol[5];
    double price;
    time_t last_updated;
} Stock;

void print_header() {
    printf("%-5s %-12s %-15s\n", "Symbol", "Price", "Last Updated");
}

void print_stock(Stock stock) {
    char time_string[20];
    struct tm *timeinfo;
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&stock.last_updated));

    printf("%-5s %-12.2f %-15s\n", stock.symbol, stock.price, time_string);
}

void update_stock_price(Stock *stock, double new_price) {
    stock->price = new_price;
    time(&(stock->last_updated));
}

bool is_valid_symbol(char *symbol) {
    int i;
    for (i = 0; i < 5 && isalnum(symbol[i]); i++) {}
    return i == 5;
}

int main() {
    int num_stocks = 3;
    Stock stocks[num_stocks];

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock symbol %d: ", i + 1);
        char symbol[5];
        scanf("%s", symbol);
        if (!is_valid_symbol(symbol)) {
            printf("Invalid symbol. Try again.\n");
            i--;
            continue;
        }
        strcpy(stocks[i].symbol, symbol);
        update_stock_price(&stocks[i], 50.00);
    }

    print_header();
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    double new_price;
    char symbol[5];

    while (true) {
        printf("\nEnter stock symbol to update price (or type 'quit' to exit): ");
        scanf("%s", symbol);

        if (strcmp(symbol, "quit") == 0) {
            break;
        }

        if (!is_valid_symbol(symbol)) {
            printf("Invalid symbol. Try again.\n");
            continue;
        }

        int index = -1;
        for (int i = 0; i < num_stocks && index == -1; i++) {
            if (strcmp(stocks[i].symbol, symbol) == 0) {
                index = i;
            }
        }

        if (index == -1) {
            printf("Stock not found.\n");
            continue;
        }

        printf("Enter new price: ");
        scanf("%lf", &new_price);

        update_stock_price(&stocks[index], new_price);
        print_stock(stocks[index]);
        printf("\n");
    }

    return 0;
}
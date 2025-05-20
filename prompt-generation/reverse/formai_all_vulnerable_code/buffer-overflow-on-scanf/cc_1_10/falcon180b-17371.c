//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    time_t date;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void print_stock(Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n", stock->price);
    printf("Date: %s\n", ctime(&stock->date));
}

void add_stock(Stock *stock) {
    stocks[num_stocks] = *stock;
    num_stocks++;
}

int main() {
    char input[1024];
    Stock new_stock;
    int choice;

    num_stocks = 0;

    while (1) {
        printf("Enter a command:\n");
        printf("1. Add a stock\n");
        printf("2. Print all stocks\n");
        printf("3. Exit\n");

        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
        case 1:
            printf("Enter the name of the stock:\n");
            fgets(new_stock.name, sizeof(new_stock.name), stdin);
            printf("Enter the symbol of the stock:\n");
            fgets(new_stock.symbol, sizeof(new_stock.symbol), stdin);
            printf("Enter the price of the stock:\n");
            scanf("%lf", &new_stock.price);
            printf("Enter the date of the stock (YYYY-MM-DD):\n");
            fgets(input, sizeof(input), stdin);
            strptime(input, "%Y-%m-%d", &new_stock.date);
            add_stock(&new_stock);
            break;
        case 2:
            for (int i = 0; i < num_stocks; i++) {
                print_stock(&stocks[i]);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid command.\n");
        }
    }

    return 0;
}
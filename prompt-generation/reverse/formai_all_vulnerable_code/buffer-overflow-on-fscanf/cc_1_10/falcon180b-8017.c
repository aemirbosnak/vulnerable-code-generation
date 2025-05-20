//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int volume;
} Stock;

void read_stocks(Stock* stocks, int count) {
    FILE* file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].volume) == 4 && i < count) {
        i++;
    }

    fclose(file);
}

void print_header() {
    printf("Stock Name\tSymbol\tPrice\tVolume\n");
}

void print_stocks(Stock* stocks, int count) {
    print_header();
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

void update_stocks(Stock* stocks, int count) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    if (tm->tm_hour >= 9 && tm->tm_hour < 16) {
        for (int i = 0; i < count; i++) {
            stocks[i].price += (rand() % 100) / 100.0;
            stocks[i].volume += rand() % 1000;
        }
    }
}

int main() {
    Stock stocks[MAX_COMPANIES];
    int count = 0;

    read_stocks(stocks, MAX_COMPANIES);
    print_stocks(stocks, count);

    while (1) {
        update_stocks(stocks, count);
        print_stocks(stocks, count);

        time_t now = time(NULL);
        struct tm* tm = localtime(&now);

        if (tm->tm_hour == 16) {
            break;
        }

        sleep(60);
    }

    return 0;
}
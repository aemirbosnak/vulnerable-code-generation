//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 10
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    float current_price;
    float change_percentage;
} Stock;

void get_stock_prices(Stock stocks[MAX_COMPANIES]);
void print_stock_prices(Stock stocks[MAX_COMPANIES]);

int main() {
    Stock stocks[MAX_COMPANIES];

    get_stock_prices(stocks);
    print_stock_prices(stocks);

    return 0;
}

void get_stock_prices(Stock stocks[MAX_COMPANIES]) {
    FILE *file;
    char filename[50] = "stock_prices.txt";
    char line[100];
    int i = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %f %f", stocks[i].symbol, &stocks[i].current_price, &stocks[i].change_percentage);
        i++;
    }

    fclose(file);
}

void print_stock_prices(Stock stocks[MAX_COMPANIES]) {
    int i;
    float total_change = 0;

    printf("\nStock Prices:\n");
    printf("----------------------\n");

    for (i = 0; i < MAX_COMPANIES; i++) {
        printf("%-10s %6.2f %6.2f%%\n", stocks[i].symbol, stocks[i].current_price, stocks[i].change_percentage);
        total_change += stocks[i].current_price * stocks[i].change_percentage;
    }

    printf("\nTotal change in portfolio: $%.2f\n", total_change);
}
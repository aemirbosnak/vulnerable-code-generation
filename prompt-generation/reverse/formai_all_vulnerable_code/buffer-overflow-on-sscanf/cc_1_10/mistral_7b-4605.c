//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 10
#define MAX_LINE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Stock;

void read_file(const char *filename, Stock stocks[MAX_STOCKS]) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LEN];
    char name[MAX_NAME_LEN];
    float price;
    int i = 0;

    if (!file) {
        puts("Could not open file.");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%s %f", name, &price) != 2)
            continue;

        strcpy(stocks[i].name, name);
        stocks[i].price = price;
        i++;
    }

    fclose(file);
}

void calculate_portfolio_value(const Stock stocks[MAX_STOCKS], int num_stocks, float current_price) {
    float portfolio_value = 0.0;
    int i;

    for (i = 0; i < num_stocks; i++)
        portfolio_value += stocks[i].quantity * stocks[i].price * current_price;

    printf("Portfolio value: %.2f\n", portfolio_value);
}

int main(void) {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    float current_price;
    const char *filename = "stocks.txt";

    read_file(filename, stocks);

    printf("Enter current stock price: ");
    scanf("%f", &current_price);

    num_stocks = (num_stocks > MAX_STOCKS) ? MAX_STOCKS : num_stocks;

    for (int i = 0; i < num_stocks; i++) {
        if (stocks[i].price > 0) {
            stocks[i].price *= current_price;
            printf("Stock %s: New price %.2f\n", stocks[i].name, stocks[i].price);
        }
    }

    calculate_portfolio_value(stocks, num_stocks, current_price);

    return EXIT_SUCCESS;
}
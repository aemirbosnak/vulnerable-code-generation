//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STOCKS 10
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10
#define MAX_PERCENT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float percent_change;
} Stock;

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Price: $%.2f\n", stock.price);
    printf("Percent Change: %.2f%%\n", stock.percent_change * 100);
}

int main() {
    Stock stocks[NUM_STOCKS];
    int i;

    // Initialize stocks
    for (i = 0; i < NUM_STOCKS; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0;
        stocks[i].percent_change = 0;
    }

    // Read stocks from file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }

    int num_stocks_read = 0;
    while (fscanf(fp, "%s $%f %.2f%%", stocks[num_stocks_read].name, &stocks[num_stocks_read].price, &stocks[num_stocks_read].percent_change) == 3) {
        num_stocks_read++;
        if (num_stocks_read >= NUM_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);

    // Print stocks
    printf("Post-Apocalyptic Stock Market Tracker\n");
    printf("-------------------------------------\n");
    for (i = 0; i < num_stocks_read; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
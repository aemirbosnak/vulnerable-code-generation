//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} stock_t;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    char line[MAX_NAME_LEN];
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in stocks
    while (fgets(line, MAX_NAME_LEN, fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: too many stocks in file.\n");
            exit(1);
        }
        strcpy(stocks[num_stocks].name, line);
        strcpy(stocks[num_stocks].symbol, "");
        strcpy(stocks[num_stocks].price, "");
        sscanf(line, "%s %s %s", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price);
        num_stocks++;
    }

    // Close file
    fclose(fp);

    // Sort stocks by name
    for (i = 0; i < num_stocks - 1; i++) {
        int j;
        for (j = i + 1; j < num_stocks; j++) {
            if (strcmp(stocks[i].name, stocks[j].name) > 0) {
                stock_t temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }

    // Print stocks
    printf("Name\tSymbol\tPrice\n");
    for (i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t%s\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char symbol[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

int main() {
    int num_symbols = 0;
    stock_t stocks[MAX_SYMBOLS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %s\n", stocks[num_symbols].symbol, stocks[num_symbols].name, stocks[num_symbols].price, stocks[num_symbols].volume)!= EOF) {
        num_symbols++;
    }

    fclose(fp);

    printf("Enter symbol to track: ");
    char symbol[MAX_NAME_LEN];
    fgets(symbol, MAX_NAME_LEN, stdin);
    symbol[strcspn(symbol, "\n")] = '\0';

    int i;
    for (i = 0; i < num_symbols; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Symbol: %s\n", stocks[i].symbol);
            printf("Name: %s\n", stocks[i].name);
            printf("Price: $%s\n", stocks[i].price);
            printf("Volume: %s\n\n", stocks[i].volume);
            break;
        }
    }

    if (i == num_symbols) {
        printf("Symbol not found.\n");
    }

    return 0;
}
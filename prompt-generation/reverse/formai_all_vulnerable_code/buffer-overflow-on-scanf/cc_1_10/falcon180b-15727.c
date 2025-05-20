//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, char* symbol, char* price, char* volume) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    strcpy(stocks[num_stocks].name, name);
    strcpy(stocks[num_stocks].symbol, symbol);
    strcpy(stocks[num_stocks].price, price);
    strcpy(stocks[num_stocks].volume, volume);

    num_stocks++;
}

void print_stocks() {
    printf("Name\tSymbol\tPrice\tVolume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%-10s\t%-10s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter command (add/print/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter symbol: ");
            scanf("%s", input);
            printf("Enter price: ");
            scanf("%s", input);
            printf("Enter volume: ");
            scanf("%s", input);

            add_stock(input, input, input, input);
        } else if (strcmp(input, "print") == 0) {
            print_stocks();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
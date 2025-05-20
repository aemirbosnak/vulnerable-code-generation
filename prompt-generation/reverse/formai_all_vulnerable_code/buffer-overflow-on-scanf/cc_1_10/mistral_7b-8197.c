//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[5];
    float price;
} Stock;

#define MAX_STOCKS 100

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char symbol[], float price) {
    if (num_stocks >= MAX_STOCKS) {
        fprintf(stderr, "Cannot add stock: table is full.\n");
        return;
    }
    strcpy(stocks[num_stocks].symbol, symbol);
    stocks[num_stocks].price = price;
    num_stocks++;
}

float get_average_price(char symbol[]) {
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            return stocks[i].price;
        }
    }
    fprintf(stderr, "No stock found with symbol %s.\n", symbol);
    exit(1);
}

int main() {
    char symbol[5];
    float price;
    char command[10];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            scanf("%s %f", symbol, &price);
            add_stock(symbol, price);
        } else if (strcmp(command, "AVG") == 0) {
            scanf("%s", symbol);
            printf("Average price of %s: %.2f\n", symbol, get_average_price(symbol));
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
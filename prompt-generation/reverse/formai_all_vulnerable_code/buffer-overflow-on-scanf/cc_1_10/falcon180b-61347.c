//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[10];
    double price;
    int quantity;
} Stock;

void init_stock(Stock* s) {
    strcpy(s->symbol, "");
    s->price = 0;
    s->quantity = 0;
}

void print_stock(Stock s) {
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
    printf("Quantity: %d\n", s.quantity);
    printf("\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    
    while (num_stocks < MAX_STOCKS) {
        printf("Enter a stock symbol (or leave blank to stop): ");
        char symbol[11];
        scanf("%s", symbol);
        
        if (!strcmp(symbol, "")) {
            break;
        }
        
        init_stock(&stocks[num_stocks]);
        strcpy(stocks[num_stocks].symbol, symbol);
        num_stocks++;
    }
    
    printf("Stock Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
    
    return 0;
}
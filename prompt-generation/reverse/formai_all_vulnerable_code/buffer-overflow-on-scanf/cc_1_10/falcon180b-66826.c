//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void read_stocks(Stock stocks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter stock %d name: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter stock %d symbol: ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter stock %d price: ", i + 1);
        scanf("%lf", &stocks[i].price);

        printf("Enter stock %d quantity: ", i + 1);
        scanf("%d", &stocks[i].quantity);
    }
}

void print_stocks(Stock stocks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Stock %d:\n", i + 1);
        printf("Name: %s\n", stocks[i].name);
        printf("Symbol: %s\n", stocks[i].symbol);
        printf("Price: $%.2f\n", stocks[i].price);
        printf("Quantity: %d\n\n", stocks[i].quantity);
    }
}

void sort_stocks(Stock stocks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n;

    printf("Enter number of stocks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_STOCKS) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    read_stocks(stocks, n);
    print_stocks(stocks, n);
    sort_stocks(stocks, n);
    print_stocks(stocks, n);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Stock;

void initStocks(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        stocks[i].price = 0;
        strcpy(stocks[i].name, "");
    }
}

void addStock(Stock stocks[], const char* name, float price) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (stocks[i].price == 0) {
            strcpy(stocks[i].name, name);
            stocks[i].price = price;
            break;
        }
    }
}

void printStocks(const Stock stocks[]) {
    printf("Name\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (stocks[i].price != 0) {
            printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    initStocks(stocks);

    addStock(stocks, "Apple", 147.95);
    addStock(stocks, "Microsoft", 218.50);
    addStock(stocks, "Google", 1145.50);

    printStocks(stocks);

    float newPrice = 235.45;
    char newName[MAX_NAME_LEN];

    printf("\nEnter the name of the stock to update its price: ");
    scanf("%s", newName);
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (strcmp(newName, stocks[i].name) == 0) {
            stocks[i].price = newPrice;
            break;
        }
    }

    printStocks(stocks);

    return 0;
}
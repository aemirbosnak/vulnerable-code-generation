//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define STOCK_NAME_LENGTH 20
#define PRICE_PRECISION 2

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
    time_t timestamp;
} Stock;

void print_stocks(Stock stocks[MAX_STOCKS]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int add_stock(Stock *stocks, char *name, float price) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price == 0.0) {
            strcpy(stocks[i].name, name);
            stocks[i].price = price;
            stocks[i].timestamp = time(NULL);
            return 1;
        }
    }
    return 0;
}

int main() {
    Stock stocks[MAX_STOCKS] = {{"Apple", 0.0, 0}, {"Microsoft", 0.0, 0}, {"Google", 0.0, 0}};

    char command[30], name[STOCK_NAME_LENGTH];
    float price;

    while (1) {
        printf("\nTuring Stock Market Tracker\n");
        printf("-----------------------------\n");
        printf("Enter command (add/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        printf("Enter stock name: ");
        scanf("%s", name);

        printf("Enter stock price: ");
        scanf("%f", &price);

        add_stock(stocks, name, price);

        printf("\nUpdated stock list:\n");
        print_stocks(stocks);
    }

    return 0;
}
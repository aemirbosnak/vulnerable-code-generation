//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char name[20];
    float price;
    int quantity;
} Stock;

void add_stock(Stock *stocks, int num_stocks) {
    printf("Enter the name of the stock: ");
    scanf("%s", &stocks[num_stocks].name);
    printf("Enter the price of the stock: ");
    scanf("%f", &stocks[num_stocks].price);
    printf("Enter the quantity of the stock: ");
    scanf("%d", &stocks[num_stocks].quantity);
    num_stocks++;
}

void display_stocks(Stock stocks[], int num_stocks) {
    printf("\nName\tPrice\tQuantity\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\t%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void update_stock_price(Stock *stocks, int num_stocks, char name[], float new_price) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = new_price;
            printf("\nThe price of %s has been updated to %.2f\n", name, new_price);
            break;
        }
    }
}

void update_stock_quantity(Stock *stocks, int num_stocks, char name[], int new_quantity) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].quantity = new_quantity;
            printf("\nThe quantity of %s has been updated to %d\n", name, new_quantity);
            break;
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    add_stock(stocks, num_stocks);
    add_stock(stocks, num_stocks);
    add_stock(stocks, num_stocks);

    display_stocks(stocks, num_stocks);

    update_stock_price(stocks, num_stocks, "AAPL", 150.00);
    update_stock_quantity(stocks, num_stocks, "AAPL", 50);

    display_stocks(stocks, num_stocks);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME 20
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} stock;

void add_stock(stock *stocks, int *num_stocks) {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[*num_stocks].name);
    printf("Enter the current price of the stock: ");
    scanf("%f", &stocks[*num_stocks].price);
    (*num_stocks)++;
}

void display_stocks(stock *stocks, int num_stocks) {
    printf("\nCurrent Stock Prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void sort_stocks(stock *stocks, int num_stocks) {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[i].price > stocks[j].price) {
                stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    add_stock(stocks, &num_stocks);

    while (1) {
        system("clear");
        display_stocks(stocks, num_stocks);
        printf("\nEnter 'a' to add a stock,'s' to sort stocks, or 'q' to quit: ");
        char choice = tolower(getchar());

        if (choice == 'a') {
            add_stock(stocks, &num_stocks);
        } else if (choice =='s') {
            sort_stocks(stocks, num_stocks);
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct Stock {
    char name[MAX_NAME_LEN];
    float current_price;
    float purchase_price;
    float profit_loss;
};

void get_stock_info(struct Stock *stock) {
    printf("Enter stock name: ");
    scanf("%s", stock->name);
    stock->current_price = 0;
    printf("Enter current price: ");
    scanf("%f", &stock->current_price);
    printf("Enter purchase price: ");
    scanf("%f", &stock->purchase_price);
    stock->profit_loss = stock->current_price - stock->purchase_price;
}

void print_stock_info(struct Stock *stock) {
    printf("\n%-*s %-*s %10s %10s %10s", MAX_NAME_LEN, "Name", MAX_NAME_LEN, stock->name, MAX_PRICE_LEN, "Current Price", MAX_PRICE_LEN, "Profit/Loss");
    printf("\n%-*s %-*s $%10.2f $%10.2f $%10.2f", MAX_NAME_LEN, "Name", MAX_NAME_LEN, stock->name, MAX_PRICE_LEN, "Current Price", MAX_PRICE_LEN, stock->current_price, MAX_PRICE_LEN, "$" , stock->profit_loss);
}

int main() {
    struct Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        if (num_stocks > 0) {
            printf("\nDo you want to add another stock? (Y/N) ");
            char choice;
            scanf(" %c", &choice);
            choice = toupper(choice);
            if (choice != 'Y') {
                break;
            }
        }
        printf("\nAdding stock #%d\n", num_stocks + 1);
        get_stock_info(&stocks[num_stocks]);
        num_stocks++;
    }

    printf("\n\nStock Report\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock_info(&stocks[i]);
    }

    return 0;
}
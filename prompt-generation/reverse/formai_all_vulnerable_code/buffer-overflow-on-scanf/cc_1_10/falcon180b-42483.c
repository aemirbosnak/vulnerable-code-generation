//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10
#define MAX_DATE_LEN 20
#define MAX_TIME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char date[MAX_DATE_LEN];
    char time[MAX_TIME_LEN];
} stock_t;

typedef struct {
    stock_t stocks[MAX_STOCKS];
    int num_stocks;
} portfolio_t;

void init_portfolio(portfolio_t* p) {
    p->num_stocks = 0;
}

void add_stock(portfolio_t* p, stock_t s) {
    if (p->num_stocks >= MAX_STOCKS) {
        printf("Error: portfolio is full.\n");
        return;
    }
    p->stocks[p->num_stocks++] = s;
}

void print_stock(stock_t s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: %s\n", s.price);
    printf("Quantity: %s\n", s.quantity);
    printf("Date: %s\n", s.date);
    printf("Time: %s\n", s.time);
}

void print_portfolio(portfolio_t* p) {
    printf("Portfolio:\n");
    for (int i = 0; i < p->num_stocks; i++) {
        print_stock(p->stocks[i]);
    }
}

int main() {
    srand(time(NULL));
    portfolio_t portfolio;
    init_portfolio(&portfolio);

    int choice;
    while (true) {
        printf("1. Add stock\n");
        printf("2. Print portfolio\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            stock_t stock;
            printf("Enter name: ");
            scanf("%s", stock.name);
            printf("Enter symbol: ");
            scanf("%s", stock.symbol);
            printf("Enter price: ");
            scanf("%s", stock.price);
            printf("Enter quantity: ");
            scanf("%s", stock.quantity);
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", stock.date);
            printf("Enter time (HH:MM:SS): ");
            scanf("%s", stock.time);
            add_stock(&portfolio, stock);
            break;
        }
        case 2: {
            print_portfolio(&portfolio);
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            printf("Invalid choice.\n");
        }
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char symbol[10];
    double price;
    int quantity;
} transaction;

typedef struct {
    char name[10];
    int num_transactions;
    transaction transactions[MAX_TRANSACTIONS];
} portfolio;

portfolio* create_portfolio(char* name) {
    portfolio* p = (portfolio*)malloc(sizeof(portfolio));
    strcpy(p->name, name);
    p->num_transactions = 0;
    return p;
}

void add_transaction(portfolio* p, char* symbol, double price, int quantity) {
    transaction t;
    strcpy(t.symbol, symbol);
    t.price = price;
    t.quantity = quantity;
    if (p->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Portfolio is full.\n");
        return;
    }
    p->transactions[p->num_transactions++] = t;
}

void display_portfolio(portfolio* p) {
    printf("Portfolio: %s\n", p->name);
    printf("Number of transactions: %d\n", p->num_transactions);
    for (int i = 0; i < p->num_transactions; i++) {
        printf("Transaction %d:\n", i+1);
        printf("Symbol: %s\n", p->transactions[i].symbol);
        printf("Price: $%.2f\n", p->transactions[i].price);
        printf("Quantity: %d\n\n", p->transactions[i].quantity);
    }
}

void destroy_portfolio(portfolio* p) {
    free(p);
}

int main() {
    portfolio* p1 = create_portfolio("Portfolio 1");
    add_transaction(p1, "AAPL", 150.00, 100);
    add_transaction(p1, "GOOG", 1000.00, 50);
    display_portfolio(p1);

    portfolio* p2 = create_portfolio("Portfolio 2");
    add_transaction(p2, "MSFT", 200.00, 75);
    add_transaction(p2, "AMZN", 3000.00, 25);
    display_portfolio(p2);

    destroy_portfolio(p1);
    destroy_portfolio(p2);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
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
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void add_transaction(char* symbol, double price, int quantity) {
    strcpy(transactions[num_transactions].symbol, symbol);
    transactions[num_transactions].price = price;
    transactions[num_transactions].quantity = quantity;
    num_transactions++;
}

void display_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s %.2f %d\n", transactions[i].symbol, transactions[i].price, transactions[i].quantity);
    }
}

int main() {
    char symbol[10];
    double price;
    int quantity;

    printf("Enter stock symbol: ");
    scanf("%s", symbol);

    printf("Enter price: ");
    scanf("%lf", &price);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    add_transaction(symbol, price, quantity);
    display_transactions();

    return 0;
}
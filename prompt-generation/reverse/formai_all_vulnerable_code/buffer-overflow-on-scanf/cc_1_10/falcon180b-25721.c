//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char symbol[10];
    int quantity;
    double price;
    time_t timestamp;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;

void addTransaction(char* symbol, int quantity, double price) {
    strcpy(transactions[numTransactions].symbol, symbol);
    transactions[numTransactions].quantity = quantity;
    transactions[numTransactions].price = price;
    transactions[numTransactions].timestamp = time(NULL);
    numTransactions++;
}

void printTransactions() {
    printf("Transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%s %d $%.2f %s\n", ctime(&transactions[i].timestamp), transactions[i].quantity, transactions[i].price, transactions[i].symbol);
    }
}

int main() {
    char symbol[10];
    int quantity;
    double price;

    while (1) {
        printf("Enter stock symbol: ");
        scanf("%s", symbol);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price: $");
        scanf("%lf", &price);

        addTransaction(symbol, quantity, price);

        printf("Transaction added.\n");
    }

    return 0;
}
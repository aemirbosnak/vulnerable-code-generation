//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_SHARES_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_TRANSACTIONS 50

typedef struct _stock {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int shares;
    int transactions;
} Stock;

Stock stocks[MAX_TRANSACTIONS];
int num_stocks = 0;

int main() {
    int num_transactions;

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        int num_shares, price;

        printf("Transaction %d:\n", i+1);
        printf("Enter the name of the stock: ");
        fgets(stocks[i].name, MAX_NAME_LEN, stdin);
        stocks[i].name[strcspn(stocks[i].name, "\n")] = 0;

        printf("Enter the price of the stock: ");
        scanf("%d", &price);
        sprintf(stocks[i].price, "%d", price);

        printf("Enter the number of shares: ");
        scanf("%d", &num_shares);
        stocks[i].shares = num_shares;

        printf("Enter the transaction number: ");
        scanf("%d", &stocks[i].transactions);
    }

    for (int i = 0; i < num_transactions; i++) {
        int sum_shares = stocks[i].shares;
        int sum_price = atoi(stocks[i].price);

        printf("Stock name: %s\n", stocks[i].name);
        printf("Price: %s\n", stocks[i].price);
        printf("Shares: %d\n", stocks[i].shares);
        printf("Transactions: %d\n", stocks[i].transactions);
        printf("Total value: $%.2f\n", sum_shares * sum_price);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock #%d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        strcpy(stocks[i].symbol, toupper(stocks[i].name[0]));
        for (int j = 1; j < strlen(stocks[i].name); j++) {
            if (isalpha(stocks[i].name[j])) {
                stocks[i].symbol[j-1] = tolower(stocks[i].name[j]);
            } else {
                stocks[i].symbol[j-1] = '\0';
                break;
            }
        }
        printf("Symbol: %s\n", stocks[i].symbol);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    printf("\nStock Tracker\n");
    printf("===========\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %-10s %10.2f %10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}
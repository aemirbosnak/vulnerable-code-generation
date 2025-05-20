//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10
#define MAX_CHANGE_LENGTH 10
#define MAX_PERCENTAGE_CHANGE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char volume[MAX_VOLUME_LENGTH];
    char change[MAX_CHANGE_LENGTH];
    char percentageChange[MAX_PERCENTAGE_CHANGE_LENGTH];
} stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    stock stocks[MAX_STOCKS];
    int i;
    for (i = 0; i < numStocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%s", stocks[i].price);
        printf("Volume: ");
        scanf("%s", stocks[i].volume);
        printf("Change: ");
        scanf("%s", stocks[i].change);
        printf("Percentage Change: ");
        scanf("%s", stocks[i].percentageChange);
    }

    printf("\nStock Market Tracker\n");
    printf("==============================================================\n");
    printf("| Name          | Symbol        | Price          | Volume        | Change        | Percentage Change |\n");
    printf("==============================================================\n");

    for (i = 0; i < numStocks; i++) {
        printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change, stocks[i].percentageChange);
    }

    return 0;
}
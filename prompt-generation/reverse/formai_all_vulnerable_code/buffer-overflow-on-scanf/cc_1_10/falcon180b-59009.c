//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} stock_t;

void generate_random_stock_name(char* name) {
    const char* vowels = "aeiouAEIOU";
    const char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    name[0] = consonants[rand() % strlen(consonants)];
    name[1] = vowels[rand() % strlen(vowels)];
    strcat(name, " Corp");
}

int compare_stocks(const void* a, const void* b) {
    const stock_t* stockA = (const stock_t*)a;
    const stock_t* stockB = (const stock_t*)b;

    if (stockA->price > stockB->price)
        return -1;
    else if (stockA->price < stockB->price)
        return 1;
    else
        return 0;
}

int main() {
    srand(time(NULL));

    stock_t stocks[MAX_STOCKS];
    int numStocks = 0;

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        char name[MAX_NAME_LENGTH];
        generate_random_stock_name(name);

        printf("Enter the starting price for %s: ", name);
        scanf("%lf", &stocks[i].price);

        strcpy(stocks[i].name, name);
    }

    qsort(stocks, numStocks, sizeof(stock_t), compare_stocks);

    printf("\nStock Market Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s $%.2f\n", stocks[i].name, stocks[i].price);
    }

    return 0;
}
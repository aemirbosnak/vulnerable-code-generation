//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char symbol[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    float price;
    int volume;
} Stock;

int main() {
    int numSymbols = 0;
    Stock symbols[MAX_SYMBOLS];

    printf("Welcome to the Artistic Stock Market Tracker!\n");
    printf("Please enter the number of stocks you would like to track (up to %d):\n", MAX_SYMBOLS);
    scanf("%d", &numSymbols);

    for (int i = 0; i < numSymbols; i++) {
        printf("Enter the symbol for stock #%d:\n", i+1);
        scanf("%s", symbols[i].symbol);

        printf("Enter the name for stock #%d:\n", i+1);
        scanf("%s", symbols[i].name);
    }

    while (1) {
        system("clear");
        printf("Artistic Stock Market Tracker\n");

        for (int i = 0; i < numSymbols; i++) {
            printf("%-20s %-20s $%.2f %10d\n", symbols[i].symbol, symbols[i].name, symbols[i].price, symbols[i].volume);
        }

        printf("\nPress any key to update prices...");
        getchar();

        for (int i = 0; i < numSymbols; i++) {
            printf("Updating prices for %s...\n", symbols[i].name);
            symbols[i].price += rand() % 100 - 50;
            symbols[i].volume += rand() % 1000;
        }
    }

    return 0;
}
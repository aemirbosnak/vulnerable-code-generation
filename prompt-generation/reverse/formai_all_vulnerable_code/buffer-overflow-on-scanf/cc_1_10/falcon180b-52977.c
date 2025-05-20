//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int volume;
} Stock;

int main() {
    int numStocks;
    scanf("%d", &numStocks);

    Stock stocks[MAX_STOCKS];
    for (int i = 0; i < numStocks; i++) {
        scanf("%s", stocks[i].symbol);
        scanf("%s", stocks[i].name);
        scanf("%lf", &stocks[i].price);
        scanf("%d", &stocks[i].volume);
    }

    char input[MAX_SYMBOL_LENGTH];
    printf("Enter a stock symbol to track:\n");
    scanf("%s", input);

    int index = -1;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, input) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Stock not found.\n");
        return 1;
    }

    printf("Tracking %s...\n", stocks[index].name);

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");
        printf("=====================\n");
        printf("Symbol: %s\n", stocks[index].symbol);
        printf("Name: %s\n", stocks[index].name);
        printf("Price: $%.2lf\n", stocks[index].price);
        printf("Volume: %d\n", stocks[index].volume);

        char choice;
        printf("\nPress 'u' to update stock prices or 'q' to quit:\n");
        scanf(" %c", &choice);

        if (choice == 'u') {
            for (int i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    stocks[i].price = (double)rand() / RAND_MAX * 100;
                    stocks[i].volume += (int)rand() % 100;
                    break;
                }
            }
        } else if (choice == 'q') {
            break;
        }
    }

    return 0;
}
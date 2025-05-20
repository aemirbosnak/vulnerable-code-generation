//FormAI DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 50

typedef struct stock {
    char symbol[10];
    float price;
    float change;
    bool isIncreased;
    int volume;
} Stock;

Stock stocks[MAX_STOCKS] = {0};
int count = 0;

/**
 * Add a new stock to the system
 */
void addStock(char symbol[]) {
    printf("\nEnter price of the stock '%s' : ", symbol);
    float price;
    scanf("%f", &price);

    printf("Enter the volume of the stock '%s' : ", symbol);
    int volume;
    scanf("%d", &volume);

    stocks[count].price = price;
    stocks[count].volume = volume;
    stocks[count].isIncreased = true;
    strcpy(stocks[count].symbol, symbol);
    count++;
}

/**
 * Update the status of all the stocks
 */
void updateStatus() {
    for(int i=0; i<count; i++) {
        float change = ((float) rand() / RAND_MAX) * 10;
        bool isIncreased = rand() % 2 == 0 ? true : false;

        if(isIncreased) {
            stocks[i].price += change;
        }
        else {
            stocks[i].price -= change;
        }

        stocks[i].isIncreased = isIncreased;
        stocks[i].change = change;
    }
}

/**
 * Print the current stock prices and volume
 */
void displayStocks() {
    printf("\nSymbol\tPrice\tVolume\tChange\n");

    for(int i=0; i<count; i++) {
        printf("%s\t%.2f\t%d\t%.2f%s\n",
            stocks[i].symbol, stocks[i].price, stocks[i].volume,
            stocks[i].isIncreased ? stocks[i].change : -stocks[i].change,
            stocks[i].isIncreased ? " (up)" : " (down)");
    }
}

int main() {
    printf("Welcome to the stock market tracker.\n");

    addStock("AAPL");
    addStock("GOOGL");
    addStock("TSLA");

    char input[10];

    while(true) {
        printf("\nEnter 'u' to update prices or 'q' to quit: ");
        scanf("%s", &input);

        if(strcmp(input, "u") == 0) {
            updateStatus();
            displayStocks();
        }
        else {
            break;
        }
    }

    return 0;
}
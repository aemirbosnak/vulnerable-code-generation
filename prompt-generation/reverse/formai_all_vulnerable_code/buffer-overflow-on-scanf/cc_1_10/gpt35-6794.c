//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double change;
} stock;

void updateStocks(stock stocks[], int count) {
    int i;
    for(i = 0; i < count; i++) {
        double change = 0.0;
        if(rand() % 2 == 0) {
            change = (double) rand() / RAND_MAX;
        } else {
            change = -(double) rand() / RAND_MAX;
        }
        stocks[i].change = change;
        stocks[i].price += change;
    }
}

void printStocks(stock stocks[], int count) {
    int i;
    printf("| Stock | Price | Change |\n");
    for(i = 0; i < count; i++) {
        printf("| %s | %.2lf | %.2lf%% |\n", stocks[i].name, stocks[i].price, 100 * stocks[i].change);
    }
    printf("\n");
}

int main() {
    stock stocks[MAX_STOCKS];
    int count = 0;
    char input[MAX_NAME_LENGTH];
    printf("Welcome to the Stock Market Tracker\n");
    printf("Enter the name of a stock (q to quit): ");
    scanf("%s", input);
    while(strcmp(input, "q") && strcmp(input, "Q") && count < MAX_STOCKS) {
        strncpy(stocks[count].name, input, MAX_NAME_LENGTH);
        stocks[count].price = 100.0;
        stocks[count].change = 0.0;
        count++;
        printf("Enter the name of a stock (q to quit): ");
        scanf("%s", input);
    }
    printf("\n");
    while(1) {
        updateStocks(stocks, count);
        printStocks(stocks, count);
        printf("Press enter to update stocks (q to quit): ");
        fgets(input, MAX_NAME_LENGTH, stdin);
        if(strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0) {
            return 0;
        }
    }
    return 0;
}
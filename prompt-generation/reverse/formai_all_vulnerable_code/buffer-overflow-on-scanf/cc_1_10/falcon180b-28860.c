//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 10
#define NUM_DAYS 30

typedef struct {
    char name[20];
    double price;
} Stock;

void generateRandomStockPrices(Stock stocks[NUM_STOCKS]) {
    srand(time(NULL));

    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i].price = rand() % 100;
    }
}

void printStockPrices(Stock stocks[NUM_STOCKS]) {
    printf("Stock Prices:\n");

    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void main() {
    Stock stocks[NUM_STOCKS];
    char choice;

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        system("clear");

        printf("Please choose an option:\n");
        printf("1. View stock prices\n");
        printf("2. Buy a stock\n");
        printf("3. Sell a stock\n");
        printf("4. Quit\n");

        scanf("%c", &choice);

        switch (choice) {
            case '1':
                generateRandomStockPrices(stocks);
                printStockPrices(stocks);
                break;
            case '2':
                printf("Which stock would you like to buy?\n");

                for (int i = 0; i < NUM_STOCKS; i++) {
                    printf("%d. %s\n", i+1, stocks[i].name);
                }

                int stockChoice;
                scanf("%d", &stockChoice);

                stocks[stockChoice-1].price += 5;
                printf("You bought %s for $%.2f.\n", stocks[stockChoice-1].name, stocks[stockChoice-1].price);
                break;
            case '3':
                printf("Which stock would you like to sell?\n");

                for (int i = 0; i < NUM_STOCKS; i++) {
                    printf("%d. %s\n", i+1, stocks[i].name);
                }

                int sellChoice;
                scanf("%d", &sellChoice);

                stocks[sellChoice-1].price -= 5;
                printf("You sold %s for $%.2f.\n", stocks[sellChoice-1].name, stocks[sellChoice-1].price);
                break;
            case '4':
                printf("Thank you for using the Stock Market Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\nPress enter to continue...");
        getchar();
    }
}
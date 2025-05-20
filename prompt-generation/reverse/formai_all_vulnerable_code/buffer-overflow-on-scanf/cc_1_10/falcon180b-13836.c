//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[5];
    float price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock name (or type 'done' to finish): ");
        scanf("%s", stocks[num_stocks].name);

        if (strcmp(stocks[num_stocks].name, "done") == 0) {
            break;
        }

        printf("Enter stock symbol: ");
        scanf("%s", stocks[num_stocks].symbol);

        printf("Enter stock price: ");
        scanf("%f", &stocks[num_stocks].price);

        num_stocks++;
    }

    printf("\nStock Market Tracker\n");
    printf("---------------------\n");

    while (1) {
        system("clear");

        printf("\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%-50s %-5s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("\n");
        printf("Press enter to update prices...\n");
        getchar();

        for (int i = 0; i < num_stocks; i++) {
            stocks[i].price += (rand() % 10 - 5) / 100.0;
        }

        printf("\n");
        printf("Prices updated!\n");
        printf("\n");
        usleep(1000000); // Sleep for 1 second
    }

    return 0;
}
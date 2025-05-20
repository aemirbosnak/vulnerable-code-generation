//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_TICKER_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_TICKER_LENGTH];
    double price;
    int quantity;
} Stock;

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s\n", asctime(t));

    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while(num_stocks < MAX_STOCKS) {
        printf("Enter stock name (max %d characters): ", MAX_NAME_LENGTH-1);
        scanf("%s", stocks[num_stocks].name);

        printf("Enter stock ticker (max %d characters): ", MAX_TICKER_LENGTH-1);
        scanf("%s", stocks[num_stocks].ticker);

        printf("Enter stock price: ");
        scanf("%lf", &stocks[num_stocks].price);

        printf("Enter stock quantity: ");
        scanf("%d", &stocks[num_stocks].quantity);

        num_stocks++;
    }

    printf("\nStock Tracker\n");
    printf("==================\n");

    while(1) {
        system("clear");
        printf("\nCurrent date and time: %s\n", asctime(localtime(&now)));

        printf("\nStock Name\tTicker\tPrice\tQuantity\n");
        for(int i=0; i<num_stocks; i++) {
            printf("%-50s\t%-10s\t$%.2lf\t%d\n", stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].quantity);
        }

        printf("\nPress any key to update stock prices...\n");
        getchar();

        now = time(NULL);
        t = localtime(&now);

        for(int i=0; i<num_stocks; i++) {
            double new_price = stocks[i].price + (rand() % 10 - 5);
            if(new_price < 0) new_price = 0;
            stocks[i].price = new_price;
        }
    }

    return 0;
}
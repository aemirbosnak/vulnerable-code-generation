//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5
#define NUM_DAYS 30

typedef struct {
    char name[20];
    double price;
} Stock;

int main() {
    Stock stocks[NUM_STOCKS];
    char choice;
    int stock_index;
    int day;
    double total_price;
    time_t start_time, end_time;

    srand(time(NULL));
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].price = rand() % 100;
    }

    printf("Welcome to the Stock Market Tracker!\n\n");
    printf("Please select a stock:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%d. %s - $%.2f\n", i+1, stocks[i].name, stocks[i].price);
    }
    scanf("%c", &choice);
    stock_index = choice - '0' - 1;

    printf("\nYou have chosen %s.\n\n", stocks[stock_index].name);
    printf("Day 1:\n");

    for (day = 1; day <= NUM_DAYS; day++) {
        printf("Day %d:\n", day);
        for (int i = 0; i < NUM_STOCKS; i++) {
            if (i == stock_index) {
                stocks[i].price += rand() % 10 - 5;
            } else {
                stocks[i].price += rand() % 10 - 5;
            }
            printf("%s - $%.2f\n", stocks[i].name, stocks[i].price);
        }
        printf("\n");
    }

    total_price = stocks[stock_index].price;
    printf("\nThe total price of %s after %d days is $%.2f.\n", stocks[stock_index].name, NUM_DAYS, total_price);

    return 0;
}
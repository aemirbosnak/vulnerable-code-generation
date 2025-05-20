//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
// This program is a simple stock market tracker in C. It allows the user to input a list of stocks and their corresponding prices, and then tracks the prices over time.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    time_t last_updated;
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks;

void add_stock(char* name, float price) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Too many stocks!\n");
        return;
    }

    strcpy(stocks[num_stocks].name, name);
    stocks[num_stocks].price = price;
    stocks[num_stocks].last_updated = time(NULL);
    num_stocks++;
}

void update_stock_price(int index, float price) {
    if (index < 0 || index >= num_stocks) {
        printf("Error: Invalid stock index!\n");
        return;
    }

    stocks[index].price = price;
    stocks[index].last_updated = time(NULL);
}

void display_stocks() {
    printf("Name\tPrice\tLast Updated\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\t%s\n", stocks[i].name, stocks[i].price, ctime(&stocks[i].last_updated));
    }
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stocks\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[MAX_NAME_LEN];
                float price;

                printf("Enter stock name: ");
                scanf("%s", name);

                printf("Enter stock price: ");
                scanf("%f", &price);

                add_stock(name, price);
                break;
            }

        case 2:
            {
                int index;

                printf("Enter stock index: ");
                scanf("%d", &index);

                update_stock_price(index, 0.0);
                break;
            }

        case 3:
            display_stocks();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
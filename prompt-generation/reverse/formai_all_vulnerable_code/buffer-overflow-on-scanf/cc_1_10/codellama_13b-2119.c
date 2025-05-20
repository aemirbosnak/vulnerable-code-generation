//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks;
    char input[MAX_NAME_LEN];

    // Get the number of stocks from the user
    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    // Get the stock names and prices from the user
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name and price of stock %d: ", i + 1);
        scanf("%s %f", stocks[i].name, &stocks[i].price);
    }

    // Calculate the total value of all stocks
    float total_value = 0;
    for (int i = 0; i < num_stocks; i++) {
        total_value += stocks[i].price;
    }

    // Display the total value of all stocks
    printf("Total value of all stocks: $%.2f\n", total_value);

    // Get the name of a stock to check the price
    printf("Enter the name of a stock to check the price: ");
    scanf("%s", input);

    // Check if the input matches any of the stock names
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(input, stocks[i].name) == 0) {
            printf("Price of %s: $%.2f\n", input, stocks[i].price);
            break;
        }
    }

    return 0;
}
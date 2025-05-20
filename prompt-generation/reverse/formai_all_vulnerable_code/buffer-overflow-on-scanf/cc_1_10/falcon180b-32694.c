//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10
#define MAX_TOTAL_VALUE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char quantity[MAX_QUANTITY_LENGTH];
    char total_value[MAX_TOTAL_VALUE_LENGTH];
} stock;

int main() {

    int num_stocks = 0;
    stock stocks[MAX_STOCKS];

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the number of stocks you want to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    printf("Enter the name, price, quantity, and total value for each stock:\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("Stock %d:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Price: ");
        scanf("%s", stocks[i].price);
        printf("Quantity: ");
        scanf("%s", stocks[i].quantity);
        printf("Total Value: ");
        scanf("%s", stocks[i].total_value);
    }

    printf("\nStock Summary:\n");
    printf("----------------------------------------------------\n");
    printf("| Name        | Price      | Quantity | Total Value |\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %s          | %s       | %s      | %s         |\n", stocks[i].name, stocks[i].price, stocks[i].quantity, stocks[i].total_value);
    }

    printf("\n----------------------------------------------------\n");

    return 0;
}
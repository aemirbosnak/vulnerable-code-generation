//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_QUANTITY 100000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int quantity;
    double price;
} Stock;

int main() {
    int numStocks, i;
    char input[100];
    Stock stocks[MAX_STOCKS];

    printf("Welcome to the Stock Market Tracker 3000!\n");
    printf("Please enter the number of stocks you want to track: ");
    scanf("%d", &numStocks);

    for (i = 0; i < numStocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker 3000\n");
        printf("-------------------------\n");

        for (i = 0; i < numStocks; i++) {
            printf("%d. %s (%s) - Quantity: %d - Price: $%.2f\n", i+1, stocks[i].name, stocks[i].symbol, stocks[i].quantity, stocks[i].price);
        }

        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "buy") == 0) {
            printf("Enter stock symbol: ");
            scanf("%s", input);
            int index = -1;
            for (i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    index = i;
                    break;
                }
            }
            if (index!= -1) {
                printf("Enter quantity: ");
                scanf("%d", &stocks[index].quantity);
            } else {
                printf("Stock not found.\n");
            }
        } else if (strcmp(input, "sell") == 0) {
            printf("Enter stock symbol: ");
            scanf("%s", input);
            int index = -1;
            for (i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    index = i;
                    break;
                }
            }
            if (index!= -1) {
                printf("Enter quantity: ");
                scanf("%d", &stocks[index].quantity);
            } else {
                printf("Stock not found.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
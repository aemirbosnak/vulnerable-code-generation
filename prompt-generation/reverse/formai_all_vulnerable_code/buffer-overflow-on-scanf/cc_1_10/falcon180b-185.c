//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[10];
    double price;
} stock;

int main() {
    int num_stocks;
    stock stocks[MAX_STOCKS];
    char input[100];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d name: ", i+1);
        scanf("%s", stocks[i].name);
        strcpy(stocks[i].symbol, stocks[i].name);
        strcat(stocks[i].symbol, " Corp");
        printf("Enter stock %s symbol: ", stocks[i].name);
        scanf("%s", stocks[i].symbol);
        printf("Enter stock %s price: $", stocks[i].name);
        scanf("%lf", &stocks[i].price);
    }

    while(1) {
        system("clear");
        printf("Stock Market Tracker\n");
        printf("=====================\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%-20s %-10s $%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }
        printf("\n");
        printf("Enter command: ");
        scanf("%s", input);
        if (strcmp(input, "update") == 0) {
            printf("Enter stock symbol to update: ");
            scanf("%s", input);
            int index = -1;
            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    index = i;
                    break;
                }
            }
            if (index >= 0) {
                printf("Enter new stock %s name: ", stocks[index].name);
                scanf("%s", stocks[index].name);
                strcpy(stocks[index].symbol, stocks[index].name);
                strcat(stocks[index].symbol, " Corp");
                printf("Enter new stock %s symbol: ", stocks[index].name);
                scanf("%s", stocks[index].symbol);
                printf("Enter new stock %s price: $", stocks[index].name);
                scanf("%lf", &stocks[index].price);
            } else {
                printf("Stock not found.\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
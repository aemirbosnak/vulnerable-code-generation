//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 20
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void readStocks(Stock stocks[], int n) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= n) {
            printf("Maximum number of stocks reached.\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[i].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[i].symbol, token);

        token = strtok(NULL, ",");
        stocks[i].price = atof(token);

        token = strtok(NULL, ",");
        stocks[i].quantity = atoi(token);

        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n;

    printf("Enter the number of stocks (maximum %d): ", MAX_STOCKS);
    scanf("%d", &n);

    readStocks(stocks, n);
    printStocks(stocks, n);

    return 0;
}
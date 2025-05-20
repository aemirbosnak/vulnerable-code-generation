//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

void loadStocks(Stock stocks[], int *numStocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        *numStocks = 0;
        return;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(stocks[i].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[i].symbol, token);

        token = strtok(NULL, ",");
        stocks[i].price = atof(token);

        i++;
        if (i >= MAX_STOCKS) {
            break;
        }
    }

    fclose(fp);
    *numStocks = i;
}

void saveStocks(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < numStocks; i++) {
        fprintf(fp, "%s,%s,%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    fclose(fp);
}

void displayStocks(Stock stocks[], int numStocks) {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s\t%-10s\t%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    loadStocks(stocks, &numStocks);

    while (1) {
        system("clear");
        displayStocks(stocks, numStocks);

        char choice;
        printf("\nEnter your choice:\n");
        printf("1. Buy stock\n");
        printf("2. Sell stock\n");
        printf("3. View portfolio\n");
        printf("4. Save and exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            // Buy stock
            break;
        case '2':
            // Sell stock
            break;
        case '3':
            // View portfolio
            break;
        case '4':
            saveStocks(stocks, numStocks);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
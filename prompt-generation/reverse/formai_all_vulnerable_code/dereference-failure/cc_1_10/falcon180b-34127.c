//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void readStocks(Stock stocks[]) {
    FILE *file;
    char line[100];
    int count = 0;

    file = fopen("stocks.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        strcpy(stocks[count].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[count].symbol, token);

        token = strtok(NULL, ",");
        stocks[count].price = atof(token);

        count++;
    }

    fclose(file);
}

void printStocks(Stock stocks[]) {
    int count = 0;

    printf("Name\tSymbol\tPrice\n");

    for (count = 0; count < MAX_STOCKS; count++) {
        if (stocks[count].name[0]!= '\0') {
            printf("%-20s\t%-10s\t$%.2f\n", stocks[count].name, stocks[count].symbol, stocks[count].price);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);
    printStocks(stocks);

    return 0;
}
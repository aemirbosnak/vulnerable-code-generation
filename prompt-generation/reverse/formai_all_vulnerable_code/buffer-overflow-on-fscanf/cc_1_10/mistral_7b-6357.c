//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 50
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    float price;
} Stock;

void readStocksFromFile(Stock stocks[], const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_COMPANIES; i++) {
        if (fscanf(file, "%s %f", stocks[i].symbol, &stocks[i].price) != 2) {
            break;
        }
    }

    fclose(file);
}

void printStocks(const Stock stocks[], int numStocks) {
    printf("\n%-10s %-15s\n", "Symbol", "Price");

    for (int i = 0; i < numStocks; i++) {
        printf("%-10s $%.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_COMPANIES];
    const char *filename = "stocks.txt";

    readStocksFromFile(stocks, filename);
    printStocks(stocks, MAX_COMPANIES);

    for (int i = 0; i < MAX_COMPANIES; i++) {
        printf("\nEnter the symbol and new price for stock %d: ", i + 1);
        scanf("%s %f", stocks[i].symbol, &stocks[i].price);

        if (strlen(stocks[i].symbol) > MAX_SYMBOL_LENGTH) {
            printf("Error: symbol too long\n");
            i--;
            continue;
        }

        if (strchr(stocks[i].symbol, ' ') != NULL) {
            printf("Error: symbol cannot contain spaces\n");
            i--;
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (strcmp(stocks[i].symbol, stocks[j].symbol) == 0) {
                printf("Error: duplicate symbol\n");
                i--;
                continue;
            }
        }
    }

    FILE *file = fopen("stocks.txt", "w");

    for (int i = 0; i < MAX_COMPANIES; i++) {
        fprintf(file, "%s %f\n", stocks[i].symbol, stocks[i].price);
    }

    fclose(file);

    printf("\nStocks have been updated and saved to file.\n");

    return 0;
}
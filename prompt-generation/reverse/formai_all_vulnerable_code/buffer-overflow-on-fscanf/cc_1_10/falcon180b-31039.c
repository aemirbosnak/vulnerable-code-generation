//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} Stock;

void loadStocks(Stock* stocks) {
    FILE* fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error loading stocks\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %lf\n", stocks[count].name, &stocks[count].price)!= EOF) {
        count++;
    }

    fclose(fp);
}

void saveStocks(const Stock* stocks) {
    FILE* fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error saving stocks\n");
        exit(1);
    }

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            fprintf(fp, "%s %lf\n", stocks[i].name, stocks[i].price);
        }
    }

    fclose(fp);
}

void printStocks(const Stock* stocks) {
    printf("Stock Name\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s $%.2lf\n", stocks[i].name, stocks[i].price);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    loadStocks(stocks);

    while (1) {
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock Price\n");
        printf("4. Print Stocks\n");
        printf("5. Save and Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add stock
            break;
        case 2:
            // Remove stock
            break;
        case 3:
            // Update stock price
            break;
        case 4:
            printStocks(stocks);
            break;
        case 5:
            saveStocks(stocks);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
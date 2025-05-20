//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Stock;

void loadStocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %lf %d", stocks[count].name, &stocks[count].price, &stocks[count].quantity) == 3) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void saveStocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            fprintf(fp, "%s %lf %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
        }
    }

    fclose(fp);
}

void printStocks(Stock stocks[]) {
    printf("Name\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-50s $%.2lf %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    loadStocks(stocks);

    int choice;
    do {
        printf("\nStock Market Tracker\n");
        printf("1. Buy Stock\n");
        printf("2. Sell Stock\n");
        printf("3. View Portfolio\n");
        printf("4. Save and Exit\n");
        printf("5. Exit without Saving\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", stocks[0].name);
                printf("Enter stock price: $");
                scanf("%lf", &stocks[0].price);
                printf("Enter stock quantity: ");
                scanf("%d", &stocks[0].quantity);
                break;
            case 2:
                printf("Enter stock name: ");
                scanf("%s", stocks[0].name);
                break;
            case 3:
                printStocks(stocks);
                break;
            case 4:
                saveStocks(stocks);
                printf("Saved portfolio and exited.\n");
                break;
            case 5:
                printf("Exited without saving.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4 && choice!= 5);

    return 0;
}
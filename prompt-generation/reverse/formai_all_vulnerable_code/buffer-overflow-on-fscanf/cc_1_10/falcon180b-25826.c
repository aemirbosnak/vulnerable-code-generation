//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 20
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    double change;
    double percentage_change;
} Stock;

void load_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %lf %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].percentage_change) == 5 && i < num_stocks) {
        i++;
    }

    fclose(fp);
}

void save_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "w");

    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    for (int i = 0; i < num_stocks; i++) {
        fprintf(fp, "%s %s %lf %lf %lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percentage_change);
    }

    fclose(fp);
}

void update_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price += stocks[i].change;
        stocks[i].percentage_change = (stocks[i].price - stocks[i].change) / stocks[i].change * 100;
    }
}

void display_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tSymbol\tPrice\tChange\t% Change\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s $%.2f $%.2f %.2f%%\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percentage_change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    load_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    while (1) {
        display_stocks(stocks, num_stocks);

        char choice;
        printf("Enter your choice:\n1. Update prices\n2. Save changes\n3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                update_stocks(stocks, num_stocks);
                break;
            case '2':
                save_stocks(stocks, num_stocks);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LENGTH 20

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    float current_price;
    float previous_price;
    float change;
    float percentage_change;
} Stock;

Stock stocks[MAX_COMPANIES];

void update_stock_prices() {
    int i;
    for (i = 0; i < MAX_COMPANIES; i++) {
        printf("Enter the name of the company (%d): ", i + 1);
        scanf("%s", stocks[i].name);
        printf("Enter the current price of %s: ", stocks[i].name);
        scanf("%f", &stocks[i].current_price);
        printf("Enter the previous price of %s: ", stocks[i].name);
        scanf("%f", &stocks[i].previous_price);
    }
}

void calculate_changes() {
    int i;
    for (i = 0; i < MAX_COMPANIES; i++) {
        stocks[i].change = stocks[i].current_price - stocks[i].previous_price;
        if (stocks[i].previous_price == 0) {
            stocks[i].percentage_change = 0;
        } else {
            stocks[i].percentage_change = (stocks[i].change / stocks[i].previous_price) * 100;
        }
    }
}

void print_stock_changes() {
    int i;
    printf("\nCompany Name\tCurrent Price\tPrevious Price\tChange\tPercentage Change\n");
    for (i = 0; i < MAX_COMPANIES; i++) {
        printf("%-20s\t%.2f\t%.2f\t%.2f\t%.2f%%\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price, stocks[i].change, stocks[i].percentage_change);
    }
}

int main() {
    update_stock_prices();
    calculate_changes();
    print_stock_changes();
    return 0;
}
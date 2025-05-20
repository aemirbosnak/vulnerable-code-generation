//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock;

stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);
    printf("Enter stock symbol: ");
    scanf("%s", stocks[num_stocks].symbol);
    printf("Enter stock price: ");
    scanf("%s", stocks[num_stocks].price);
    printf("Enter stock volume: ");
    scanf("%s", stocks[num_stocks].volume);
    num_stocks++;
}

void display_stocks() {
    printf("Name\tSymbol\tPrice\tVolume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t%s\t%s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add stock\n2. Display stocks\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                display_stocks();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}
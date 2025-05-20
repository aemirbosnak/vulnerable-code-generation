//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    double price;
    int volume;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, char* symbol, double price, int volume) {
    strcpy(stocks[num_stocks].name, name);
    strcpy(stocks[num_stocks].symbol, symbol);
    stocks[num_stocks].price = price;
    stocks[num_stocks].volume = volume;
    num_stocks++;
}

void print_stocks() {
    printf("Name\tSymbol\tPrice\tVolume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%10.2f\t%10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add/print/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char name[MAX_NAME_LENGTH];
            char symbol[MAX_NAME_LENGTH];
            double price;
            int volume;
            printf("Enter stock name: ");
            scanf("%s", name);
            printf("Enter stock symbol: ");
            scanf("%s", symbol);
            printf("Enter stock price: ");
            scanf("%lf", &price);
            printf("Enter stock volume: ");
            scanf("%d", &volume);
            add_stock(name, symbol, price, volume);
        } else if (strcmp(input, "print") == 0) {
            print_stocks();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
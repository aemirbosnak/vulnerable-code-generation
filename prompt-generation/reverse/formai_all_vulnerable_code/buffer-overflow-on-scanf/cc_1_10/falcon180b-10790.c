//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_STOCK_SYMBOL_LENGTH 10
#define MAX_STOCK_PRICE_LENGTH 20

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    char price[MAX_STOCK_PRICE_LENGTH];
} stock_t;

int main() {
    int num_companies;
    stock_t companies[MAX_COMPANIES];
    char input_buffer[512];
    char *token;
    int i;

    printf("Enter the number of companies to track: ");
    scanf("%d", &num_companies);

    printf("Enter the company names, symbols, and prices:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    token = strtok(input_buffer, "\n");
    for (i = 0; i < num_companies; i++) {
        if (token == NULL) {
            printf("Error: not enough input\n");
            exit(1);
        }
        strcpy(companies[i].name, token);
        token = strtok(NULL, " ");
        strcpy(companies[i].symbol, token);
        token = strtok(NULL, " ");
        strcpy(companies[i].price, token);
        token = strtok(NULL, "\n");
    }

    printf("Stock Name\tSymbol\tPrice\n");
    for (i = 0; i < num_companies; i++) {
        printf("%-20s\t%-10s\t%s\n", companies[i].name, companies[i].symbol, companies[i].price);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
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
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];
    char delimiter = ',';

    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price of stock %d: ", i+1);
        scanf("%s", stocks[i].price);

        printf("Enter the volume of stock %d: ", i+1);
        scanf("%s", stocks[i].volume);
    }

    printf("Enter the delimiter used in the input file: ");
    scanf("%c", &delimiter);

    FILE *fp = fopen("stock_data.csv", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(input, sizeof(input), fp)!= NULL) {
        char *token = strtok(input, ",");
        int stock_index = -1;

        while (token!= NULL) {
            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(token, stocks[i].symbol) == 0) {
                    stock_index = i;
                    break;
                }
            }

            if (stock_index!= -1) {
                if (strcmp(token, "Name") == 0) {
                    strcpy(stocks[stock_index].name, strtok(NULL, ","));
                } else if (strcmp(token, "Price") == 0) {
                    strcpy(stocks[stock_index].price, strtok(NULL, ","));
                } else if (strcmp(token, "Volume") == 0) {
                    strcpy(stocks[stock_index].volume, strtok(NULL, ","));
                }
            }

            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    printf("Stock Data:\n");
    printf("------------------------------------------------------------\n");
    printf("| Name     | Symbol   | Price    | Volume   |\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %s     | %s     | %s     | %s     |\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    return 0;
}
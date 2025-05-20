//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int volume;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void read_stocks_from_file(const char *filename) {
    FILE *fp;
    char line[1024];
    char *token;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    num_stocks = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].symbol, token);

        token = strtok(NULL, ",");
        stocks[num_stocks].price = atof(token);

        token = strtok(NULL, ",");
        stocks[num_stocks].volume = atoi(token);

        num_stocks++;
    }

    fclose(fp);
}

void print_stock_table() {
    printf("+---------------------------+\n");
    printf("| Name       | Symbol | Price | Volume |\n");
    printf("+---------------------------+\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %s        | %s    | %.2f | %d     |\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    printf("+---------------------------+\n");
}

int main() {
    char filename[1024];
    printf("Enter the name of the stock file: ");
    scanf("%s", filename);

    read_stocks_from_file(filename);
    print_stock_table();

    return 0;
}
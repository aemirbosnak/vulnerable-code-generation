//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define LINE_LENGTH 100

typedef struct {
    char symbol[5];
    float price;
    float prev_price;
} Stock;

void read_stocks_file(FILE *file, Stock stocks[MAX_STOCKS]) {
    int i = 0;
    char line[LINE_LENGTH];

    while (fgets(line, LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s%f%f", stocks[i].symbol, &stocks[i].price, &stocks[i].prev_price);
        i++;
    }
}

void display_stocks(Stock stocks[MAX_STOCKS]) {
    int i;
    printf("\nCURRENT PRICES:\n");

    for (i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

void calculate_percentage_change(Stock stocks[MAX_STOCKS]) {
    int i;
    float percentage[MAX_STOCKS];

    for (i = 0; i < MAX_STOCKS; i++) {
        percentage[i] = (stocks[i].price - stocks[i].prev_price) / stocks[i].prev_price * 100.0;
    }

    printf("\nPERCENTAGE CHANGE:\n");

    for (i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f%%\n", stocks[i].symbol, percentage[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    FILE *file;

    file = fopen("stocks.txt", "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    read_stocks_file(file, stocks);
    fclose(file);

    display_stocks(stocks);
    calculate_percentage_change(stocks);

    return 0;
}
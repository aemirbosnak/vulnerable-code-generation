//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define LINE_LENGTH 100

typedef struct {
    char symbol[10];
    double price;
} Stock;

void read_stock_prices(FILE *input, Stock prices[]) {
    int i = 0;
    char line[LINE_LENGTH];

    while (fgets(line, LINE_LENGTH, input) != NULL && i < MAX_LINES) {
        sscanf(line, "%s%lf", prices[i].symbol, &prices[i].price);
        i++;
    }
}

void write_stock_prices(FILE *output, Stock prices[]) {
    for (int i = 0; i < MAX_LINES; i++) {
        double percentage_change = prices[i + 1].price / prices[i].price - 1;
        fprintf(output, "%s,%.2f%%\n", prices[i].symbol, percentage_change * 100);
    }
}

int main() {
    FILE *input = fopen("stocks.txt", "r");
    FILE *output = fopen("percentage_changes.txt", "w");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        return 1;
    }

    Stock prices[MAX_LINES];

    read_stock_prices(input, prices);
    write_stock_prices(output, prices);

    for (int i = 0; i < MAX_LINES - 1; i++) {
        double percentage_change = prices[i + 1].price / prices[i].price - 1;
        printf("%s: %.2f%%\n", prices[i].symbol, percentage_change * 100);
    }

    fclose(input);
    fclose(output);

    return 0;
}
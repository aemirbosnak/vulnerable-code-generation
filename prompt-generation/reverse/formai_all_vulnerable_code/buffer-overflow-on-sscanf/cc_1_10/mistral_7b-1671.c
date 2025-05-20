//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define LINE_LENGTH 256

typedef struct {
    char name[50];
    float opening_price;
    float closing_price;
    float daily_gain_loss;
} Stock;

void read_stock_data(Stock stocks[MAX_STOCKS], char filename[]) {
    FILE *file;
    int i = 0;
    char line[LINE_LENGTH];

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s %f %f", stocks[i].name, &stocks[i].opening_price, &stocks[i].closing_price);
        i++;
    }

    fclose(file);
}

void print_top_5_gainers(Stock stocks[MAX_STOCKS]) {
    int i, j;
    Stock temp;
    float max_gain;

    for (i = 0; i < MAX_STOCKS - 1; i++) {
        for (j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[i].daily_gain_loss < stocks[j].daily_gain_loss) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }

        if (stocks[i].daily_gain_loss > max_gain) {
            max_gain = stocks[i].daily_gain_loss;
        }
    }

    for (i = 0; i < 5; i++) {
        if (stocks[i].daily_gain_loss == max_gain) {
            printf("%s: %.2f%%\n", stocks[i].name, stocks[i].daily_gain_loss * 100);
        }
    }
}

void print_top_5_losers(Stock stocks[MAX_STOCKS]) {
    int i, j;
    Stock temp;
    float max_loss;

    for (i = 0; i < MAX_STOCKS - 1; i++) {
        for (j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[i].daily_gain_loss > stocks[j].daily_gain_loss) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }

        if (stocks[i].daily_gain_loss < max_loss) {
            max_loss = stocks[i].daily_gain_loss;
        }
    }

    for (i = 0; i < 5; i++) {
        if (stocks[i].daily_gain_loss == max_loss) {
            printf("%s: %.2f%%\n", stocks[i].name, stocks[i].daily_gain_loss * 100);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    char filename[] = "stock_data.txt";

    read_stock_data(stocks, filename);

    for (int i = 0; i < MAX_STOCKS; i++) {
        stocks[i].daily_gain_loss = ((stocks[i].closing_price - stocks[i].opening_price) / stocks[i].opening_price) * 100;
    }

    printf("Top 5 Gainers:\n");
    print_top_5_gainers(stocks);

    printf("\nTop 5 Losers:\n");
    print_top_5_losers(stocks);

    return 0;
}
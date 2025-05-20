//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME 20
#define MAX_SYMBOL 10

typedef struct {
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    float price;
    float change;
    float percent_change;
} Stock;

Stock stocks[MAX_STOCKS];

void load_stocks() {
    FILE* file = fopen("stocks.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %f %f %f\n", stocks[count].name, stocks[count].symbol, &stocks[count].price, &stocks[count].change, &stocks[count].percent_change) == 5) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void save_stocks() {
    FILE* file = fopen("stocks.txt", "w");

    if (file == NULL) {
        printf("Error: Unable to open stocks file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            fprintf(file, "%s %s %f %f %f\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
        }
    }

    fclose(file);
}

void update_stock_prices() {
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    if (current_time->tm_hour >= 9 && current_time->tm_hour <= 16) {
        for (int i = 0; i < MAX_STOCKS; i++) {
            if (stocks[i].name[0]!= '\0') {
                stocks[i].price += stocks[i].change;
                stocks[i].percent_change = ((stocks[i].price - stocks[i].change) / stocks[i].change) * 100;
            }
        }
    }
}

void display_stocks() {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s %-10s $%.2f $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
        }
    }
}

int main() {
    load_stocks();

    while (1) {
        update_stock_prices();
        display_stocks();
        sleep(60);
    }

    return 0;
}
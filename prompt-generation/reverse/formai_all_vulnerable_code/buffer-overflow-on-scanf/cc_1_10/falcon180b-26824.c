//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_PRICES 1000
#define MAX_DAYS 365

typedef struct {
    char name[20];
    float prices[MAX_PRICES];
    int days[MAX_DAYS];
} Stock;

void read_stock(Stock *stock) {
    printf("Enter stock name: ");
    scanf("%s", stock->name);
    printf("Enter number of prices: ");
    scanf("%d", &stock->prices[0]);
    for (int i = 1; i < stock->prices[0]; i++) {
        printf("Enter price %d: ", i);
        scanf("%f", &stock->prices[i]);
    }
    printf("Enter number of days: ");
    scanf("%d", &stock->days[0]);
    for (int i = 1; i < stock->days[0]; i++) {
        printf("Enter day %d: ", i);
        scanf("%d", &stock->days[i]);
    }
}

void print_stock(Stock *stock) {
    printf("Stock name: %s\n", stock->name);
    printf("Number of prices: %d\n", stock->prices[0]);
    for (int i = 0; i < stock->prices[0]; i++) {
        printf("Price %d: %.2f\n", i+1, stock->prices[i]);
    }
    printf("Number of days: %d\n", stock->days[0]);
    for (int i = 0; i < stock->days[0]; i++) {
        printf("Day %d: %d\n", i+1, stock->days[i]);
    }
}

void calculate_average(Stock *stock) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < stock->prices[0]; i++) {
        sum += stock->prices[i];
        count++;
    }
    stock->prices[0] = count;
    stock->prices[count] = sum / count;
}

void main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (or 'done' to finish):\n");
        scanf("%s", stocks[num_stocks].name);
        if (strcmp(stocks[num_stocks].name, "done") == 0) {
            break;
        }
        read_stock(&stocks[num_stocks]);
        num_stocks++;
    }

    printf("Stock information:\n");
    for (int i = 0; i < num_stocks; i++) {
        calculate_average(&stocks[i]);
        print_stock(&stocks[i]);
    }
}
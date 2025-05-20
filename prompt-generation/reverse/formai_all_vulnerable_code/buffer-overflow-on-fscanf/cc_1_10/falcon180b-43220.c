//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 10
#define NUM_DAYS 30

typedef struct {
    char name[20];
    double price;
} Stock;

void generateRandomStockPrice(Stock* stock) {
    srand(time(NULL));
    stock->price = rand() % 1000;
}

void printStock(Stock stock) {
    printf("%-20s $%.2f\n", stock.name, stock.price);
}

int main() {
    Stock stocks[NUM_STOCKS];
    char filename[50];

    for (int i = 0; i < NUM_STOCKS; i++) {
        sprintf(filename, "stock%d.txt", i + 1);
        FILE* file = fopen(filename, "r");

        if (file == NULL) {
            printf("Error: File not found.\n");
            exit(1);
        }

        fscanf(file, "%s $%lf", stocks[i].name, &stocks[i].price);
        fclose(file);
    }

    printf("Day 1:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printStock(stocks[i]);
    }

    for (int day = 1; day <= NUM_DAYS; day++) {
        for (int i = 0; i < NUM_STOCKS; i++) {
            stocks[i].price += rand() % 50 - 25;
        }

        printf("\nDay %d:\n", day);
        for (int i = 0; i < NUM_STOCKS; i++) {
            printStock(stocks[i]);
        }
    }

    return 0;
}
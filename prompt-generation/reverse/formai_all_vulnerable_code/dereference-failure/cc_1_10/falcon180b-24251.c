//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

struct stock {
    char symbol[10];
    char name[50];
    double price;
    int volume;
};

void read_stocks(struct stock stocks[], int size) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= size) {
            printf("Error: Too many stocks.\n");
            exit(1);
        }

        sscanf(line, "%s %s %lf %d", stocks[i].symbol, stocks[i].name, &stocks[i].price, &stocks[i].volume);
        i++;
    }

    fclose(fp);
}

void print_stocks(struct stock stocks[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%-10s %-20s $%.2f %d\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].volume);
    }
}

void sort_stocks(struct stock stocks[], int size, int (*compare)(const void *, const void *)) {
    qsort(stocks, size, sizeof(struct stock), compare);
}

int compare_price(const void *a, const void *b) {
    struct stock *stock1 = (struct stock *)a;
    struct stock *stock2 = (struct stock *)b;

    if (stock1->price > stock2->price)
        return 1;
    else if (stock1->price < stock2->price)
        return -1;
    else
        return 0;
}

int compare_volume(const void *a, const void *b) {
    struct stock *stock1 = (struct stock *)a;
    struct stock *stock2 = (struct stock *)b;

    if (stock1->volume > stock2->volume)
        return 1;
    else if (stock1->volume < stock2->volume)
        return -1;
    else
        return 0;
}

int main() {
    struct stock stocks[100];
    int size;

    printf("Enter the number of stocks: ");
    scanf("%d", &size);

    read_stocks(stocks, size);

    printf("\nInitial stocks:\n");
    print_stocks(stocks, size);

    sort_stocks(stocks, size, compare_price);

    printf("\nSorted by price:\n");
    print_stocks(stocks, size);

    sort_stocks(stocks, size, compare_volume);

    printf("\nSorted by volume:\n");
    print_stocks(stocks, size);

    return 0;
}
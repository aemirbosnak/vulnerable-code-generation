//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

void read_stocks(stock_t stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_stocks && fscanf(fp, "%s %s %s", stocks[i].name, stocks[i].price, stocks[i].volume) == 3) {
        i++;
    }

    fclose(fp);
}

void print_stocks(stock_t stocks[], int num_stocks) {
    printf("Name\tPrice\tVolume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t%s\n", stocks[i].name, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num_stocks);

    read_stocks(stocks, num_stocks);

    while (1) {
        system("clear");
        printf("Enter the name of the stock you want to search for: ");
        char search_name[MAX_NAME_LEN];
        scanf("%s", search_name);

        int found = 0;
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].name, search_name) == 0) {
                printf("Found stock: %s\n", stocks[i].name);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Stock not found.\n");
        }

        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}
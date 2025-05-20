//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 1000
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
};

int main() {
    FILE *fp;
    char filename[50] = "stocks.txt";
    char line[100];
    int num_stocks = 0;
    struct stock stocks[MAX_STOCKS];

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read stocks from file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Maximum number of stocks reached!\n");
            break;
        }
        sscanf(line, "%s %s %lf %d", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price, &stocks[num_stocks].quantity);
        num_stocks++;
    }

    // Sort stocks by price
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                struct stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }

    // Print sorted stocks
    printf("Sorted stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s) - $%.2lf - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    // Close file
    fclose(fp);

    return 0;
}
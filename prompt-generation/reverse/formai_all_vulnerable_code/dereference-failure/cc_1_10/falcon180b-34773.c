//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
};

int main() {
    FILE *fp;
    char line[MAX_STOCKS][MAX_PRICE_LEN];
    int i, j;
    char *token;
    time_t now;
    struct tm *tm;
    char date_time[80];

    fp = fopen("stock_prices.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    now = time(NULL);
    tm = localtime(&now);
    strftime(date_time, 80, "%Y-%m-%d %H:%M:%S", tm);

    printf("Stock Market Tracker - %s\n", date_time);

    for (i = 0; i < MAX_STOCKS && fgets(line[i], MAX_PRICE_LEN, fp)!= NULL; i++) {
        token = strtok(line[i], ";");
        strcpy(line[i], token);
        token = strtok(NULL, ";");
        strcpy(line[i], token);
        token = strtok(NULL, ";");
        strcpy(line[i], token);
    }

    for (j = 0; j < i; j++) {
        printf("Stock %d:\n", j+1);
        printf("Name: %s\n", line[j]);
        printf("Symbol: %s\n", strtok(line[j], " "));
        printf("Price: $%.2f\n\n", atof(strtok(NULL, " ")));
    }

    fclose(fp);

    return 0;
}
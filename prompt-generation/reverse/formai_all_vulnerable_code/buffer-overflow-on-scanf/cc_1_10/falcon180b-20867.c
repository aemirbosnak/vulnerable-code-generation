//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 20
#define MAX_PRICE_DIGITS 9
#define MAX_VOLUME_DIGITS 9
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    char date[MAX_DATE_LEN];
} Stock;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    char line[MAX_NAME_LEN];
    int count = 0;
    Stock stocks[MAX_STOCKS];
    time_t now;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_NAME_LEN, fp)!= NULL) {
        if (count >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            exit(1);
        }

        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        char *price_str = strtok(NULL, ",");
        char *volume_str = strtok(NULL, ",");
        char *date_str = strtok(NULL, ",");

        if (name == NULL || symbol == NULL || price_str == NULL || volume_str == NULL || date_str == NULL) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }

        strcpy(stocks[count].name, name);
        strcpy(stocks[count].symbol, symbol);
        stocks[count].price = atof(price_str);
        stocks[count].volume = atoi(volume_str);
        strcpy(stocks[count].date, date_str);

        count++;
    }

    fclose(fp);

    printf("Stock Market Tracker\n");
    printf("=====================\n");

    for (int i = 0; i < count; i++) {
        printf("%s (%s): $%.2f (%d shares) on %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].date);
    }

    time(&now);
    printf("Current date and time: %s\n", ctime(&now));

    return 0;
}
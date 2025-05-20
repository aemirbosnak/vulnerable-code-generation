//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    double price;
    int volume;
} stock;

stock stocks[100];

int main() {
    int i, j, n;
    char filename[50];
    FILE *fp;
    stock temp;

    printf("Enter the name of the file containing stock data: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    n = 0;

    while (fscanf(fp, "%s %lf %d", temp.name, &temp.price, &temp.volume)!= EOF) {
        strcpy(stocks[n].name, temp.name);
        stocks[n].price = temp.price;
        stocks[n].volume = temp.volume;
        n++;
    }

    fclose(fp);

    printf("\nStock Market Tracker\n");

    while (true) {
        system("clear");

        printf("\nEnter the name of the stock you want to track: ");
        scanf("%s", temp.name);

        for (i = 0; i < n; i++) {
            if (strcmp(stocks[i].name, temp.name) == 0) {
                printf("\nName: %s\nPrice: $%.2f\nVolume: %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
                break;
            }
        }

        if (i == n) {
            printf("\nStock not found.\n");
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}
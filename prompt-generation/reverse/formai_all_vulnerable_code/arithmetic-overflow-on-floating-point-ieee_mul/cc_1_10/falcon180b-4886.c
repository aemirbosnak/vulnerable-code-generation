//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    char symbol[10];
    float price;
    int volume;
} stock;

void main() {
    int choice, i, j, n;
    float total_price = 0.0;
    char filename[20];
    FILE *fp;
    stock market[100];

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the name of the file containing the stock data: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %f %d", &market[i].symbol, &market[i].price, &market[i].volume);
        total_price += market[i].price * market[i].volume;
    }

    fclose(fp);

    printf("Total value of all stocks: $%.2f\n", total_price);

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View all stocks\n");
        printf("2. View a specific stock\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    printf("%s: $%.2f (%d shares)\n", market[i].symbol, market[i].price, market[i].volume);
                }
                break;

            case 2:
                printf("Please enter the symbol of the stock you want to view: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if (fp == NULL) {
                    printf("Error: File not found.\n");
                    exit(1);
                }

                fscanf(fp, "%s %f %d", &market[0].symbol, &market[0].price, &market[0].volume);

                printf("%s: $%.2f (%d shares)\n", market[0].symbol, market[0].price, market[0].volume);

                fclose(fp);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
}
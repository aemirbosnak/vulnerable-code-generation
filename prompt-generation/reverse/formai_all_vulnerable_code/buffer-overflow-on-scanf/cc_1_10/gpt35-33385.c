//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char name[50];
    float price;
    float change;
} stock;

int main() {
    int n;
    stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks you want to track (max: %d): ", MAX_STOCKS);
    scanf("%d", &n);

    printf("Enter the name, price and change (%%) for each stock:\n");
    for (int i = 0; i < n; i++) {
        printf("Stock %d:\n", i+1);
        scanf("%s %f %f", stocks[i].name, &stocks[i].price, &stocks[i].change);
    }

    printf("\n\n***** Stock Market Tracker *****\n\n");

    while (1) {
        printf("\n\n+--------------------------------------+\n");
        printf("| %-35s |\n", "Stocks");
        printf("+--------------------------------------+\n");
        printf("| %-20s | %-10s |\n", "Name", "Price");
        printf("+----------------------+---------------+\n");

        for (int i = 0; i < n; i++) {
            stocks[i].price += (stocks[i].price * stocks[i].change / 100);
            printf("| %-20s | %-10.2f |\n", stocks[i].name, stocks[i].price);
        }

        printf("+----------------------+---------------+\n");

        printf("\nPress ENTER to refresh or type 'exit' to quit the program.");
        char input[10];
        fgets(input, 10, stdin);

        if (strstr(input, "exit")) {
            break;
        }
    }

    printf("\nThank you for using Stock Market Tracker!\n");

    return 0;
}
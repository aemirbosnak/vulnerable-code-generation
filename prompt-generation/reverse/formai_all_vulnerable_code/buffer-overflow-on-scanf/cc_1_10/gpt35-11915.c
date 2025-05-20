//FormAI DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[10];
    float price;
    char change[10];
} Stock;

void display_menu() {
    printf("\n");
    printf("=============\n");
    printf(" STOCK MARKET\n");
    printf("=============\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Quit\n");
    printf("\nEnter your choice: ");
}

int main() {
    int choice;
    Stock *stocks = NULL;
    int num_stocks = 0;

    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // add a new stock
                stocks = (Stock *)realloc(stocks, (num_stocks + 1) * sizeof(Stock));
                printf("\nEnter stock symbol: ");
                scanf("%s", stocks[num_stocks].symbol);
                printf("Enter stock price: ");
                scanf("%f", &stocks[num_stocks].price);
                printf("Enter change (+/-%%): ");
                scanf("%s", stocks[num_stocks].change);
                num_stocks++;
                break;
            case 2:
                // view all stocks
                printf("\n%-10s %-10s %-10s\n", "Symbol", "Price", "Change");
                printf("-------------------------------------------\n");
                for (int i = 0; i < num_stocks; i++) {
                    printf("%-10s %-10.2f %-10s\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
                }
                break;
            case 3:
                // quit program
                break;
            default:
                printf("\nInvalid Choice. Try again.\n");
        }

    } while (choice != 3);

    free(stocks);
    printf("\nGoodbye!\n");
    return 0;
}
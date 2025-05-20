//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_SYMBOLS 10

struct stock {
    char symbol[MAX_SYMBOLS];
    double price;
    int quantity;
};

void init_stock(struct stock *s) {
    strcpy(s->symbol, "");
    s->price = 0.0;
    s->quantity = 0;
}

int main() {
    int num_stocks;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num_stocks);

    struct stock stocks[MAX_STOCKS];

    for (int i = 0; i < num_stocks; i++) {
        init_stock(&stocks[i]);
        printf("Enter stock symbol for stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);
    }

    char choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Buy\n");
        printf("2. Sell\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter stock symbol: ");
                scanf("%s", stocks[0].symbol);
                printf("Enter quantity: ");
                scanf("%d", &stocks[0].quantity);
                printf("Enter price: ");
                scanf("%lf", &stocks[0].price);
                break;
            case '2':
                printf("Enter stock symbol: ");
                scanf("%s", stocks[0].symbol);
                printf("Enter quantity: ");
                scanf("%d", &stocks[0].quantity);
                printf("Enter price: ");
                scanf("%lf", &stocks[0].price);
                break;
            case '3':
                printf("Your balance is: $%.2f\n", stocks[0].price * stocks[0].quantity);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
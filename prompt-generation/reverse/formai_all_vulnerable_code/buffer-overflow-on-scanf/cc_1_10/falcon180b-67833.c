//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Stock;

void print_header(void) {
    printf("+----------------------+\n");
    printf("| %-20s | %-10s |\n", "Stock Name", "Price");
    printf("+----------------------+\n");
}

void print_stock(Stock stock) {
    printf("| %-20s | $%.2f |\n", stock.name, stock.price);
}

void print_footer(void) {
    printf("+----------------------+\n");
}

int main(void) {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];

    srand(time(NULL));

    while (num_stocks < MAX_STOCKS) {
        printf("Enter the name of a stock (or type 'done' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        stocks[num_stocks].name[0] = '\0';
        strncat(stocks[num_stocks].name, input, MAX_NAME_LENGTH - 1);

        printf("Enter the current price of %s:\n", stocks[num_stocks].name);
        scanf("%lf", &stocks[num_stocks].price);

        num_stocks++;
    }

    print_header();

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    print_footer();

    return 0;
}
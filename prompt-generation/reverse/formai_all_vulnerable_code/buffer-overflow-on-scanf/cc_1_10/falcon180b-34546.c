//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_DAYS 100

typedef struct {
    char name[30];
    float price;
    int day;
} stock;

void init_stock(stock *s) {
    s->price = 0;
    s->day = 0;
}

void print_stock(stock s) {
    printf("%s %.2f %d\n", s.name, s.price, s.day);
}

void update_stock(stock *s) {
    s->day++;
    s->price = (float)rand() / RAND_MAX * 100;
}

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks;
    char input[100];

    srand(time(NULL));

    printf("Welcome to the Stock Market Tracker!\n");
    printf("How many stocks would you like to track? ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);
        init_stock(&stocks[i]);
    }

    int day = 1;
    while (day <= MAX_DAYS) {
        system("clear");
        printf("Day %d\n", day);

        for (int i = 0; i < num_stocks; i++) {
            print_stock(stocks[i]);
            update_stock(&stocks[i]);
        }

        printf("\nEnter 'n' to continue or any other key to exit: ");
        scanf("%s", input);

        if (input[0]!= 'n') {
            break;
        }

        day++;
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float price;
} stock;

void generate_random_stock(stock *s) {
    srand(time(NULL));
    strcpy(s->name, "Random Stock ");
    strcpy(s->symbol, "RND");
    s->price = (float)rand() / RAND_MAX * 100;
}

void print_stock(stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
}

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Random Stock Market Tracker!\n");

    while (num_stocks < MAX_STOCKS) {
        stock new_stock;
        generate_random_stock(&new_stock);
        printf("New stock added: ");
        print_stock(new_stock);
        stocks[num_stocks++] = new_stock;

        char choice;
        printf("\nDo you want to add another stock? (y/n): ");
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    printf("\nYour portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
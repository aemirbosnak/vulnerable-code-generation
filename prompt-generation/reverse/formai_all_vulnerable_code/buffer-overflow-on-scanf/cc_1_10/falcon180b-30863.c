//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void initialize_stock(Stock *s, char *name, float price, int quantity) {
    strcpy(s->name, name);
    s->price = price;
    s->quantity = quantity;
}

void print_stock(Stock s) {
    printf("%-20s $%.2f %d\n", s.name, s.price, s.quantity);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock name (or type 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter stock price: ");
        float price;
        scanf("%f", &price);

        printf("Enter stock quantity: ");
        int quantity;
        scanf("%d", &quantity);

        initialize_stock(&stocks[num_stocks], name, price, quantity);
        num_stocks++;
    }

    printf("\nStock List:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}
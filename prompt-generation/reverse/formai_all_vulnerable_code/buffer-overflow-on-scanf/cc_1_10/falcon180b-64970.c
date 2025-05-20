//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_HISTORY 100

typedef struct {
    char name[20];
    float price;
    int history[MAX_HISTORY];
    int index;
} stock;

stock stocks[MAX_STOCKS];
int num_stocks;

void add_stock() {
    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);
    stocks[num_stocks].price = rand() % 100;
    stocks[num_stocks].index = 0;
    num_stocks++;
}

void remove_stock(int index) {
    printf("Removing stock %s\n", stocks[index].name);
    num_stocks--;
    for (int i = index; i < num_stocks; i++) {
        stocks[i] = stocks[i+1];
    }
}

void update_prices() {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price += rand() % 10 - 5;
        if (stocks[i].price < 0) {
            stocks[i].price = 0;
        }
        stocks[i].history[stocks[i].index] = stocks[i].price;
        stocks[i].index = (stocks[i].index + 1) % MAX_HISTORY;
    }
}

void print_stocks() {
    printf("\nCurrent stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f (%+d)\n", stocks[i].name, stocks[i].price, stocks[i].history[stocks[i].index]);
    }
}

int main() {
    srand(time(NULL));
    num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        add_stock();
    }

    int choice;
    do {
        printf("\nChoose an option:\n1. Add stock\n2. Remove stock\n3. Update prices\n4. Print stocks\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                printf("Enter stock index to remove: ");
                scanf("%d", &choice);
                remove_stock(choice);
                break;
            case 3:
                update_prices();
                break;
            case 4:
                print_stocks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}
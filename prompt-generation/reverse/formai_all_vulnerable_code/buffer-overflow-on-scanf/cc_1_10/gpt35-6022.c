//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[4];
    double price;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    Stock new_stock;
    printf("Enter symbol: ");
    scanf("%s", new_stock.symbol);
    printf("Enter price: ");
    scanf("%lf", &new_stock.price);

    if (num_stocks < MAX_STOCKS) {
        stocks[num_stocks++] = new_stock;
        printf("Stock added successfully!\n");
    } else {
        printf("Maximum number of stocks reached!\n");
    }
}

void remove_stock() {
    char symbol[4];
    printf("Enter symbol to remove: ");
    scanf("%s", symbol);

    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(symbol, stocks[i].symbol) == 0) {
            int j;
            for (j = i; j < num_stocks - 1; j++) {
                stocks[j] = stocks[j+1];
            }
            num_stocks--;
            printf("Stock removed successfully!\n");
            return;
        }
    }

    printf("Stock not found!\n");
}

void print_stocks() {
    int i;
    for (i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

void update_stock() {
    char symbol[4];
    printf("Enter symbol to update: ");
    scanf("%s", symbol);

    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(symbol, stocks[i].symbol) == 0) {
            printf("Enter new price: ");
            scanf("%lf", &stocks[i].price);
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Stock not found!\n");
}

int main() {
    printf("Welcome to the stock market tracker!\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Update stock\n");
        printf("4. Print stocks\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                remove_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                print_stocks();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
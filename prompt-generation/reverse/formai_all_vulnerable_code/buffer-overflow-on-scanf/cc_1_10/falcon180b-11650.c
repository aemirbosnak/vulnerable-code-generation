//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} stock;

stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);

    printf("Enter stock symbol: ");
    scanf("%s", stocks[num_stocks].symbol);

    stocks[num_stocks].price = 0.0;
    stocks[num_stocks].quantity = 0;

    num_stocks++;
    printf("Stock added successfully.\n");
}

void update_stock_price(int index) {
    printf("Enter new stock price: ");
    scanf("%lf", &stocks[index].price);
    printf("Price updated successfully.\n");
}

void update_stock_quantity(int index) {
    printf("Enter new stock quantity: ");
    scanf("%d", &stocks[index].quantity);
    printf("Quantity updated successfully.\n");
}

void delete_stock(int index) {
    if (index < 0 || index >= num_stocks) {
        printf("Error: Invalid stock index.\n");
        return;
    }

    num_stocks--;
    printf("Stock deleted successfully.\n");
}

void display_stocks() {
    if (num_stocks == 0) {
        printf("No stocks found.\n");
        return;
    }

    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t%.2lf\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    system("clear");

    int choice;
    do {
        printf("\n");
        printf("1. Add stock\n");
        printf("2. Update stock price\n");
        printf("3. Update stock quantity\n");
        printf("4. Delete stock\n");
        printf("5. Display stocks\n");
        printf("6. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                printf("Enter stock index: ");
                scanf("%d", &choice);
                update_stock_price(choice);
                break;
            case 3:
                printf("Enter stock index: ");
                scanf("%d", &choice);
                update_stock_quantity(choice);
                break;
            case 4:
                printf("Enter stock index: ");
                scanf("%d", &choice);
                delete_stock(choice);
                break;
            case 5:
                display_stocks();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 6);

    return 0;
}
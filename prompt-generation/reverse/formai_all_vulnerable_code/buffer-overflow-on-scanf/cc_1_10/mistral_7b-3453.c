//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char symbol[5];
    float price;
    int quantity;
} Stock;

#define MAX_STOCKS 100
#define MAX_SYMBOL_LENGTH 5
#define MAX_INPUT_LENGTH 100

Stock stocks[MAX_STOCKS];

void read_stock(Stock* stock) {
    char symbol[MAX_SYMBOL_LENGTH];
    float price;
    int quantity;

    printf("Enter stock symbol: ");
    scanf("%s", symbol);
    strcpy(stock->symbol, symbol);

    printf("Enter stock price: ");
    scanf("%f", &price);
    stock->price = price;

    printf("Enter stock quantity: ");
    scanf("%d", &quantity);
    stock->quantity = quantity;
}

void print_stock(Stock stock) {
    printf("%s\t%.2f\t%d\n", stock.symbol, stock.price, stock.quantity);
}

void add_stock(Stock* stock) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].quantity == 0) {
            stock->symbol[strcspn(stock->symbol, "\n")] = '\0';
            strcpy(&stocks[i], stock);
            printf("Stock added successfully.\n");
            return;
        }
    }

    printf("Stock list is full. Please remove some stocks before adding new one.\n");
}

void remove_stock(char symbol[MAX_SYMBOL_LENGTH]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            memset(&stocks[i], 0, sizeof(Stock));
            printf("Stock removed successfully.\n");
            return;
        }
    }

    printf("Stock not found.\n");
}

void update_price(char symbol[MAX_SYMBOL_LENGTH], float new_price) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = new_price;
            printf("Price updated successfully.\n");
            return;
        }
    }

    printf("Stock not found.\n");
}

void list_stocks() {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].quantity > 0) {
            print_stock(stocks[i]);
        }
    }
}

int main() {
    int choice;
    Stock stock;

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printf("\n1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock Price\n");
        printf("4. List Stocks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_stock(&stock);
                add_stock(&stock);
                break;
            case 2:
                printf("Enter stock symbol to remove: ");
                scanf("%s", stock.symbol);
                remove_stock(stock.symbol);
                break;
            case 3:
                printf("Enter stock symbol: ");
                scanf("%s", stock.symbol);
                printf("Enter new stock price: ");
                scanf("%f", &stock.price);
                update_price(stock.symbol, stock.price);
                break;
            case 4:
                list_stocks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
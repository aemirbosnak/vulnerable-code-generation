//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int volume;
} Stock;

typedef struct {
    Stock *stocks[MAX_STOCKS];
    int count;
} StockMarket;

void init_stock_market(StockMarket *market) {
    market->count = 0;
}

Stock *create_stock(const char *name, float price, int volume) {
    Stock *new_stock = (Stock *)malloc(sizeof(Stock));
    if (new_stock == NULL) {
        perror("Failed to allocate memory for stock");
        exit(EXIT_FAILURE);
    }
    strncpy(new_stock->name, name, NAME_LENGTH);
    new_stock->price = price;
    new_stock->volume = volume;
    return new_stock;
}

void add_stock(StockMarket *market, Stock *stock) {
    if (market->count < MAX_STOCKS) {
        market->stocks[market->count++] = stock;
        printf("Added stock: %s\n", stock->name);
    } else {
        printf("Stock market is full, cannot add more stocks.\n");
    }
}

void remove_stock(StockMarket *market, const char *name) {
    for (int i = 0; i < market->count; i++) {
        if (strncmp(market->stocks[i]->name, name, NAME_LENGTH) == 0) {
            free(market->stocks[i]);
            market->stocks[i] = market->stocks[market->count - 1];
            market->count--;
            printf("Removed stock: %s\n", name);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void view_stocks(const StockMarket *market) {
    if (market->count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    printf("Current Stocks:\n");
    for (int i = 0; i < market->count; i++) {
        printf("Name: %s, Price: %.2f, Volume: %d\n",
               market->stocks[i]->name,
               market->stocks[i]->price,
               market->stocks[i]->volume);
    }
}

float calculate_market_value(const StockMarket *market) {
    float total_value = 0;
    for (int i = 0; i < market->count; i++) {
        total_value += market->stocks[i]->price * market->stocks[i]->volume;
    }
    return total_value;
}

void free_stock_market(StockMarket *market) {
    for (int i = 0; i < market->count; i++) {
        free(market->stocks[i]);
    }
}

int main() {
    StockMarket market;
    init_stock_market(&market);

    int choice;
    char name[NAME_LENGTH];
    float price;
    int volume;

    while (1) {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. View Stocks\n");
        printf("4. Calculate Total Market Value\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock volume: ");
                scanf("%d", &volume);
                add_stock(&market, create_stock(name, price, volume));
                break;

            case 2:
                printf("Enter stock name to remove: ");
                scanf("%s", name);
                remove_stock(&market, name);
                break;

            case 3:
                view_stocks(&market);
                break;

            case 4:
                printf("Total Market Value: %.2f\n", calculate_market_value(&market));
                break;

            case 5:
                free_stock_market(&market);
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}
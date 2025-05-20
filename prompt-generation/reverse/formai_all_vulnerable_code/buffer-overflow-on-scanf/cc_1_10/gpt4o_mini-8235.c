//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define SYMBOL_LENGTH 10

typedef struct {
    char symbol[SYMBOL_LENGTH];
    float price;
    int quantity;
} Stock;

void display_stocks(Stock stocks[], int stock_count) {
    printf("\n===== Stock Market Tracker =====\n");
    printf("Symbol       Price       Quantity\n");
    printf("---------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%-10s  $%.2f       %d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
    printf("---------------------------------\n");
}

void update_stock_price(Stock *stock) {
    float change = (rand() % 20 - 10) / 100.0; // Random change: -10% to +10%
    stock->price += stock->price * change;
    if (stock->price < 0) {
        stock->price = 0; // Prevent negative price
    }
}

void add_stock(Stock stocks[], int *stock_count) {
    if (*stock_count >= MAX_STOCKS) {
        printf("Error: Cannot add more stocks, maximum limit reached!\n");
        return;
    }
    printf("Enter stock symbol: ");
    scanf("%s", stocks[*stock_count].symbol);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*stock_count].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[*stock_count].quantity);
    (*stock_count)++;
}

void delete_stock(Stock stocks[], int *stock_count) {
    char symbol[SYMBOL_LENGTH];
    printf("Enter stock symbol to delete: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < *stock_count; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i] = stocks[*stock_count - 1]; // Replace with the last stock
            (*stock_count)--;
            printf("Stock '%s' deleted successfully.\n", symbol);
            return;
        }
    }
    printf("Error: Stock with symbol '%s' not found!\n", symbol);
}

void save_stocks_to_file(Stock stocks[], int stock_count) {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to save stocks to file!\n");
        return;
    }
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f %d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
    fclose(file);
    printf("Stocks saved to 'stocks.txt'.\n");
}

void load_stocks_from_file(Stock stocks[], int *stock_count) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("No saved stocks found, starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %f %d", stocks[*stock_count].symbol, &stocks[*stock_count].price, &stocks[*stock_count].quantity) != EOF) {
        (*stock_count)++;
    }
    fclose(file);
    printf("Stocks loaded successfully! Total: %d\n", *stock_count);
}

int main() {
    srand(time(0));
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    int option;

    load_stocks_from_file(stocks, &stock_count);

    do {
        printf("\n1. Add Stock\n2. Delete Stock\n3. Display Stocks\n4. Update Prices\n5. Save to File\n6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_stock(stocks, &stock_count);
                break;
            case 2:
                delete_stock(stocks, &stock_count);
                break;
            case 3:
                display_stocks(stocks, stock_count);
                break;
            case 4:
                for (int i = 0; i < stock_count; i++) {
                    update_stock_price(&stocks[i]);
                }
                printf("Stock prices updated.\n");
                break;
            case 5:
                save_stocks_to_file(stocks, stock_count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Error: Invalid option. Please try again.\n");
        }
    } while (option != 6);

    return 0;
}
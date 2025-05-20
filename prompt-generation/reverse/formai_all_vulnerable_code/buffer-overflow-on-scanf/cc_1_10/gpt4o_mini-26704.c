//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void add_stock(Stock stocks[], int *stock_count);
void update_price(Stock stocks[], int stock_count);
void view_portfolio(Stock stocks[], int stock_count);
void print_menu();

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(stocks, &stock_count);
                break;
            case 2:
                update_price(stocks, stock_count);
                break;
            case 3:
                view_portfolio(stocks, stock_count);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void print_menu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Portfolio\n");
    printf("4. Exit\n");
}

void add_stock(Stock stocks[], int *stock_count) {
    if (*stock_count >= MAX_STOCKS) {
        printf("Stock limit reached! Cannot add more stocks.\n");
        return;
    }

    Stock new_stock;
    printf("Enter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter stock ticker: ");
    scanf("%s", new_stock.ticker);
    printf("Enter stock price: ");
    scanf("%f", &new_stock.price);
    printf("Enter quantity: ");
    scanf("%d", &new_stock.quantity);

    stocks[*stock_count] = new_stock;
    (*stock_count)++;
    printf("Stock added successfully!\n");
}

void update_price(Stock stocks[], int stock_count) {
    char ticker[MAX_NAME_LENGTH];
    printf("Enter the stock ticker to update price: ");
    scanf("%s", ticker);
    
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Current price of %s (%s): %.2f\n", stocks[i].name, stocks[i].ticker, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void view_portfolio(Stock stocks[], int stock_count) {
    if (stock_count == 0) {
        printf("No stocks in the portfolio.\n");
        return;
    }

    float total_value = 0.0;
    printf("\n--- Portfolio ---\n");
    for (int i = 0; i < stock_count; i++) {
        float value = stocks[i].price * stocks[i].quantity;
        total_value += value;
        printf("Stock: %s (%s) - Price: %.2f, Quantity: %d, Total Value: %.2f\n",
               stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].quantity, value);
    }
    printf("Total Portfolio Value: %.2f\n", total_value);
}
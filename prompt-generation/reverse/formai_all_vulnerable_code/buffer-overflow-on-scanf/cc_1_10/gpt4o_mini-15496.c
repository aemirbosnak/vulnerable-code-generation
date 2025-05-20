//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void print_menu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add a stock\n");
    printf("2. Update stock price\n");
    printf("3. Display all stocks\n");
    printf("4. Exit\n");
}

void add_stock(Stock stocks[], int *stock_count) {
    if (*stock_count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }
    
    Stock new_stock;
    printf("Enter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter stock price: ");
    scanf("%f", &new_stock.price);
    new_stock.change = 0.0;  // no change initially
    stocks[*stock_count] = new_stock;
    (*stock_count)++;
    printf("Stock added successfully!\n");
}

void update_stock_price(Stock stocks[], int stock_count) {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            float new_price;
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &new_price);
            stocks[i].change = ((new_price - stocks[i].price) / stocks[i].price) * 100; // calculate change
            stocks[i].price = new_price; // update price
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void display_all_stocks(Stock stocks[], int stock_count) {
    if (stock_count == 0) {
        printf("No stocks available!\n");
        return;
    }
    
    printf("\nCurrent Stocks:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s | %-8s |\n", "Stock Name", "Price", "Change (%)");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("| %-20s | $%-9.2f | %-8.2f |\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    int choice;

    while (1) {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(stocks, &stock_count);
                break;
            case 2:
                update_stock_price(stocks, stock_count);
                break;
            case 3:
                display_all_stocks(stocks, stock_count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
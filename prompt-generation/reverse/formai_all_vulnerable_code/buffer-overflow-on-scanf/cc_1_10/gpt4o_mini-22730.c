//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define STOCK_NAME_LENGTH 30

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void add_stock() {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }

    Stock new_stock;
    printf("Enter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter stock price: ");
    scanf("%f", &new_stock.price);

    stocks[stock_count++] = new_stock;
    printf("Stock added successfully!\n");
}

void update_stock() {
    char stock_name[STOCK_NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", stock_name);

    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void view_stocks() {
    if (stock_count == 0) {
        printf("No stocks to display!\n");
        return;
    }
    
    printf("Stock List:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s |\n", "Stock Name", "Stock Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("| %-20s | $%-9.2f |\n", stocks[i].name, stocks[i].price);
    }
    printf("--------------------------------------------------\n");
}

void display_menu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number between 1 and 4.\n");
            while (getchar() != '\n'); // Clear the buffer
            continue;
        }

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                update_stock();
                break;
            case 3:
                view_stocks();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}
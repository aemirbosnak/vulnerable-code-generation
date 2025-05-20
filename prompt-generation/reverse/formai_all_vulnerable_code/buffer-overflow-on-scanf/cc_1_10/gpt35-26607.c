//FormAI DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>

#define MAX_STOCKS 10
#define MAX_NAME 30

typedef struct {
    char name[MAX_NAME];
    double price;
} Stock;

void display_stock_tracker_menu();
void add_stock(Stock[], int*);
void remove_stock(Stock[], int*);
void display_stocks(Stock[], int);

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char option;
    do {
        display_stock_tracker_menu();
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                add_stock(stocks, &num_stocks);
                break;
            case 'r':
                remove_stock(stocks, &num_stocks);
                break;
            case 's':
                display_stocks(stocks, num_stocks);
                break;
            case 'q':
                printf("Exiting stock tracker program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 'q');

    return 0;
}

// Displays the stock tracker menu
void display_stock_tracker_menu() {
    printf("\nStock Tracker Menu\n");
    printf("--------------------------------------\n");
    printf("a - Add a stock\n");
    printf("r - Remove a stock\n");
    printf("s - Show all stocks\n");
    printf("q - Quit program\n");
    printf("--------------------------------------\n");
    printf("Enter an option: ");
}

// Adds a stock to the stock array
void add_stock(Stock stocks[], int *num_stocks) {
    if (*num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    printf("Enter the name of the stock: ");
    scanf("%s", stocks[*num_stocks].name);

    printf("Enter the price of the stock: ");
    scanf("%lf", &stocks[*num_stocks].price);

    printf("Stock added successfully.\n");
    (*num_stocks)++;
}

// Removes a stock from the stock array
void remove_stock(Stock stocks[], int *num_stocks) {
    if (*num_stocks == 0) {
        printf("Error: No stocks to remove.\n");
        return;
    }

    printf("Enter the name of the stock to remove: ");
    char stock_name[MAX_NAME];
    scanf("%s", stock_name);

    int found_index = -1;
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Error: Stock not found.\n");
        return;
    }

    // Move all stocks after the removed stock up one index
    for (int i = found_index + 1; i < *num_stocks; i++) {
        stocks[i - 1] = stocks[i];
    }

    printf("Stock removed successfully.\n");
    (*num_stocks)--;
}

// Displays all stocks in the stock array
void display_stocks(Stock stocks[], int num_stocks) {
    if (num_stocks == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("%-30s%-10s\n", "Stock Name", "Stock Price");
    printf("--------------------------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-30s%-10.2f\n", stocks[i].name, stocks[i].price);
    }
}
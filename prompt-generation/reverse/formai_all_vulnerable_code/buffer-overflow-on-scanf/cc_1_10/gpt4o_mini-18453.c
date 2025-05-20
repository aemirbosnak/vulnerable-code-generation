//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float history[10];
    int history_count;
} Stock;

void add_stock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }

    Stock new_stock;
    printf("Enter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter stock price: ");
    scanf("%f", &new_stock.price);
    new_stock.history[0] = new_stock.price;
    new_stock.history_count = 1;

    stocks[*count] = new_stock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void update_stock(Stock stocks[], int count) {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            if (stocks[i].history_count < 10) {
                printf("Enter new stock price: ");
                scanf("%f", &stocks[i].price);
                stocks[i].history[stocks[i].history_count] = stocks[i].price;
                stocks[i].history_count++;
                printf("Stock price updated successfully!\n");
            } else {
                printf("Price history is full, cannot update!\n");
            }
            return;
        }
    }
    printf("Stock not found!\n");
}

void view_stocks(Stock stocks[], int count) {
    printf("\nCurrent stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Current Price: %.2f\n", stocks[i].name, stocks[i].price);
        printf("Price history: ");
        for (int j = 0; j < stocks[i].history_count; j++) {
            printf("%.2f ", stocks[i].history[j]);
        }
        printf("\n");
    }
}

void display_menu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Quit\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                update_stock(stocks, count);
                break;
            case 3:
                view_stocks(stocks, count);
                break;
            case 4:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 4);

    return 0;
}
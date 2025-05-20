//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void add_stock(const char *name, float price) {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }
    strncpy(stocks[stock_count].name, name, NAME_LENGTH - 1);
    stocks[stock_count].name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    stocks[stock_count].price = price;
    stock_count++;
    printf("Added stock: %s at price: %.2f\n", name, price);
}

void update_stock_price(const char *name, float new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = new_price;
            printf("Updated stock: %s to new price: %.2f\n", name, new_price);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void list_stocks() {
    if (stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }
    printf("List of stocks:\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    char action[10], name[NAME_LENGTH];
    float price;

    printf("Welcome to the Stock Market Tracker!\n");
    while (1) {
        printf("Available actions: ADD, UPDATE, LIST, EXIT\n");
        printf("Enter action: ");
        scanf("%s", action);

        if (strcmp(action, "ADD") == 0) {
            printf("Enter stock name: ");
            scanf("%s", name);
            printf("Enter stock price: ");
            scanf("%f", &price);
            add_stock(name, price);
        } else if (strcmp(action, "UPDATE") == 0) {
            printf("Enter stock name: ");
            scanf("%s", name);
            printf("Enter new stock price: ");
            scanf("%f", &price);
            update_stock_price(name, price);
        } else if (strcmp(action, "LIST") == 0) {
            list_stocks();
        } else if (strcmp(action, "EXIT") == 0) {
            printf("Exiting Stock Market Tracker. Goodbye!\n");
            break;
        } else {
            printf("Invalid action. Please try again.\n");
        }
    }
    return 0;
}
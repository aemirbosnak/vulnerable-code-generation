//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void add_stock(const char *name, float price) {
    if (stock_count < MAX_STOCKS) {
        strncpy(stocks[stock_count].name, name, MAX_NAME_LENGTH);
        stocks[stock_count].price = price;
        stocks[stock_count].change = 0.0; 
        stock_count++;
        printf("Added stock: %s at price: %.2f\n", name, price);
    } else {
        printf("Unable to add more stocks, maximum limit reached.\n");
    }
}

void update_stock(const char *name, float new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].change = new_price - stocks[i].price;
            stocks[i].price = new_price;
            printf("Updated %s to new price: %.2f\n", name, new_price);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void display_stocks() {
    printf("\n=== Stock Tracker ===\n");
    printf("Name\t\tPrice\t\tChange\n");
    printf("----------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%-15s %.2f\t\t%.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("==========================\n");
}

void get_random_price_update() {
    srand(time(NULL));
    for (int i = 0; i < stock_count; i++) {
        float random_change = ((rand() % 200) - 100) / 100.0; // Change between -1.00 to 0.99
        update_stock(stocks[i].name, stocks[i].price + random_change);
    }
}

void menu() {
    while (1) {
        printf("\n==== Stock Market Tracker ====\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display All Stocks\n");
        printf("4. Random Price Update\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[MAX_NAME_LENGTH];
            float price;
            printf("Enter stock name: ");
            scanf("%s", name);
            printf("Enter stock price: ");
            scanf("%f", &price);
            add_stock(name, price);
        } else if (choice == 2) {
            char name[MAX_NAME_LENGTH];
            float new_price;
            printf("Enter stock name to update: ");
            scanf("%s", name);
            printf("Enter new price: ");
            scanf("%f", &new_price);
            update_stock(name, new_price);
        } else if (choice == 3) {
            display_stocks();
        } else if (choice == 4) {
            get_random_price_update();
            display_stocks();
        } else if (choice == 5) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n");
    menu();
    return 0;
}
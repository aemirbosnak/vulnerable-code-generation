//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10 // Maximum number of stocks that can be tracked
#define MAX_NAME_LENGTH 20 // Maximum length of a stock name
#define MAX_PRICE_LENGTH 10 // Maximum length of a stock price

struct Stock {
    char name[MAX_NAME_LENGTH];
    float price;
};

void display_menu();
void add_stock(struct Stock* stocks, int* num_stocks);
void remove_stock(struct Stock* stocks, int* num_stocks);
void update_stock(struct Stock* stocks, int num_stocks);
void display_stocks(struct Stock* stocks, int num_stocks);

int main() {
    struct Stock stocks[MAX_STOCKS]; // Array of stocks
    int num_stocks = 0; // Number of stocks currently tracked
    int choice = 0; // User's menu choice
    int i; // Loop index
    
    printf("Welcome to the Stock Market Tracker!\n\n");
    
    while (choice != 5) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_stock(stocks, &num_stocks);
                break;
            case 2:
                remove_stock(stocks, &num_stocks);
                break;
            case 3:
                update_stock(stocks, num_stocks);
                break;
            case 4:
                display_stocks(stocks, num_stocks);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void display_menu() {
    printf("What would you like to do?\n");
    printf("1. Add a stock\n");
    printf("2. Remove a stock\n");
    printf("3. Update a stock's price\n");
    printf("4. Display all stocks\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void add_stock(struct Stock* stocks, int* num_stocks) {
    if (*num_stocks >= MAX_STOCKS) {
        printf("Error: You have reached the maximum number of stocks that can be tracked.\n");
        return;
    }
    
    struct Stock new_stock;
    
    printf("Enter the name of the stock (max. %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", new_stock.name);
    
    printf("Enter the price of the stock (max. %d characters): ", MAX_PRICE_LENGTH - 1);
    scanf("%f", &new_stock.price);
    
    stocks[*num_stocks] = new_stock;
    (*num_stocks)++;
    
    printf("%s has been added to the stock tracker.\n", new_stock.name);
}

void remove_stock(struct Stock* stocks, int* num_stocks) {
    if (*num_stocks == 0) {
        printf("Error: There are no stocks to remove.\n");
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    
    printf("Enter the name of the stock to remove: ");
    scanf("%s", name);
    
    int found = 0;
    int index = 0;
    
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if (found) {
        printf("%s has been removed from the stock tracker.\n", name);
        
        for (int i = index; i < *num_stocks - 1; i++) {
            stocks[i] = stocks[i+1];
        }
        
        (*num_stocks)--;
    } else {
        printf("Error: %s is not being tracked.\n", name);
    }
}

void update_stock(struct Stock* stocks, int num_stocks) {
    if (num_stocks == 0) {
        printf("Error: There are no stocks to update.\n");
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);
    
    int found = 0;
    int index = 0;
    
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if (found) {
        printf("Enter the new price of %s: ", name);
        scanf("%f", &stocks[index].price);
        printf("%s has been updated to $%.2f.\n", name, stocks[index].price);
    } else {
        printf("Error: %s is not being tracked.\n", name);
    }
}

void display_stocks(struct Stock* stocks, int num_stocks) {
    if (num_stocks == 0) {
        printf("There are no stocks being tracked.\n");
        return;
    }
    
    printf("Current stocks being tracked:\n");
    
    for (int i = 0; i < num_stocks; i++) {
        printf("%s - $%.2f\n", stocks[i].name, stocks[i].price);
    }
}
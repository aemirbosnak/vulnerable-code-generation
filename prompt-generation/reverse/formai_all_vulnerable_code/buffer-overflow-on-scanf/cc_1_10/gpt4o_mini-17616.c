//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int shares;
    float price;
} Stock;

Stock portfolio[MAX_STOCKS];
int stock_count = 0;

void add_stock() {
    if (stock_count >= MAX_STOCKS) {
        printf("Portfolio is full! Cannot add more stocks.\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", portfolio[stock_count].name);
    printf("Enter number of shares: ");
    scanf("%d", &portfolio[stock_count].shares);
    printf("Enter current price per share: ");
    scanf("%f", &portfolio[stock_count].price);
    
    stock_count++;
    printf("Stock added successfully!\n");
}

void update_price() {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            printf("Enter new price for %s: ", portfolio[i].name);
            scanf("%f", &portfolio[i].price);
            printf("Price updated successfully!\n");
            return;
        }
    }
    
    printf("Stock not found!\n");
}

void view_portfolio() {
    if (stock_count == 0) {
        printf("Your portfolio is empty.\n");
        return;
    }
    
    printf("Your Stock Portfolio:\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Shares", "Price");
    for (int i = 0; i < stock_count; i++) {
        printf("%-20s %-10d $%-10.2f\n", portfolio[i].name, portfolio[i].shares, portfolio[i].price);
    }
}

float calculate_portfolio_value() {
    float total_value = 0.0;
    for (int i = 0; i < stock_count; i++) {
        total_value += portfolio[i].shares * portfolio[i].price;
    }
    return total_value;
}

void display_total_value() {
    float total_value = calculate_portfolio_value();
    printf("Total portfolio value: $%.2f\n", total_value);
}

void display_menu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Portfolio\n");
    printf("4. Display Total Portfolio Value\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            add_stock();
            break;
        case 2:
            update_price();
            break;
        case 3:
            view_portfolio();
            break;
        case 4:
            display_total_value();
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
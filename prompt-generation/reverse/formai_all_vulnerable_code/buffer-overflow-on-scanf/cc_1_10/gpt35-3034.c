//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char name[20];
    float price;
} stock;

void add_stock(stock* stocks[], int* num_stocks) {
    if (*num_stocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    
    stock* new_stock = (stock*) malloc(sizeof(stock));
    printf("Enter the name of the stock: ");
    scanf("%s", new_stock->name);
    printf("Enter the current price of the stock: ");
    scanf("%f", &new_stock->price);
    
    stocks[*num_stocks] = new_stock;
    *num_stocks = *num_stocks + 1;
    
    printf("%s added to stocks successfully.\n", new_stock->name);
}

void print_stocks(stock* stocks[], int num_stocks) {
    printf("Stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%d. %s - $%.2f\n", i+1, stocks[i]->name, stocks[i]->price);
    }
}

void delete_stock(stock* stocks[], int* num_stocks) {
    if (*num_stocks == 0) {
        printf("No stocks to delete.\n");
        return;
    }
    
    int stock_num;
    print_stocks(stocks, *num_stocks);
    printf("Enter the number of the stock to delete: ");
    scanf("%d", &stock_num);
    
    if (stock_num < 1 || stock_num > *num_stocks) {
        printf("Invalid stock number.\n");
        return;
    }
    
    printf("%s deleted successfully.\n", stocks[stock_num-1]->name);
    free(stocks[stock_num-1]);
    
    for (int i = stock_num-1; i < (*num_stocks)-1; i++) {
        stocks[i] = stocks[i+1];
    }
    
    *num_stocks = *num_stocks - 1;
}

void update_stock(stock* stocks[], int num_stocks) {
    if (num_stocks == 0) {
        printf("No stocks to update.\n");
        return;
    }
    
    int stock_num;
    float new_price;
    print_stocks(stocks, num_stocks);
    printf("Enter the number of the stock to update: ");
    scanf("%d", &stock_num);
    
    if (stock_num < 1 || stock_num > num_stocks) {
        printf("Invalid stock number.\n");
        return;
    }
    
    printf("Enter the new price of the stock: ");
    scanf("%f", &new_price);
    stocks[stock_num-1]->price = new_price;
    
    printf("%s updated successfully.\n", stocks[stock_num-1]->name);
}

int main() {
    stock* stocks[MAX_STOCKS];
    int num_stocks = 0;
    int option;
    
    printf("Welcome to the Stock Market Tracker.\n");
    do {
        printf("\nMenu:\n1. Add Stock\n2. View Stocks\n3. Delete Stock\n4. Update Stock\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_stock(stocks, &num_stocks);
                break;
            case 2:
                print_stocks(stocks, num_stocks);
                break;
            case 3:
                delete_stock(stocks, &num_stocks);
                break;
            case 4:
                update_stock(stocks, num_stocks);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);
    
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]);
    }
    
    return 0;
}
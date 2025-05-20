//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10 // assuming the tracker can handle up to 10 stocks 

// structure for a stock 
typedef struct {
    char name[20];
    float price;
    int units;
} stock;

// function to add a stock to the tracker 
void add_stock(stock stocks[], int *num_stocks) {
    if (*num_stocks == MAX_STOCKS) { // if maximum number of stocks reached, exit function
        printf("Maximum number of stocks reached!\n");
        return;
    }
    
    stock new_stock;
    printf("\nEnter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter stock price: ");
    scanf("%f", &new_stock.price);
    printf("Enter number of units: ");
    scanf("%d", &new_stock.units);
    
    stocks[*num_stocks] = new_stock; // add new stock to stocks array
    (*num_stocks)++; // increment number of stocks
}

// function to remove a stock from the tracker
void remove_stock(stock stocks[], int *num_stocks) {
    if (*num_stocks == 0) { // if no stocks to remove, exit function
        printf("No stocks to remove!\n");
        return;
    }
    
    int stock_index;
    printf("\nEnter index of stock to remove: ");
    scanf("%d", &stock_index);
    
    if (stock_index < 0 || stock_index >= *num_stocks) { // check if index is valid
        printf("Invalid stock index!\n");
        return;
    }
    
    for (int i = stock_index; i < *num_stocks-1; i++) { // shift elements to remove stock
        stocks[i] = stocks[i+1];
    }
    
    (*num_stocks)--; // decrement number of stocks
}

// function to display all stocks in the tracker
void display_stocks(stock stocks[], int num_stocks) {
    printf("\nStocks:\n");
    printf("|%-20s|%-10s|%-10s|\n", "Name", "Price", "Units");
    for (int i = 0; i < num_stocks; i++) {
        printf("|%-20s|%-10.2f|%-10d|\n", stocks[i].name, stocks[i].price, stocks[i].units);
    }
}

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    
    int choice;
    while (1) { // infinite loop until user exits 
        printf("\n*** Stock Market Tracker ***\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Display all stocks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_stock(stocks, &num_stocks);
                break;
            case 2:
                remove_stock(stocks, &num_stocks);
                break;
            case 3:
                display_stocks(stocks, num_stocks);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCKS 50 //Maximum stocks that can be tracked

struct Stock {
    char ticker[10];  //Ticker symbol of stock e.g AAPL
    double current_price; //Current stock price 
    double open_price; //Stock price at opening
    double high_price; //Highest price of the day
    double low_price; //Lowest price of the day
};

struct Stock stock_list[MAX_STOCKS]; //Array of Stock structures

int num_stocks = 0; //Number of stocks currently being tracked

void add_stock() {
    //Function to add a new stock
    if (num_stocks == MAX_STOCKS) {
        printf("The maximum number of stocks have already been added.\n");
        return;
    }
    struct Stock new_stock;
    printf("Enter the ticker symbol of the stock: ");
    scanf("%s", new_stock.ticker);
    printf("Enter the current price of the stock: ");
    scanf("%lf", &new_stock.current_price);
    printf("Enter the opening price of the stock: ");
    scanf("%lf", &new_stock.open_price);
    printf("Enter the highest price of the stock for the day: ");
    scanf("%lf", &new_stock.high_price);
    printf("Enter the lowest price of the stock for the day: ");
    scanf("%lf", &new_stock.low_price);
    stock_list[num_stocks++] = new_stock;
}

void remove_stock(char* ticker) {
    //Function to remove a stock based on ticker symbol
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stock_list[i].ticker, ticker) == 0) {
            break;
        }
    }
    if (i == num_stocks) {
        printf("Stock with ticker symbol %s not found.\n", ticker);
        return;
    }
    for (int j = i; j < num_stocks - 1; j++) {
        stock_list[j] = stock_list[j + 1];
    }
    num_stocks--;
    printf("Stock with ticker symbol %s removed.\n", ticker);
}

void update_stock(char* ticker) {
    //Function to update the details of a stock based on ticker symbol
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stock_list[i].ticker, ticker) == 0) {
            break;
        }
    }
    if (i == num_stocks) {
        printf("Stock with ticker symbol %s not found.\n", ticker);
        return;
    }
    printf("Enter the current price of the stock: ");
    scanf("%lf", &stock_list[i].current_price);
    printf("Enter the opening price of the stock: ");
    scanf("%lf", &stock_list[i].open_price);
    printf("Enter the highest price of the stock for the day: ");
    scanf("%lf", &stock_list[i].high_price);
    printf("Enter the lowest price of the stock for the day: ");
    scanf("%lf", &stock_list[i].low_price);
    printf("Details of stock with ticker symbol %s updated.\n", ticker);
}

void display_stock(char* ticker) {
    //Function to display the details of a stock based on ticker symbol
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stock_list[i].ticker, ticker) == 0) {
            printf("Ticker: %s\n", stock_list[i].ticker);
            printf("Current Price: %.2lf\n", stock_list[i].current_price);
            printf("Open Price: %.2lf\n", stock_list[i].open_price);
            printf("High Price: %.2lf\n", stock_list[i].high_price);
            printf("Low Price: %.2lf\n", stock_list[i].low_price);
            return;
        }
    }
    printf("Stock with ticker symbol %s not found.\n", ticker);
}

void display_all_stocks() {
    //Function to display the details of all current stocks being tracked
    printf("Current Stocks Tracked: \n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock #%d\n", i+1);
        printf("Ticker: %s\n", stock_list[i].ticker);
        printf("Current Price: %.2lf\n", stock_list[i].current_price);
        printf("Open Price: %.2lf\n", stock_list[i].open_price);
        printf("High Price: %.2lf\n", stock_list[i].high_price);
        printf("Low Price: %.2lf\n\n", stock_list[i].low_price);
    }
}

int main() {
    int choice;
    char ticker[10];
    do {
        printf("Main Menu\n");
        printf("1. Add a new stock\n");
        printf("2. Remove a stock\n");
        printf("3. Update stock details\n");
        printf("4. Display details of a stock\n");
        printf("5. Display details of all stocks being tracked\n");
        printf("6. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                printf("Enter the ticker symbol of the stock to be removed: ");
                scanf("%s", ticker);
                remove_stock(ticker);
                break;
            case 3:
                printf("Enter the ticker symbol of the stock to be updated: ");
                scanf("%s", ticker);
                update_stock(ticker);
                break;
            case 4:
                printf("Enter the ticker symbol of the stock to be displayed: ");
                scanf("%s", ticker);
                display_stock(ticker);
                break;
            case 5:
                display_all_stocks();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);
  return 0;
}
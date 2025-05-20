//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 5 // maximum number of stocks the tracker can hold
#define MAX_NAME_LENGTH 20 // maximum length of stock name
#define MAX_DATE_LENGTH 11 // maximum length of date string

typedef struct {
    char ticker[MAX_NAME_LENGTH];
    float price;
    char date[MAX_DATE_LENGTH];
} Stock;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu() {
    printf("\n\n======================");
    printf("\n Sherlock's StockTracker");
    printf("\n======================");
    printf("\n1. Add Stock");
    printf("\n2. Remove Stock");
    printf("\n3. View All Stocks");
    printf("\n4. View Specific Stock");
    printf("\n5. Exit");
    printf("\n\nPlease enter your choice: ");
}

void add_stock(Stock stocks[], int* count) {
    if (*count == MAX_STOCKS) {
        printf("\nError: Tracker is full! You cannot add any more stocks.\n");
        return;
    }
    
    Stock new_stock;
    printf("\nEnter the stock's ticker symbol:");
    scanf("%s", new_stock.ticker);
    printf("\nEnter the stock's current price:");
    scanf("%f", &new_stock.price);
    clear_input_buffer();
    printf("\nEnter the date of last update (dd/mm/yyyy):");
    fgets(new_stock.date, MAX_DATE_LENGTH, stdin);
    new_stock.date[strcspn(new_stock.date, "\n")] = 0; // remove newline character
    
    stocks[*count] = new_stock;
    *count += 1;
    printf("\nSuccessfully added %s to tracker.\n", new_stock.ticker);
}

void remove_stock(Stock stocks[], int* count) {
    if (*count == 0) {
        printf("\nThere are no stocks in the tracker to remove.\n");
        return;
    }
    
    printf("\nEnter the ticker symbol of the stock you wish to remove:");
    char ticker[MAX_NAME_LENGTH];
    scanf("%s", ticker);
    clear_input_buffer();
    
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nError: The stock with ticker symbol %s could not be found.\n", ticker);
        return;
    }
    
    for (int i = index; i < *count - 1; i++) {
        stocks[i] = stocks[i+1];
    }
    *count -= 1;
    printf("\nSuccessfully removed %s from tracker.\n", ticker);
}

void view_all_stocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("\nThere are no stocks in the tracker to display.\n");
        return;
    }
    
    printf("\n===============================");
    printf("\n Stocks currently in the tracker");
    printf("\n===============================\n");
    printf("%-10s %-10s %-12s\n", "Ticker", "Price", "Last update");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %7.2f %12s\n", stocks[i].ticker, stocks[i].price, stocks[i].date);
    }
}

void view_specific_stock(Stock stocks[], int count) {
    if (count == 0) {
        printf("\nThere are no stocks in the tracker to display.\n");
        return;
    }
    
    printf("\nEnter the ticker symbol of the stock you wish to view:");
    char ticker[MAX_NAME_LENGTH];
    scanf("%s", ticker);
    clear_input_buffer();
    
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nError: The stock with ticker symbol %s could not be found.\n", ticker);
        return;
    }
    
    printf("\n===========================");
    printf("\n Details for stock %s", ticker);
    printf("\n===========================\n");
    printf("%-10s %-10s %-12s\n", "Ticker", "Price", "Last update");
    printf("--------------------------------\n");
    printf("%-10s %7.2f %12s\n", stocks[index].ticker, stocks[index].price, stocks[index].date);   
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice = 0;
    
    printf("Welcome to Sherlock's StockTracker!\n\n");
    
    while (choice != 5) {
        print_menu();
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch(choice) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                remove_stock(stocks, &count);
                break;
            case 3:
                view_all_stocks(stocks, count);
                break;
            case 4:
                view_specific_stock(stocks, count);
                break;
            case 5:
                printf("\nThank you for using Sherlock's StockTracker. Goodbye!\n");
                break;
            default:
                printf("\nError: Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    
    return 0;
}
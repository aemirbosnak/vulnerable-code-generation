//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of stocks to track
#define MAX_STOCKS 10

// Define struct to hold stock information
struct Stock {
    char symbol[6];
    double current_price;
    double open_price;
    double high_price;
    double low_price;
    int volume;
};

// Function to display menu options
void print_menu() {
  printf("\n\n\tSTOCK MARKET TRACKER\n");
  printf("-----------------------------------------------------------------------\n");
  printf("1. Add stock\n");
  printf("2. Remove stock\n");
  printf("3. Update stock prices\n");
  printf("4. View stock information\n");
  printf("5. View top gainers and losers\n");
  printf("6. Exit program\n");
  printf("Enter your choice: ");
}

// Function to add a new stock
void add_stock(struct Stock* stock_list, int* num_stocks) {
    if (*num_stocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached!\n");
        return;
    }
    
    printf("Enter stock symbol (e.g. AAPL): ");
    scanf("%s", stock_list[*num_stocks].symbol);
    
    printf("Enter current price: ");
    scanf("%lf", &stock_list[*num_stocks].current_price);
    
    printf("Enter opening price: ");
    scanf("%lf", &stock_list[*num_stocks].open_price);
    
    printf("Enter high price: ");
    scanf("%lf", &stock_list[*num_stocks].high_price);
    
    printf("Enter low price: ");
    scanf("%lf", &stock_list[*num_stocks].low_price);
    
    printf("Enter volume: ");
    scanf("%d", &stock_list[*num_stocks].volume);
    
    (*num_stocks)++;
    
    printf("\nStock added successfully!\n");
}

// Function to remove a stock
void remove_stock(struct Stock* stock_list, int* num_stocks) {
    char symbolToRemove[6];
    
    printf("Enter stock symbol to remove: ");
    scanf("%s", symbolToRemove);
    
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(stock_list[i].symbol, symbolToRemove) == 0) {
            for (int j = i + 1; j < *num_stocks; j++) {
                stock_list[j - 1] = stock_list[j];
            }
            
            (*num_stocks)--;
            
            printf("\nStock removed successfully!\n");
            return;
        }
    }
    
    printf("\nStock not found!\n");
}

// Function to update stock prices
void update_prices(struct Stock* stock_list, int num_stocks) {
    srand(time(NULL));
    
    for (int i = 0; i < num_stocks; i++) {
        double currentPrice = stock_list[i].current_price;
        double openPrice = stock_list[i].open_price;
        
        // Simulate random price movement
        double priceChange = ((double) rand() / (double) RAND_MAX) * (currentPrice - openPrice);
        
        // Update stock price values
        stock_list[i].current_price += priceChange;
        stock_list[i].open_price = currentPrice;
        if (stock_list[i].current_price > stock_list[i].high_price) {
            stock_list[i].high_price = stock_list[i].current_price;
        }
        if (stock_list[i].current_price < stock_list[i].low_price) {
            stock_list[i].low_price = stock_list[i].current_price;
        }
        stock_list[i].volume += (rand() % 10000) - 5000;
    }
    
    printf("\nStock prices updated!\n");
}

// Function to view stock information
void view_stock_info(struct Stock* stock_list, int num_stocks) {
    char symbolToView[6];
    
    printf("Enter stock symbol to view: ");
    scanf("%s", symbolToView);
    
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stock_list[i].symbol, symbolToView) == 0) {
            printf("\n\n\t%s STOCK INFORMATION\n", stock_list[i].symbol);
            printf("-----------------------------------------------------------------------\n");
            printf("Current Price: $%.2lf\n", stock_list[i].current_price);
            printf("Open Price: $%.2lf\n", stock_list[i].open_price);
            printf("High Price: $%.2lf\n", stock_list[i].high_price);
            printf("Low Price: $%.2lf\n", stock_list[i].low_price);
            printf("Volume: %d\n", stock_list[i].volume);
            return;
        }
    }
    
    printf("\nStock not found!\n");
}

// Function to compare stock structs by price change
int compare_price_change(const void* a, const void* b) {
    struct Stock* stockA = (struct Stock*) a;
    struct Stock* stockB = (struct Stock*) b;
    
    double changeA = stockA->current_price - stockA->open_price;
    double changeB = stockB->current_price - stockB->open_price;
    
    if (changeA < changeB) {
        return 1;
    }
    else if (changeA > changeB) {
        return -1;
    }
    else {
        return 0;
    }
}

// Function to view top gainers and losers
void view_top_gainers_losers(struct Stock* stock_list, int num_stocks) {
    qsort(stock_list, num_stocks, sizeof(struct Stock), compare_price_change);
    
    printf("\n\n\tTOP GAINERS AND LOSERS\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Symbol\t\tPrice Change (%%)\n");
    
    for (int i = 0; i < num_stocks; i++) {
        double change = ((stock_list[i].current_price - stock_list[i].open_price) / stock_list[i].open_price) * 100;
        printf("%s\t\t%.2lf\n", stock_list[i].symbol, change);
    }
}

// Main function
int main() {
    int numStocks = 0;
    struct Stock stockList[MAX_STOCKS];
    
    int choice = 0;
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_stock(stockList, &numStocks);
                break;
            case 2:
                remove_stock(stockList, &numStocks);
                break;
            case 3:
                update_prices(stockList, numStocks);
                break;
            case 4:
                view_stock_info(stockList, numStocks);
                break;
            case 5:
                view_top_gainers_losers(stockList, numStocks);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}
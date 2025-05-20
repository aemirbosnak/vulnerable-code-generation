//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Stock struct to store symbol and price
struct Stock {
    char symbol[10];
    float price;
};
typedef struct Stock Stock;

// Function to print stock information
void printStocks(Stock* stocks, int n) {
    printf("Symbol\tPrice\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    // Number of stocks to track
    int n = 3;
    
    // Allocate memory for stocks array
    Stock* stocks = malloc(n * sizeof(Stock));
    
    // Initialize stock information
    for (int i = 0; i < n; i++) {
        printf("Enter stock symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Enter stock price: ");
        scanf("%f", &stocks[i].price);
    }
    
    // Print initial stock information
    printf("Initial Stock Information:\n");
    printStocks(stocks, n);
    
    // Allow user to update stock prices
    char choice;
    do {
        printf("Do you want to update prices? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            // Prompt for stock symbol
            char symbol[10];
            printf("Enter stock symbol to update: ");
            scanf("%s", symbol);
            
            // Find matching stock symbol and update price
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(stocks[i].symbol, symbol) == 0) {
                    printf("Enter new price for %s: ", symbol);
                    scanf("%f", &stocks[i].price);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Invalid stock symbol\n");
            }
            
            // Print updated stock information
            printStocks(stocks, n);
        }
    } while (choice == 'y' || choice == 'Y');
    
    // Free memory allocated for stocks array
    free(stocks);
    
    return 0;
}
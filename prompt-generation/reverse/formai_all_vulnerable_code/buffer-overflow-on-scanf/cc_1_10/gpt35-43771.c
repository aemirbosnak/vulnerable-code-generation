//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 50

// Define a stock struct with name and price
struct Stock {
    char name[MAX_NAME_LENGTH];
    float price;
};

// Global array of stocks
struct Stock stocks[MAX_STOCKS];

// Global variables to keep track of number of stocks and current index
int numStocks = 0;
int currentIndex = 0;

// Function to add a new stock to the array
void addStock(char name[], float price) {
    // Check if maximum number of stocks has been reached
    if (numStocks + 1 > MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    
    // Copy name into new stock and set price
    strcpy(stocks[numStocks].name, name);
    stocks[numStocks].price = price;
    
    // Increment number of stocks
    numStocks++;
}

// Function to print all stocks in the array
void printStocks() {
    if (numStocks == 0) {
        printf("No stocks to display.\n");
        return;
    }
    
    printf("%-10s %s\n", "Price", "Name");
    
    for (int i = 0; i < numStocks; i++) {
        printf("%-10.2f %s\n", stocks[i].price, stocks[i].name);
    }
}

// Function to get user input for a new stock
void getStockInput() {
    char name[MAX_NAME_LENGTH];
    float price;
    
    printf("Enter name of stock: ");
    scanf("%s", name);
    
    printf("Enter price of stock: ");
    scanf("%f", &price);
    
    addStock(name, price);
}

// Function to get user input for which stock to view
void getStockViewInput() {
    int choice;
    
    printf("Enter the index of the stock to view: ");
    scanf("%d", &choice);
    
    // Check if choice is valid
    if (choice < 1 || choice > numStocks) {
        printf("Invalid choice.\n");
        return;
    }
    
    // Set current index for viewing
    currentIndex = choice - 1;
}

// Function to view the current stock
void viewCurrentStock() {
    if (numStocks == 0) {
        printf("No stocks to view.\n");
        return;
    }
    
    printf("%s: %.2f\n", stocks[currentIndex].name, stocks[currentIndex].price);
}

// Function to update the current stock price
void updateCurrentStockPrice() {
    if (numStocks == 0) {
        printf("No stocks to update.\n");
        return;
    }
    
    float newPrice;
    
    printf("Enter new price for %s: ", stocks[currentIndex].name);
    scanf("%f", &newPrice);
    
    stocks[currentIndex].price = newPrice;
}

int main() {
    while (true) {
        printf("1. Add stock\n");
        printf("2. View all stocks\n");
        printf("3. View current stock\n");
        printf("4. Update current stock price\n");
        printf("5. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                getStockInput();
                break;
            case 2:
                printStocks();
                break;
            case 3:
                getStockViewInput();
                viewCurrentStock();
                break;
            case 4:
                getStockViewInput();
                updateCurrentStockPrice();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
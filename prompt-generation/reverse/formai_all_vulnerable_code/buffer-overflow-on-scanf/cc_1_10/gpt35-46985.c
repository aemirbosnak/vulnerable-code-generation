//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double change;
} Stock;

Stock stocks[MAX_STOCKS];
int numOfStocks = 0;

void addStock() {
    // Check if max stocks limit has been reached
    if (numOfStocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }
    
    // Get name and price of new stock
    char name[MAX_NAME_LENGTH];
    double price;
    printf("Enter name of stock: ");
    scanf("%s", name);
    printf("Enter price of stock: ");
    scanf("%lf", &price);
    
    // Add new stock to array
    Stock newStock;
    strcpy(newStock.name, name);
    newStock.price = price;
    newStock.change = 0.0;
    stocks[numOfStocks] = newStock;
    numOfStocks++;
    printf("Stock successfully added.\n");
}

void removeStock() {
    // Check if there are any stocks to remove
    if (numOfStocks == 0) {
        printf("Error: There are no stocks to remove.\n");
        return;
    }
    
    // Get index of stock to remove
    int index = -1;
    printf("Enter index of stock to remove: ");
    scanf("%d", &index);
    if (index < 0 || index >= numOfStocks) {
        printf("Error: Invalid index.\n");
        return;
    }
    
    // Remove stock from array and shift remaining stocks left
    for (int i = index; i < numOfStocks - 1; i++) {
        stocks[i] = stocks[i+1];
    }
    numOfStocks--;
    printf("Stock successfully removed.\n");
}

void displayStocks() {
    // Check if there are any stocks to display
    if (numOfStocks == 0) {
        printf("There are no stocks to display.\n");
        return;
    }
    
    // Display header
    printf("%-5s %-20s %-10s %-10s\n", "Index", "Name", "Price", "Change");
    
    // Display each stock
    for (int i = 0; i < numOfStocks; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f\n", i, stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStocks() {
    // Generate random change for each stock
    srand(time(NULL));
    for (int i = 0; i < numOfStocks; i++) {
        double change = ((double) rand() / (RAND_MAX)) * 10.0 - 5.0;
        stocks[i].change = change;
        stocks[i].price += change;
    }
}

int main() {
    char command;
    do {
        // Display menu
        printf("\n");
        printf("Stock market tracker\n");
        printf("--------------------\n");
        printf("Commands:\n");
        printf("  a - Add stock\n");
        printf("  r - Remove stock\n");
        printf("  d - Display stocks\n");
        printf("  u - Update stocks\n");
        printf("  q - Quit\n");
        printf("Enter command: ");
        
        // Get command from user
        scanf(" %c", &command);
        
        // Execute command
        switch (command) {
            case 'a':
                addStock();
                break;
            case 'r':
                removeStock();
                break;
            case 'd':
                displayStocks();
                break;
            case 'u':
                updateStocks();
                printf("Stocks successfully updated.\n");
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid command.\n");
                break;
        }
    } while (command != 'q');
    
    return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

// create a struct to hold stock information
typedef struct Stock {
    char name[20];
    float price;
    float change;
} Stock;

// function to get stock information from user
Stock getStockInfo() {
    Stock newStock;
    printf("Enter the name of the stock: ");
    scanf("%s", newStock.name);
    printf("Enter the price of one share: ");
    scanf("%f", &newStock.price);
    printf("Enter the percentage change in price (positive or negative): ");
    scanf("%f", &newStock.change);
    return newStock;
}

// function to display current stock information
void displayStocks(Stock stocks[], int numStocks) {
    printf("Current Stock Information:\n");
    for(int i = 0; i < numStocks; i++) {
        printf("Name: %s\tPrice: $%.2f\tChange: %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

int main() {
    Stock myStocks[MAX_STOCKS];
    int numStocks = 0;
    int choice;
    do {
        printf("\nStock Market Tracker - Choose an option:\n");
        printf("1. Add a new stock\n");
        printf("2. Display current stocks\n");
        printf("3. Quit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(numStocks < MAX_STOCKS) {
                    myStocks[numStocks] = getStockInfo();
                    numStocks++;
                }
                else {
                    printf("Maximum number of stocks reached.\n");
                }
                break;
            case 2:
                if(numStocks > 0) {
                    displayStocks(myStocks, numStocks);
                }
                else {
                    printf("No stocks currently in tracker.\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please choose an option from the menu.\n");
        }
    } while(choice != 3);
    return 0;
}
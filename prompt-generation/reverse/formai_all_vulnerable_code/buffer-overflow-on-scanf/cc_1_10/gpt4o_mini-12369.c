//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayStocks(Stock stocks[], int count);
void addStock(Stock stocks[], int *count);
void updateStock(Stock stocks[], int count);
void deleteStock(Stock stocks[], int *count);
void clearScreen();

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while(1) {
        clearScreen();
        printf("Welcome to the Stock Market Tracker!\n");
        printf("1. Display Stocks\n");
        printf("2. Add Stock\n");
        printf("3. Update Stock\n");
        printf("4. Delete Stock\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayStocks(stocks, count);
                break;
            case 2:
                addStock(stocks, &count);
                break;
            case 3:
                updateStock(stocks, count);
                break;
            case 4:
                deleteStock(stocks, &count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Press Enter to continue...\n");
        getchar(); // To consume newline character left by scanf
        getchar(); // To wait for user response
    }
    return 0;
}

void displayStocks(Stock stocks[], int count) {
    clearScreen();
    printf("Current Stocks:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Change");
    printf("--------------------------------------------------\n");
    
    for(int i = 0; i < count; i++) {
        printf("%-20s $%-9.2f %+9.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full. Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter stock percent change: ");
    scanf("%f", &newStock.change);
    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to update.\n");
        return;
    }
    
    displayStocks(stocks, count);
    int index;
    printf("Enter the stock number (1-%d) to update: ", count);
    scanf("%d", &index);
    
    if(index < 1 || index > count) {
        printf("Invalid stock number.\n");
        return;
    }
    
    index--; // To match array index
    printf("Updating stock: %s\n", stocks[index].name);
    printf("Enter new price: ");
    scanf("%f", &stocks[index].price);
    printf("Enter new percent change: ");
    scanf("%f", &stocks[index].change);
    printf("Stock updated successfully!\n");
}

void deleteStock(Stock stocks[], int *count) {
    if(*count == 0) {
        printf("No stocks to delete.\n");
        return;
    }
    
    displayStocks(stocks, *count);
    int index;
    printf("Enter the stock number (1-%d) to delete: ", *count);
    scanf("%d", &index);
    
    if(index < 1 || index > *count) {
        printf("Invalid stock number.\n");
        return;
    }
    
    index--; // To match array index
    for(int i = index; i < *count - 1; i++) {
        stocks[i] = stocks[i + 1];
    }
    (*count)--;
    printf("Stock deleted successfully!\n");
}

void clearScreen() {
    // This function clears the terminal screen
    system("clear");  // Use "cls" for Windows
}
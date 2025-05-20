//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20

struct stock {
    char name[MAX_NAME_LENGTH];
    float price;
};

typedef struct stock Stock;

// Function prototypes
void displayMainMenu();
void addStock(Stock stocks[], int *count);
void deleteStock(Stock stocks[], int *count);
void updateStockPrice(Stock stocks[], int count);
void displayAllStocks(Stock stocks[], int count);
int searchStock(char searchName[], Stock stocks[], int count);

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1: // Add a new stock
                addStock(stocks, &count);
                break;
            case 2: // Delete a stock
                deleteStock(stocks, &count);
                break;
            case 3: // Update stock price
                updateStockPrice(stocks, count);
                break;
            case 4: // Display all stocks
                displayAllStocks(stocks, count);
                break;
            case 5: // Exit the program
                printf("Exiting program...\n");
                break;
            default: // Invalid choice
                printf("Invalid choice! Try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}

/**
 * Display the main menu with options for the user.
 */
void displayMainMenu() {
    printf("== Stock Market Tracker ==\n");
    printf("1. Add new stock\n");
    printf("2. Delete a stock\n");
    printf("3. Update stock price\n");
    printf("4. Display all stocks\n");
    printf("5. Exit program\n");
}

/**
 * Add a new stock to the list of stocks.
 */
void addStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    float price;

    if (*count == MAX_STOCKS) {
        printf("Error: Cannot add more stocks.\n");
        return;
    }

    printf("Enter the name of the stock: ");
    scanf("%s", name);

    if (searchStock(name, stocks, *count) != -1) {
        printf("Error: Stock already exists!\n");
        return;
    }

    printf("Enter the price of the stock: ");
    scanf("%f", &price);

    strcpy(stocks[*count].name, name);
    stocks[*count].price = price;

    (*count)++;

    printf("Stock added successfully!\n");
}

/**
 * Delete a stock from the list of stocks.
 */
void deleteStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    int index;

    if (*count == 0) {
        printf("Error: No stocks to delete.\n");
        return;
    }

    printf("Enter the name of the stock to delete: ");
    scanf("%s", name);

    index = searchStock(name, stocks, *count);

    if (index == -1) {
        printf("Error: Stock not found.\n");
        return;
    }

    strcpy(stocks[index].name, "");
    stocks[index].price = 0;

    for (int i = index; i < (*count) - 1; i++) {
        stocks[i] = stocks[i + 1];
    }

    (*count)--;

    printf("Stock deleted successfully!\n");
}

/**
 * Update the price of a stock in the list of stocks.
 */
void updateStockPrice(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    float price;
    int index;

    if (count == 0) {
        printf("Error: No stocks to update.\n");
    }

    printf("Enter the name of the stock to update: ");
    scanf("%s", name);

    index = searchStock(name, stocks, count);

    if (index == -1) {
        printf("Error: Stock not found.\n");
        return;
    }

    printf("Enter the new price of the stock: ");
    scanf("%f", &price);

    stocks[index].price = price;

    printf("Stock price updated successfully!\n");
}

/**
 * Display all the stocks in the list.
 */
void displayAllStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("%-20s %s\n", "Stock Name", "Price");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (strlen(stocks[i].name) > 0) {
            printf("%-20s %6.2f\n", stocks[i].name, stocks[i].price);
        }
    }
}

/**
 * Search for a stock in the list of stocks.
 */
int searchStock(char searchName[], Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];

    for (int i = 0; i < count; i++) {
        strcpy(name, stocks[i].name);
        // Convert both the searchName and name to uppercase before comparing
        for (int j = 0; j < strlen(searchName); j++) {
            searchName[j] = toupper(searchName[j]);
        }
        for (int j = 0; j < strlen(name); j++) {
            name[j] = toupper(name[j]);
        }
        if (strcmp(searchName, name) == 0) {
            return i;
        }
    }

    return -1;
}
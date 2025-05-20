//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
    float change;
} Stock;

void displayMenu() {
    printf("\n*** Stock Market Tracker ***\n");
    printf("\n1. Add a stock");
    printf("\n2. Remove a stock");
    printf("\n3. Update stock price");
    printf("\n4. Update stock quantity");
    printf("\n5. Display stock details");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
}

void addStock(Stock *stocks, int *numStocks) {
    if (*numStocks == MAX_STOCKS) {
        printf("\nError: Maximum number of stocks (%d) reached.\n", MAX_STOCKS);
        return;
    }

    Stock newStock;
    printf("\nEnter stock name: ");
    scanf(" %[^\n]", newStock.name);

    printf("Enter price: ");
    scanf("%f", &newStock.price);

    printf("Enter quantity: ");
    scanf("%d", &newStock.quantity);

    newStock.change = 0;

    stocks[*numStocks] = newStock;
    (*numStocks)++;
    printf("\nStock added successfully.\n");
}

void removeStock(Stock *stocks, int *numStocks) {
    if (*numStocks == 0) {
        printf("\nError: No stocks to remove.\n");
        return;
    }

    char stockName[MAX_NAME_LEN];
    printf("\nEnter stock name to remove: ");
    scanf(" %[^\n]", stockName);

    for (int i = 0; i < *numStocks; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            for (int j = i; j < *numStocks - 1; j++) {
                stocks[j] = stocks[j+1];    // Shift the array one position to the left
            }
            (*numStocks)--;
            printf("\nStock removed successfully.\n");
            return;
        }
    }

    printf("\nError: Stock not found.\n");
}

void updatePrice(Stock *stocks, int numStocks) {
    if (numStocks == 0) {
        printf("\nError: No stocks to update.\n");
        return;
    }

    char stockName[MAX_NAME_LEN];
    printf("\nEnter stock name to update price: ");
    scanf(" %[^\n]", stockName);

    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("\nPrice updated successfully.\n");
            return;
        }
    }

    printf("\nError: Stock not found.\n");
}

void updateQuantity(Stock *stocks, int numStocks) {
    if (numStocks == 0) {
        printf("\nError: No stocks to update.\n");
        return;
    }

    char stockName[MAX_NAME_LEN];
    printf("\nEnter stock name to update quantity: ");
    scanf(" %[^\n]", stockName);

    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &stocks[i].quantity);
            printf("\nQuantity updated successfully.\n");
            return;
        }
    }

    printf("\nError: Stock not found.\n");
}

void displayStockDetails(Stock *stocks, int numStocks) {
    if (numStocks == 0) {
        printf("\nError: No stocks to display.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s", "Name", "Price", "Quantity", "Change");

    for (int i = 0; i < numStocks; i++) {
        printf("\n%-20s %-10.2f %-10d %-10.2f", stocks[i].name, stocks[i].price, stocks[i].quantity, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0, choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStock(stocks, &numStocks); break;
            case 2: removeStock(stocks, &numStocks); break;
            case 3: updatePrice(stocks, numStocks); break;
            case 4: updateQuantity(stocks, numStocks); break;
            case 5: displayStockDetails(stocks, numStocks); break;
            case 6: printf("\nExiting program.\n"); break;
            default: printf("\nError: Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
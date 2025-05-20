//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;  // In percentage
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\n========================= Stock Market Tracker =========================\n");
    printf("| %-25s | %-10s | %-10s |\n", "Stock Name", "Price", "Change (%)");
    printf("=======================================================================\n");
    for (int i = 0; i < count; i++) {
        printf("| %-25s | $%-9.2f | %-10.2f |\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("=======================================================================\n");
}

void updateStocks(Stock stocks[], int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        float randomChange = ((float)(rand() % 200) - 100) / 100; // Random changes between -1.00 to +1.00
        stocks[i].price += stocks[i].price * randomChange * 0.01;      // Update stock price
        stocks[i].change = randomChange;                                 // Update change percentage
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count < MAX_STOCKS) {
        printf("Enter stock name: ");
        scanf("%s", stocks[*count].name);
        printf("Enter initial price: ");
        scanf("%f", &stocks[*count].price);
        stocks[*count].change = 0.0; // Initialize change to 0
        (*count)++;
    } else {
        printf("Maximum stocks reached! Cannot add more.\n");
    }
}

void mainMenu(Stock stocks[], int *count) {
    int choice;

    do {
        printf("\n==================== Stock Market Tracker Menu ====================\n");
        printf("1. Add Stock\n");
        printf("2. Update Stocks\n");
        printf("3. Display Stocks\n");
        printf("4. Exit\n");
        printf("===================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, count);
                break;
            case 2:
                updateStocks(stocks, *count);
                printf("Stocks updated successfully!\n");
                break;
            case 3:
                displayStocks(stocks, *count);
                break;
            case 4:
                printf("Exiting the program. Stay energetic!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;

    printf("Welcome to the Energetic Stock Market Tracker!\n");
    mainMenu(stocks, &count);

    return 0;
}
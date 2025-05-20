//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int volume;
} Stock;

void displayMenu() {
    printf("Stock Market Tracker\n");
    printf("====================\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display All Stocks\n");
    printf("4. Search Stock by Name\n");
    printf("5. Exit\n");
}

void addStock(Stock *stocks, int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter stock volume: ");
    scanf("%d", &newStock.volume);

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock *stocks, int count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Updating details for %s:\n", stocks[i].name);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new volume: ");
            scanf("%d", &stocks[i].volume);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(Stock *stocks, int count) {
    printf("Current Stocks:\n");
    printf("================\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Price: %.2f | Volume: %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
    }
}

void searchStock(Stock *stocks, int count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Found Stock: %s | Price: %.2f | Volume: %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
            return;
        }
    }
    printf("Stock not found!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStock(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                searchStock(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    bool isOwned;
} Stock;

void printMenu() {
    printf("Welcome to MyStockTracker!\n");
    printf("What would you like to do?\n");
    printf("1. Add a stock to your watchlist\n");
    printf("2. Remove a stock from your watchlist\n");
    printf("3. Buy a stock\n");
    printf("4. Sell a stock\n");
    printf("5. Show your watchlist\n");
    printf("6. Quit\n\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int findStock(Stock stocks[], char *name) {
    for(int i = 0; i < MAX_STOCKS; i++) {
        if(strcmp(stocks[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addStock(Stock stocks[]) {
    char name[MAX_NAME_LENGTH];
    float price;
    printf("Enter the name of the stock: ");
    scanf("%s", name);
    printf("Enter the current price of the stock: ");
    scanf("%f", &price);
    int index = findStock(stocks, name);
    if(index == -1) {
        for(int i = 0; i < MAX_STOCKS; i++) {
            if(strlen(stocks[i].name) == 0) {
                strcpy(stocks[i].name, name);
                stocks[i].price = price;
                stocks[i].isOwned = false;
                printf("%s has been added to your watchlist!\n", name);
                break;
            }
        }
    } else {
        printf("%s is already in your watchlist!\n", name);
    }
    printf("\n");
}

void removeStock(Stock stocks[]) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock: ");
    scanf("%s", name);
    int index = findStock(stocks, name);
    if(index != -1) {
        strcpy(stocks[index].name, "");
        stocks[index].price = 0;
        stocks[index].isOwned = false;
        printf("%s has been removed from your watchlist!\n", name);
    } else {
        printf("%s is not in your watchlist!\n", name);
    }
    printf("\n");
}

void buyStock(Stock stocks[]) {
    char name[MAX_NAME_LENGTH];
    float price;
    printf("Enter the name of the stock: ");
    scanf("%s", name);
    int index = findStock(stocks, name);
    if(index != -1) {
        printf("Enter the price per share: ");
        scanf("%f", &price);
        if(price <= stocks[index].price) {
            stocks[index].isOwned = true;
            printf("You have bought shares of %s!\n", name);
        } else {
            printf("The price per share is higher than the current price. You cannot buy\n");
        }
    } else {
        printf("%s is not in your watchlist!\n", name);
    }
    printf("\n");
}

void sellStock(Stock stocks[]) {
    char name[MAX_NAME_LENGTH];
    float price;
    printf("Enter the name of the stock: ");
    scanf("%s", name);
    int index = findStock(stocks, name);
    if(index != -1) {
        if(stocks[index].isOwned) {
            printf("Enter the price per share: ");
            scanf("%f", &price);
            if(price >= stocks[index].price) {
                stocks[index].isOwned = false;
                printf("You have sold shares of %s!\n", name);
            } else {
                printf("The price per share is lower than the current price. You cannot sell\n");
            }
        } else {
            printf("You do not own any shares of %s!\n", name);
        }
    } else {
        printf("%s is not in your watchlist!\n", name);
    }
    printf("\n");
}

void printStockList(Stock stocks[]) {
    printf("Your watchlist contains:\n");
    for(int i = 0; i < MAX_STOCKS; i++) {
        if(strlen(stocks[i].name) != 0) {
            printf("%s - $%.2f", stocks[i].name, stocks[i].price);
            if(stocks[i].isOwned) {
                printf(" - Owned\n");
            } else {
                printf("\n");
            }
        }
    }
    printf("\n");
}

int main() {
    Stock stocks[MAX_STOCKS] = {0};
    int choice = 0;

    while(choice != 6) {
        printMenu();
        choice = getChoice();

        switch(choice) {
            case 1:
                addStock(stocks);
                break;
            case 2:
                removeStock(stocks);
                break;
            case 3:
                buyStock(stocks);
                break;
            case 4:
                sellStock(stocks);
                break;
            case 5:
                printStockList(stocks);
                break;
            case 6:
                printf("Thank you for using MyStockTracker!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n\n");
                break;
        }
    }

    return 0;
}
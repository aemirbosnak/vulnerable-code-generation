//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

struct stock {
    char name[MAX_NAME_LENGTH];
    double price;
    int volume;
};

struct stock portfolio[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    if (numStocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    double price;
    int volume;
    printf("Enter name of stock: ");
    scanf("%s", name);
    printf("Enter price of stock: ");
    scanf("%lf", &price);
    printf("Enter volume of stock: ");
    scanf("%d", &volume);
    struct stock newStock;
    strcpy(newStock.name, name);
    newStock.price = price;
    newStock.volume = volume;
    portfolio[numStocks++] = newStock;
    printf("Stock added to portfolio.\n");
}

void displayPortfolio() {
    if (numStocks == 0) {
        printf("Portfolio is empty.\n");
        return;
    }
    printf("Current portfolio:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2lf, Volume: %d\n", portfolio[i].name, portfolio[i].price, portfolio[i].volume);
    }
}

void deleteStock() {
    if (numStocks == 0) {
        printf("Portfolio is empty.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to delete: ");
    scanf("%s", name);
    int indexToRemove = -1;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove == -1) {
        printf("Stock not found.\n");
        return;
    }
    for (int i = indexToRemove; i < numStocks-1; i++) {
        portfolio[i] = portfolio[i+1];
    }
    numStocks--;
    printf("Stock deleted from portfolio.\n");
}

void updateStock() {
    if (numStocks == 0) {
        printf("Portfolio is empty.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);
    int indexToUpdate = -1;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            indexToUpdate = i;
            break;
        }
    }
    if (indexToUpdate == -1) {
        printf("Stock not found.\n");
        return;
    }
    double price;
    int volume;
    printf("Enter new price of stock: ");
    scanf("%lf", &price);
    printf("Enter new volume of stock: ");
    scanf("%d", &volume);
    portfolio[indexToUpdate].price = price;
    portfolio[indexToUpdate].volume = volume;
    printf("Stock updated successfully.\n");
}

void printMenu() {
    printf("\n");
    printf("Welcome to the Stock Market Tracker\n");
    printf("===================================\n");
    printf("1. Add stock to portfolio\n");
    printf("2. Display current portfolio\n");
    printf("3. Delete stock from portfolio\n");
    printf("4. Update stock in portfolio\n");
    printf("5. Exit program\n");
    printf("===================================\n");
    printf("\n");
}

int main() {
    while(1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addStock();
                break;
            case 2:
                displayPortfolio();
                break;
            case 3:
                deleteStock();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1-5.\n");
                break;
        }
    }
}
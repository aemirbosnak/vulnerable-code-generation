//FormAI DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

int numStocks = 0;
Stock stocks[MAX_STOCKS];

void addStock(char name[], float price) {
    if (numStocks < MAX_STOCKS) {
        strcpy(stocks[numStocks].name, name);
        stocks[numStocks].price = price;
        numStocks++;
    } else {
        printf("ERROR: Maximum number of stocks reached.\n");
    }
}

void displayStocks() {
    printf("Stocks:\n");
    printf("Name\tPrice\n");
    printf("-------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void updatePrice(char name[], float price) {
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = price;
            printf("Price of %s updated to %.2f\n", name, price);
            return;
        }
    }
    printf("ERROR: Stock not found.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        printf("Choose an option:\n");
        printf("1. Add stock\n");
        printf("2. Display stocks\n");
        printf("3. Update stock price\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(name, price);
                break;
            case 2:
                displayStocks();
                break;
            case 3:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updatePrice(name, price);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}
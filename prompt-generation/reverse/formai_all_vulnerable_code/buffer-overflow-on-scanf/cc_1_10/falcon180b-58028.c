//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks;

void addStock() {
    printf("Enter stock name: ");
    scanf("%s", stocks[numStocks].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[numStocks].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[numStocks].quantity);
    numStocks++;
}

void displayStocks() {
    printf("\nStock Name\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t\t%.2f\t\t%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void buyStock() {
    printf("\nEnter stock name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("\nEnter quantity to buy: ");
            int quantity;
            scanf("%d", &quantity);
            if (quantity <= stocks[i].quantity) {
                stocks[i].quantity -= quantity;
                printf("\n%d shares of %s bought successfully!\n", quantity, name);
            } else {
                printf("\nNot enough shares available.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStock not found.\n");
    }
}

void sellStock() {
    printf("\nEnter stock name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("\nEnter quantity to sell: ");
            int quantity;
            scanf("%d", &quantity);
            if (quantity <= stocks[i].quantity) {
                stocks[i].quantity -= quantity;
                printf("\n%d shares of %s sold successfully!\n", quantity, name);
            } else {
                printf("\nNot enough shares available.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStock not found.\n");
    }
}

int main() {
    srand(time(NULL));
    printf("\nWelcome to the Stock Market Tracker!\n");
    printf("------------------------------------\n");
    printf("Please choose an option:\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Buy Stock\n");
    printf("4. Sell Stock\n");
    printf("5. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addStock();
            break;
        case 2:
            displayStocks();
            break;
        case 3:
            buyStock();
            break;
        case 4:
            sellStock();
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice.\n");
    }
    return 0;
}
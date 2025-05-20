//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char name[50];
    double price;
    int quantity;
} Stock;

void buyStock(Stock* stock, double price, int quantity) {
    printf("Buying %d units of %s at $%.2f\n", quantity, stock->name, price);
    stock->quantity += quantity;
}

void sellStock(Stock* stock, double price, int quantity) {
    printf("Selling %d units of %s at $%.2f\n", quantity, stock->name, price);
    stock->quantity -= quantity;
}

void displayStock(Stock* stock) {
    printf("Name: %s\n", stock->name);
    printf("Price: $%.2f\n", stock->price);
    printf("Quantity: %d\n", stock->quantity);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int choice, quantity;
    double price;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the name of the stock you wish to track:\n");
    scanf("%s", stocks[0].name);
    stocks[0].price = 0.0;
    stocks[0].quantity = 0;

    while(1) {
        printf("\n");
        printf("1. Buy Stock\n");
        printf("2. Sell Stock\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the price at which you want to buy %s:\n", stocks[0].name);
                scanf("%lf", &price);
                printf("Enter the quantity of %s you want to buy:\n", stocks[0].name);
                scanf("%d", &quantity);
                buyStock(&stocks[0], price, quantity);
                break;

            case 2:
                printf("Enter the price at which you want to sell %s:\n", stocks[0].name);
                scanf("%lf", &price);
                printf("Enter the quantity of %s you want to sell:\n", stocks[0].name);
                scanf("%d", &quantity);
                sellStock(&stocks[0], price, quantity);
                break;

            case 3:
                displayStock(&stocks[0]);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_COMPANIES 100

struct company {
    char name[50];
    char symbol[10];
    float price;
};

struct stock {
    struct company company;
    int quantity;
};

struct stock portfolio[MAX_STOCKS];
int num_stocks;

void add_stock() {
    if (num_stocks >= MAX_STOCKS) {
        printf("Sorry, your portfolio is full!\n");
        return;
    }

    printf("Enter the company name: ");
    scanf("%s", &portfolio[num_stocks].company.name);

    printf("Enter the company symbol: ");
    scanf("%s", &portfolio[num_stocks].company.symbol);

    printf("Enter the current stock price: ");
    scanf("%f", &portfolio[num_stocks].company.price);

    printf("Enter the number of shares you own: ");
    scanf("%d", &portfolio[num_stocks].quantity);

    num_stocks++;
}

void display_portfolio() {
    printf("\nYour Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s) - %d shares @ $%.2f\n",
               portfolio[i].company.name,
               portfolio[i].company.symbol,
               portfolio[i].quantity,
               portfolio[i].company.price);
    }
}

int main() {
    int choice;
    char company_name[50];

    do {
        printf("\nWelcome to the Stock Market Tracker!\n");
        printf("Please choose an option:\n");
        printf("1. Add a stock to your portfolio\n");
        printf("2. Display your portfolio\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_stock();
            break;

        case 2:
            display_portfolio();
            break;

        case 3:
            printf("Thanks for using the Stock Market Tracker! Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice!= 3);

    return 0;
}
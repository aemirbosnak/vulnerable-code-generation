//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void display_menu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add a Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

void add_stock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    (*count)++;
    printf("Stock added successfully!\n");
}

void update_stock_price(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    float new_price;
    int found = 0;

    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new price for %s: ", name);
            scanf("%f", &new_price);
            stocks[i].price = new_price;
            printf("Price updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Stock not found!\n");
    }
}

void view_stocks(Stock stocks[], int count) {
    printf("\n--- Current Stocks ---\n");
    if (count == 0) {
        printf("No stocks available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Stock Name: %s, Price: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                update_stock_price(stocks, count);
                break;
            case 3:
                view_stocks(stocks, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
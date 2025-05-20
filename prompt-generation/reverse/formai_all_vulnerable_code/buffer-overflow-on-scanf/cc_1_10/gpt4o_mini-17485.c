//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

void add_stock(Stock *portfolio, int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Oh no! You've reached the maximum number of stocks (%d) in your portfolio!\n", MAX_STOCKS);
        return;
    }

    printf("🎉 Adding a new stock to your portfolio! 🎉\n");
    printf("Enter the stock name: ");
    scanf("%s", portfolio[*count].name);
    
    printf("Enter the stock price: ");
    scanf("%f", &portfolio[*count].price);
    
    printf("✨ Stock '%s' added at price $%.2f! ✨\n", portfolio[*count].name, portfolio[*count].price);
    (*count)++;
}

void display_stocks(Stock *portfolio, int count) {
    if (count == 0) {
        printf("Your portfolio is empty! 📉 Let's add some stocks!\n");
        return;
    }
    
    printf("\n📊 Your Stock Portfolio 📈\n");
    for (int i = 0; i < count; i++) {
        printf("Stock: %s | Price: $%.2f\n", portfolio[i].name, portfolio[i].price);
    }
}

void update_stock(Stock *portfolio, int count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name you want to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            printf("Updating the stock price for '%s'. Enter the new price: ", name);
            scanf("%f", &portfolio[i].price);
            printf("🎉 Stock '%s' updated to $%.2f! 🎉\n", name, portfolio[i].price);
            return;
        }
    }
    
    printf("😢 Stock '%s' was not found in your portfolio.\n", name);
}

void delete_stock(Stock *portfolio, int *count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name you want to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                portfolio[j] = portfolio[j + 1];
            }
            (*count)--;
            printf("🚀 Stock '%s' has been successfully deleted from your portfolio! 🚀\n", name);
            return;
        }
    }
    
    printf("😞 Stock '%s' could not be found, nothing was deleted.\n", name);
}

int main() {
    Stock portfolio[MAX_STOCKS];
    int count = 0;
    int choice;

    printf("🌟 Welcome to Your Enthusiastic Stock Market Tracker! 🌟\n");

    do {
        printf("\n📋 Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Delete Stock\n");
        printf("5. Exit\n");
        printf("Choose your option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(portfolio, &count);
                break;
            case 2:
                display_stocks(portfolio, count);
                break;
            case 3:
                update_stock(portfolio, count);
                break;
            case 4:
                delete_stock(portfolio, &count);
                break;
            case 5:
                printf("🚪 Thanks for using the Stock Market Tracker! Goodbye! 🚪\n");
                break;
            default:
                printf("🛑 Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
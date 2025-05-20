//FormAI DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char ticker[10];
    double price;
    int quantity;
} Stock;

int count = 0;
Stock stocks[MAX_STOCKS];

/* Function to add a stock to the tracker */
void addStock(char ticker[], double price, int quantity) {
    if (count == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    Stock stock;
    strcpy(stock.ticker, ticker);
    stock.price = price;
    stock.quantity = quantity;
    stocks[count++] = stock;
    printf("Stock %s added successfully.\n", ticker);
}

/* Function to remove a stock from the tracker */
void removeStock(char ticker[]) {
    int idx = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Stock not found.\n");
        return;
    }
    for (int i = idx; i < count - 1; i++) {
        stocks[i] = stocks[i+1];
    }
    count--;
    printf("Stock %s removed successfully.\n", ticker);
}

/* Function to display the portfolio and calculate its value */
void displayPortfolio() {
    double value = 0;
    printf("Ticker\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2lf\t%d\n", stocks[i].ticker, stocks[i].price, stocks[i].quantity);
        value += (stocks[i].price * stocks[i].quantity);
    }
    printf("Total value of portfolio: $%.2lf\n", value);
}

/* Function to update the price of a stock */
void updatePrice(char ticker[], double newPrice) {
    int idx = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Stock not found.\n");
        return;
    }
    stocks[idx].price = newPrice;
    printf("Price of stock %s updated to %.2lf.\n", ticker, newPrice);
}

int main() {
    int choice;
    char ticker[10];
    double price, newPrice;
    int quantity;

    /* Menu-driven interface */
    while (1) {
        printf("\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Display portfolio\n");
        printf("4. Update stock price\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticker symbol: ");
                scanf("%s", ticker);
                printf("Enter price: ");
                scanf("%lf", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addStock(ticker, price, quantity);
                break;

            case 2:
                printf("Enter ticker symbol: ");
                scanf("%s", ticker);
                removeStock(ticker);
                break;

            case 3:
                displayPortfolio();
                break;

            case 4:
                printf("Enter ticker symbol: ");
                scanf("%s", ticker);
                printf("Enter new price: ");
                scanf("%lf", &newPrice);
                updatePrice(ticker, newPrice);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
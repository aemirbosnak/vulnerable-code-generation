//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stockCount = 0;

void addStock(const char *name, float price) {
    if (stockCount < MAX_STOCKS) {
        strcpy(stocks[stockCount].name, name);
        stocks[stockCount].price = price;
        stockCount++;
        printf("Stock %s added with price %.2f\n", name, price);
    } else {
        printf("Stock list is full!\n");
    }
}

void updateStock(const char *name, float newPrice) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = newPrice;
            printf("Updated %s price to %.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void displayStocks() {
    printf("\nCurrent Stock Prices:\n");
    printf("---------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Company: %-20s Price: $%.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("---------------------\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    float price;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display All Stocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateStock(name, price);
                break;

            case 3:
                displayStocks();
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
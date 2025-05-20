//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} Stock;

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%s\n", stock.price);
    printf("Quantity: %d\n\n", stock.quantity);
}

int main() {
    // Initialize stocks
    Stock stocks[MAX_STOCKS] = {{"Apple", "AAPL", "$150.00", 100},
                                {"Amazon", "AMZN", "$3000.00", 10},
                                {"Google", "GOOG", "$1200.00", 50},
                                {"Tesla", "TSLA", "$700.00", 25},
                                {"Microsoft", "MSFT", "$200.00", 75}};

    int choice, index;

    do {
        printf("Stock Market Tracker\n");
        printf("=====================\n");
        printf("1. View Stocks\n");
        printf("2. Buy Stock\n");
        printf("3. Sell Stock\n");
        printf("4. Update Stock Price\n");
        printf("5. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (index = 0; index < MAX_STOCKS; index++) {
                if (stocks[index].quantity > 0) {
                    print_stock(stocks[index]);
                }
            }
            break;

        case 2:
            printf("Enter the name of the stock to buy: ");
            scanf("%s", stocks[0].name);
            printf("Enter the quantity to buy: ");
            scanf("%d", &stocks[0].quantity);
            break;

        case 3:
            printf("Enter the name of the stock to sell: ");
            scanf("%s", stocks[0].name);
            printf("Enter the quantity to sell: ");
            scanf("%d", &stocks[0].quantity);
            break;

        case 4:
            printf("Enter the name of the stock to update: ");
            scanf("%s", stocks[0].name);
            printf("Enter the new price: ");
            scanf("%s", stocks[0].price);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}
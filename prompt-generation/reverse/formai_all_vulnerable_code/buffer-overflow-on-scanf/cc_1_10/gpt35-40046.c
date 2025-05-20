//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char symbol[10];
    float price;
};

void print_stock_data(struct Stock stock) {
    printf("%s: %.2f\n", stock.symbol, stock.price);
}

int main() {
    struct Stock stocks[3];
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 146.08;
    strcpy(stocks[1].symbol, "GOOGL");
    stocks[1].price = 2717.69;
    strcpy(stocks[2].symbol, "MSFT");
    stocks[2].price = 290.14;

    int choice;

    do {
        printf("Please choose an option:\n");
        printf("1. View stock prices\n");
        printf("2. Add a stock\n");
        printf("3. Remove a stock\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < 3; i++) {
                    print_stock_data(stocks[i]);
                }
                break;
            case 2:
                if (sizeof(stocks) / sizeof(stocks[0]) < 10) {
                    char new_symbol[10];
                    float new_price;
                    printf("Enter new stock symbol: ");
                    scanf("%s", new_symbol);
                    printf("Enter new stock price: ");
                    scanf("%f", &new_price);

                    struct Stock new_stock;
                    strcpy(new_stock.symbol, new_symbol);
                    new_stock.price = new_price;

                    stocks[sizeof(stocks) / sizeof(stocks[0])] = new_stock;
                } else {
                    printf("You can only add up to 10 stocks.\n");
                }
                break;
            case 3:
                printf("Enter the symbol of the stock you want to remove: ");
                char symbol_to_remove[10];
                scanf("%s", symbol_to_remove);

                int index_to_remove = -1;

                for (int i = 0; i < sizeof(stocks) / sizeof(stocks[0]); i++) {
                    if (strcmp(stocks[i].symbol, symbol_to_remove) == 0) {
                        index_to_remove = i;
                        break;
                    }
                }

                if (index_to_remove != -1) {
                    for (int i = index_to_remove; i < sizeof(stocks) / sizeof(stocks[0]) - 1; i++) {
                        stocks[i] = stocks[i + 1];
                    }
                    memset(&stocks[sizeof(stocks) / sizeof(stocks[0]) - 1], 0, sizeof(struct Stock));
                } else {
                    printf("Stock with symbol %s not found.\n", symbol_to_remove);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}
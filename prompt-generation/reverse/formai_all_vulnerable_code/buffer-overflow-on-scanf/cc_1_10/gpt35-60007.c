//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char name[20];
    float price;
};

void updatePrice(struct Stock *s, float newPrice) {
    s->price = newPrice;
}

int main() {
    struct Stock stockList[5];
    int numShares = 0;

    // initialize stock names and starting prices
    strcpy(stockList[0].name, "AAPL");
    stockList[0].price = 148.48;

    strcpy(stockList[1].name, "GOOG");
    stockList[1].price = 2728.27;

    strcpy(stockList[2].name, "MSFT");
    stockList[2].price = 298.27;

    strcpy(stockList[3].name, "AMZN");
    stockList[3].price = 3272.35;

    strcpy(stockList[4].name, "TSLA");
    stockList[4].price = 711.92;

    // display initial stock prices
    printf("Stock Prices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f\n", stockList[i].name, stockList[i].price);
    }

    // menu options for user
    int choice;
    do {
        printf("\nMenu\n");
        printf("1. Buy Shares\n");
        printf("2. Sell Shares\n");
        printf("3. Update Stock Prices\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the stock name: ");
                char stockName[20];
                scanf("%s", stockName);
                printf("Enter the number of shares you would like to buy: ");
                scanf("%d", &numShares);

                // search for stock name in array
                int found = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(stockName, stockList[i].name) == 0) {
                        found = 1;
                        float totalPrice = numShares * stockList[i].price;
                        printf("You have bought %d shares of %s for $%.2f\n", numShares, stockList[i].name, totalPrice);
                        break;
                    }
                }
                if (!found) {
                    printf("Stock not found\n");
                }
                break;
            case 2:
                printf("Enter the stock name: ");
                char stockName2[20];
                scanf("%s", stockName2);
                printf("Enter the number of shares you would like to sell: ");
                scanf("%d", &numShares);

                // search for stock name in array
                found = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(stockName2, stockList[i].name) == 0) {
                        found = 1;
                        float totalPrice = numShares * stockList[i].price;
                        printf("You have sold %d shares of %s for $%.2f\n", numShares, stockList[i].name, totalPrice);
                        break;
                    }
                }
                if (!found) {
                    printf("Stock not found\n");
                }
                break;
            case 3:
                printf("Enter the stock name: ");
                char stockName3[20];
                scanf("%s", stockName3);
                printf("Enter the new stock price: ");
                float newPrice;
                scanf("%f", &newPrice);

                // search for stock name in array and update price
                found = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(stockName3, stockList[i].name) == 0) {
                        found = 1;
                        updatePrice(&stockList[i], newPrice);
                        printf("Stock price updated.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Stock not found\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
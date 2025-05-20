//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

struct Stock {
    int id;
    char symbol[10];
    float price;
};

int main() {
    struct Stock stocks[MAX_STOCKS] = {
        {1, "AAPL", 148.48},
        {2, "GOOG", 2712.33},
        {3, "TSLA", 680.76},
        {4, "AMZN", 3372.20},
        {5, "FB", 357.60}
    };
    int numStocks = 5;

    //Display initial stock data
    printf("Stock Market Tracker\n\n");
    printf("ID\tSymbol\tPrice\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%d\t%s\t%.2f\n", stocks[i].id, stocks[i].symbol, stocks[i].price);
    }

    //Allow user to update stock prices
    char choice = 'y';
    while (choice == 'y') {
        printf("\nEnter the ID of the stock you would like to update: ");
        int id;
        scanf("%d", &id);

        int index = -1;
        for (int i = 0; i < numStocks; i++) {
            if (stocks[i].id == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            printf("\nInvalid ID entered.");
        }
        else {
            printf("Enter the new stock price: ");
            float price;
            scanf("%f", &price);
            stocks[index].price = price;
            printf("\nNew stock data:\n");
            printf("Symbol\tPrice\n");
            printf("%s\t%.2f\n", stocks[index].symbol, stocks[index].price);
        }

        printf("\nWould you like to update another stock? (y/n): ");
        fflush(stdin);
        scanf("%c", &choice);
        if (choice != 'y' && choice != 'n') {
            printf("\nInvalid choice entered. Exiting program.");
            return 1;
        }
    }

    //Display updated stock data
    printf("\nUpdated stock data:\n");
    printf("ID\tSymbol\tPrice\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%d\t%s\t%.2f\n", stocks[i].id, stocks[i].symbol, stocks[i].price);
    }
    return 0;
}
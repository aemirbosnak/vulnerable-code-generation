//FormAI DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 20
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    float price;
    int quantity;
} Stock;

void updatePrice(Stock *s) {
    float percentageChange = ((float)rand() / RAND_MAX) * 10 - 5;
    s->price *= (1 + percentageChange / 100);
}

int main() {
    srand(time(NULL));
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];

    printf("\nWelcome to the Stock Market Tracker!\n");

    while (1) {
        printf("\nSelect an option:\n1 - Add stock\n2 - Update prices\n3 - View stocks\n0 - Exit\n");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("\nThank you for using the Stock Market Tracker!\n");
                exit(0);
            case 1:
                if (numStocks == MAX_STOCKS) {
                    printf("\nError: Maximum number of stocks reached.\n");
                    break;
                }

                Stock newStock;
                printf("\nEnter stock name:\n");
                scanf("%s", newStock.name);
                printf("Enter stock price:\n");
                scanf("%f", &newStock.price);
                printf("Enter stock quantity:\n");
                scanf("%d", &newStock.quantity);

                stocks[numStocks++] = newStock;

                printf("\nSuccess: Stock added to the tracker.\n");
                break;
            case 2:
                for (int i = 0; i < numStocks; i++) {
                    updatePrice(&stocks[i]);
                }

                printf("\nSuccess: Prices updated.\n");
                break;
            case 3:
                printf("\n--- Stock Tracker ---\n");

                for (int i = 0; i < numStocks; i++) {
                    printf("Stock %d: %s, Price: %.2f, Quantity: %d\n", i + 1, stocks[i].name, stocks[i].price, stocks[i].quantity);
                }

                printf("----------------------\n");

                break;
            default:
                printf("\nError: Invalid option selected.\n");
                break;
        }
    }
  
    return 0;
}
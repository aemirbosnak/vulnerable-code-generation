//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int volume;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    if (numStocks == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    Stock newStock;

    printf("Enter the name of the new stock: ");
    scanf("%s", newStock.name);

    printf("Enter the price of the new stock: ");
    scanf("%lf", &newStock.price);

    printf("Enter the volume of the new stock: ");
    scanf("%d", &newStock.volume);

    stocks[numStocks] = newStock;
    numStocks++;

    printf("New stock \"%s\" added.\n", newStock.name);
}

void removeStock() {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to remove: ");
    scanf("%s", stockName);

    int i;
    for (i = 0; i < numStocks; i++) {
        if (strcmp(stockName, stocks[i].name) == 0) {
            printf("Removing stock \"%s\" with price %.2lf and volume %d.\n", stocks[i].name, stocks[i].price, stocks[i].volume);

            int j;
            for (j = 0; j < numStocks - 1; j++) {
                stocks[j] = stocks[j + 1];
            }

            numStocks--;

            return;
        }
    }

    printf("Stock \"%s\" not found.\n", stockName);
}

void displayStocks() {
    printf("Stocks:\n");

    int i;
    for (i = 0; i < numStocks; i++) {
        printf("%s ($%.2lf) - Volume: %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Display stocks\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                removeStock();
                break;
            case 3:
                displayStocks();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
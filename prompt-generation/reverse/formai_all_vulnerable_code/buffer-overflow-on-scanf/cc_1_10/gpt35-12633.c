//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME 20
#define MAX_DATAPTS 50

typedef struct stocks {
    char name[MAX_STOCK_NAME];
    float price[MAX_DATAPTS];
    int datapts;
} Stocks;

Stocks stock[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    char name[MAX_STOCK_NAME];
    int i, j, flag;
    float price;
    int datapts;

    printf("Enter name of stock: ");
    scanf("%s", name);

    // check if stock already exists
    for (i = 0; i < numStocks; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("%s is already in the system.\n", name);
            printf("Please update the stock instead.\n");
            return;
        }
    }

    printf("Enter number of data points: ");
    scanf("%d", &datapts);

    if (datapts > MAX_DATAPTS) {
        printf("Maximum number of data points exceeded.\n");
        return;
    } else if (datapts < 1) {
        printf("Invalid number of data points.\n");
        return;
    }

    stock[numStocks].datapts = datapts;
    strcpy(stock[numStocks].name, name);

    printf("Enter prices (separated by space):\n");

    for (i = 0; i < datapts; i++) {
        scanf("%f", &price);
        stock[numStocks].price[i] = price;
    }

    numStocks++;

    printf("Stock successfully added!\n");
}

void updateStock() {
    char name[MAX_STOCK_NAME];
    int i, j, flag;
    float price;
    int datapts;

    printf("Enter name of stock: ");
    scanf("%s", name);

    for (i = 0; i < numStocks; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Enter new prices (separated by space):\n");

            for (j = 0; j < stock[i].datapts; j++) {
                scanf("%f", &price);
                stock[i].price[j] = price;
            }

            printf("%s updated successfully!\n", name);
            return;
        }
    }

    printf("%s not found in the system.\n", name);
}

void getStats() {
    char name[MAX_STOCK_NAME];
    int i, j, flag;
    float min, max, sum, avg;
    int datapts;

    printf("Enter name of stock: ");
    scanf("%s", name);

    for (i = 0; i < numStocks; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            min = stock[i].price[0];
            max = stock[i].price[0];
            sum = stock[i].price[0];

            for (j = 1; j < stock[i].datapts; j++) {
                if (stock[i].price[j] < min) {
                    min = stock[i].price[j];
                }

                if (stock[i].price[j] > max) {
                    max = stock[i].price[j];
                }

                sum += stock[i].price[j];
            }

            avg = sum / stock[i].datapts;

            printf("Statistics for %s:\n", stock[i].name);
            printf("Minimum price: %.2f\n", min);
            printf("Maximum price: %.2f\n", max);
            printf("Sum of prices: %.2f\n", sum);
            printf("Average price: %.2f\n", avg);
            return;
        }
    }

    printf("%s not found in the system.\n", name);
}

void displayStocks() {
    int i, j;

    if (numStocks == 0) {
        printf("No stocks in the system.\n");
        return;
    }

    for (i = 0; i < numStocks; i++) {
        printf("%s: ", stock[i].name);

        for (j = 0; j < stock[i].datapts; j++) {
            printf("%.2f ", stock[i].price[j]);
        }

        printf("\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the stock market tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add stock\n");
        printf("2. Update stock\n");
        printf("3. Get statistics\n");
        printf("4. Display stocks\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                getStats();
                break;
            case 4:
                displayStocks();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
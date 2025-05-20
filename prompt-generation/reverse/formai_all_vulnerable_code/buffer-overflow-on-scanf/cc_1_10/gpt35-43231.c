//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NAME_LENGTH 50
#define MAX_STOCKS_TO_TRACK 10
#define MAX_DATA_POINTS 100

/* Defining a struct to hold Stock data */
struct Stock {
    char name[MAX_STOCK_NAME_LENGTH];
    float data[MAX_DATA_POINTS];
    int data_count;
};

/* Function to create a new stock */
void createStock(struct Stock *stocks, int *stock_count) {
    printf("Enter the stock name: ");
    fgets(stocks[*stock_count].name, MAX_STOCK_NAME_LENGTH, stdin);
    printf("Enter the data points (separated by spaces): ");
    int i = 0;
    while (scanf("%f", &(stocks[*stock_count].data[i])) != EOF && i < MAX_DATA_POINTS) {
        i++;
    }
    stocks[*stock_count].data_count = i;
    (*stock_count)++;
}

/* Function to print all stock data */
void printStocks(struct Stock *stocks, int stock_count) {
    for (size_t i = 0; i < stock_count; i++) {
        printf("%s data: ", stocks[i].name);
        for (size_t j = 0; j < stocks[i].data_count; j++) {
            printf("%.2f ", stocks[i].data[j]);
        }
        printf("\n");
    }
}

/* Function to calculate the average stock value */
float averageStockValue(struct Stock stock) {
    float total = 0;
    for (size_t i = 0; i < stock.data_count; i++) {
        total += stock.data[i];
    }
    return total / stock.data_count;
}

/* Function to print the average stock value for all stocks */
void printAverageStockValue(struct Stock *stocks, int stock_count) {
    for (size_t i = 0; i < stock_count; i++) {
        printf("%s average value: %.2f\n", stocks[i].name, averageStockValue(stocks[i]));
    }
}

/* main function */
int main() {
    struct Stock stocks[MAX_STOCKS_TO_TRACK];
    int stock_count = 0;
    int option;

    do {
        printf("\n1. Create new stock\n");
        printf("2. Print all stock data\n");
        printf("3. Print average stock value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createStock(stocks, &stock_count);
                break;
            case 2:
                printStocks(stocks, stock_count);
                break;
            case 3:
                printAverageStockValue(stocks, stock_count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 4);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10
#define MAX_STOCK_NAME_LEN 20

typedef struct Stock {
    char name[MAX_STOCK_NAME_LEN];
    int num;
    double price;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void update_stock(int index, double new_price) {
    stocks[index].price = new_price;
}

int main() {

    // Initialize the stock list
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        stocks[i].num = -1;
    }

    // Get the stock name and price from the user
    char stock_name[MAX_STOCK_NAME_LEN];
    double stock_price;
    printf("Enter the name of the stock: ");
    scanf("%s", stock_name);

    printf("Enter the price of the stock: ");
    scanf("%lf", &stock_price);

    // Find the stock in the list
    int index = -1;
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            index = i;
            break;
        }
    }

    // If the stock is found, update its price
    if (index != -1) {
        update_stock(index, stock_price);
        printf("Stock price updated.\n");
    } else {
        // If the stock is not found, add it to the list
        index = MAX_STOCK_NUM - 1;
        stocks[index].num = MAX_STOCK_NUM - 1;
        strcpy(stocks[index].name, stock_name);
        stocks[index].price = stock_price;
        printf("Stock added.\n");
    }

    // Print the updated stock list
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        if (stocks[i].num != -1) {
            printf("%s: %.2lf\n", stocks[i].name, stocks[i].price);
        }
    }

    return 0;
}
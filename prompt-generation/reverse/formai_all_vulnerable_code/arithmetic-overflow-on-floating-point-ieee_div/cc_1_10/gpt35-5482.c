//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME 25

typedef struct Stock {
    char name[MAX_NAME];
    float price;
    float change;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

/**
  * Function to add a stock to the list of stocks.
  * @param name name of the stock
  * @param price current price of the stock
  * @param change percentage change in the stock price
  */
void addStock(char* name, float price, float change) {
    if (numStocks < MAX_STOCKS) {
        Stock s;
        strcpy(s.name, name);
        s.price = price;
        s.change = change;
        stocks[numStocks] = s;
        numStocks++;
    } else {
        printf("Maximum number of stocks reached.\n");
    }
}

/**
  * Function to update the price and percentage change of a stock.
  * @param index the index of the stock to update
  * @param price the new price of the stock
  */
void updateStock(int index, float price) {
    if (index < numStocks) {
        float oldPrice = stocks[index].price;
        stocks[index].change = ((price - oldPrice) / oldPrice) * 100;
        stocks[index].price = price;
    } else {
        printf("Invalid stock index.\n");
    }
}

/**
  * Function to display all of the stocks in the list.
  */
void displayStocks() {
    printf("Name \t\t Price \t\t Change\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-15s %10.2f %10.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

/**
  * Function to convert a string to uppercase.
  * @param str string to convert
  */
void toUpper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    // Adding sample stocks to the list
    addStock("APPLE", 145.44, 0.55);
    addStock("AMAZON", 3244.99, -1.23);
    addStock("TESLA", 655.44, 2.22);

    char command[10];
    while (1) {
        printf("\nEnter a command (ADD, UPDATE, DISPLAY or QUIT): ");
        scanf("%s", command);
        toUpper(command);

        if (strcmp(command, "ADD") == 0) {
            char name[MAX_NAME];
            float price;
            float change;
            printf("Enter the name of the stock to add: ");
            scanf("%s", name);
            printf("Enter the current price of the stock: ");
            scanf("%f", &price);
            printf("Enter the percentage change in the stock price: ");
            scanf("%f", &change);
            addStock(name, price, change);
        } else if (strcmp(command, "UPDATE") == 0) {
            int index;
            float price;
            printf("Enter the index of the stock to update: ");
            scanf("%d", &index);
            printf("Enter the new price of the stock: ");
            scanf("%f", &price);
            updateStock(index, price);
        } else if (strcmp(command, "DISPLAY") == 0) {
            displayStocks();
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
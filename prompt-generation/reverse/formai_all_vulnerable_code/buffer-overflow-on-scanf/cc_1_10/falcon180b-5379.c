//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for a stock
typedef struct {
    char symbol[10];
    float price;
    int quantity;
} Stock;

// Function to compare two stocks based on their prices
int compare(const void *a, const void *b) {
    Stock *stockA = (Stock *)a;
    Stock *stockB = (Stock *)b;

    if (stockA->price > stockB->price)
        return 1;
    else if (stockA->price < stockB->price)
        return -1;
    else
        return 0;
}

// Function to sort an array of stocks based on their prices
void sort(Stock stocks[], int n) {
    qsort(stocks, n, sizeof(Stock), compare);
}

// Function to display the current state of the stock market
void display(Stock stocks[], int n) {
    printf("Current state of the stock market:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-10.2f %10d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
    printf("-------------------------------------------------\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    Stock stocks[n];

    // Read in the initial state of the stock market
    printf("Enter the initial state of the stock market:\n");
    for (int i = 0; i < n; i++) {
        printf("Stock %d:\n", i + 1);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%f", &stocks[i].price);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    // Simulate the stock market
    int m;
    printf("Enter the number of transactions: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Transaction %d:\n", i + 1);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%f", &stocks[i].price);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    // Sort the stocks based on their prices
    sort(stocks, n);

    // Display the current state of the stock market
    display(stocks, n);

    return 0;
}
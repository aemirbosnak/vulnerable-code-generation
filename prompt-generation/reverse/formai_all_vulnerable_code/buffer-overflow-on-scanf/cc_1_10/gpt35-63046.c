//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10 // Maximum number of stocks supported
#define MAX_NAME_LENGTH 20 // Maximum length of a stock name

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

int numStocks = 0;
Stock stocks[MAX_STOCKS];

void addStock() {
    printf("Enter stock name: ");
    scanf("%s", stocks[numStocks].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[numStocks].price);
    numStocks++;
}

void deleteStock() {
    if (numStocks == 0) {
        printf("No stocks to delete\n");
        return;
    }
    int index;
    printf("Enter stock index to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= numStocks) {
        printf("Invalid index\n");
    } else {
        for (int i = index; i < numStocks - 1; i++) {
            stocks[i] = stocks[i+1];
        }
        numStocks--;
    }
}

void printStocks() {
    printf("Current stocks:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%d. %s: $%.2f\n", i, stocks[i].name, stocks[i].price);
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add stock\n");
        printf("2. Delete stock\n");
        printf("3. View stocks\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                deleteStock();
                break;
            case 3:
                printStocks();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    printf("Goodbye!\n");
    return 0;
}
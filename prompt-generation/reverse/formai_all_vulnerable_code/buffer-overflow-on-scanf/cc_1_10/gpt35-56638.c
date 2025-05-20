//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    float change;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    if (numStocks == MAX_STOCKS) {
        printf("ERROR: Maximum number of stocks reached!\n");
        return;
    }

    printf("Enter the stock name: ");
    fgets(stocks[numStocks].name, MAX_NAME_LEN, stdin);
    stocks[numStocks].name[strcspn(stocks[numStocks].name, "\n")] = '\0'; // remove the newline character from the input

    printf("Enter the stock price: ");
    scanf("%f", &stocks[numStocks].price);

    printf("Enter the stock change: ");
    scanf("%f", &stocks[numStocks].change);

    printf("%s stock added to the tracker!\n", stocks[numStocks].name);

    numStocks++;
}

void displayStocks() {
    if (numStocks == 0) {
        printf("No stocks available in the tracker!\n");
        return;
    }

    printf("%-20s %-10s %-10s\n", "Name", "Price", "Change");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %-10.2f %-10.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStocks() {
    if (numStocks == 0) {
        printf("No stocks available in the tracker to update!\n");
        return;
    }

    printf("Enter the name of the stock to update: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the newline character from the input

    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter the new stock price: ");
            scanf("%f", &stocks[i].price);

            printf("Enter the new stock change: ");
            scanf("%f", &stocks[i].change);

            printf("%s stock updated successfully!\n", stocks[i].name);
            return;
        }
    }

    printf("ERROR: Stock not found in the tracker!\n");
}

void removeStock() {
    if (numStocks == 0) {
        printf("No stocks available in the tracker to remove!\n");
        return;
    }

    printf("Enter the name of the stock to remove: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the newline character from the input

    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < numStocks - 1; j++) {
                stocks[j] = stocks[j + 1];
            }

            numStocks--;
            printf("%s stock removed from the tracker!\n", name);
            return;
        }
    }

    printf("ERROR: Stock not found in the tracker!\n");
}

void updatePriceChanges() {
    srand(time(NULL)); // seed the random number generator with the current time
    printf("Updating the stock price changes...\n");

    for (int i = 0; i < numStocks; i++) {
        float change = ((float)rand() / (float)RAND_MAX) * 0.2 - 0.1; // generate a random number between -0.1 and 0.1
        stocks[i].change = change;
        stocks[i].price += change * stocks[i].price;
    }

    printf("Stock prices updated successfully!\n");
}

int main() {
    char option;

    do {
        printf("\n");
        printf("Enter your option:\n");
        printf("1. Add a new stock to the tracker\n");
        printf("2. Display all the stocks in the tracker\n");
        printf("3. Update a stock in the tracker\n");
        printf("4. Remove a stock from the tracker\n");
        printf("5. Update the price changes of all the stocks in the tracker\n");
        printf("6. Quit\n");

        scanf("%c", &option);
        getchar(); // remove the newline character from the input

        switch (option) {
            case '1':
                addStock();
                break;

            case '2':
                displayStocks();
                break;

            case '3':
                updateStocks();
                break;

            case '4':
                removeStock();
                break;

            case '5':
                updatePriceChanges();
                break;

            case '6':
                printf("Goodbye!\n");
                break;

            default:
                printf("ERROR: Invalid option! Try again.\n");
                break;
        }
    } while (option != '6');

    return 0;
}
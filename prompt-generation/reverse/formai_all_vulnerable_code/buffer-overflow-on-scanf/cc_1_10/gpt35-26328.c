//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STOCKS 100

typedef struct {
    char ticker[10];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

void displayMenu();
void addStock();
void updateStockPrice();
void deleteStock();
void listStocks();
void searchStocks();
void sortStocksByTicker();
void sortStocksByPrice();
void exitProgram();

int main() {
    char choice;

    do {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addStock();
                break;
            case '2':
                updateStockPrice();
                break;
            case '3':
                deleteStock();
                break;
            case '4':
                listStocks();
                break;
            case '5':
                searchStocks();
                break;
            case '6':
                sortStocksByTicker();
                break;
            case '7':
                sortStocksByPrice();
                break;
            case '8':
                exitProgram();
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != '8');

    return 0;
}

void displayMenu() {
    printf("\nC STOCK MARKET TRACKER\n");
    printf("----------------------\n");
    printf("1. Add new stock\n");
    printf("2. Update stock price\n");
    printf("3. Delete stock\n");
    printf("4. List all stocks\n");
    printf("5. Search stocks\n");
    printf("6. Sort stocks by ticker symbol\n");
    printf("7. Sort stocks by price\n");
    printf("8. Exit program\n");
    printf("Enter your choice: ");
}

void addStock() {
    if (numStocks == MAX_STOCKS) {
        printf("Maximum stocks limit reached, cannot add new stock.\n");
        return;
    }

    printf("\nEnter ticker symbol: ");
    scanf("%s", stocks[numStocks].ticker);
    printf("Enter stock price: ");
    scanf("%f", &stocks[numStocks].price);

    numStocks++;
    printf("Stock added successfully.\n");
}

void updateStockPrice() {
    char ticker[10];
    bool found = false;
    int i;

    printf("\nEnter ticker symbol to update: ");
    scanf("%s", ticker);

    for (i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            found = true;
            printf("Enter new stock price: ");
            scanf("%f", &stocks[i].price);
            printf("Stock price updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Stock with ticker symbol %s not found.\n", ticker);
    }
}

void deleteStock() {
    char ticker[10];
    bool found = false;
    int i;

    printf("\nEnter ticker symbol to delete: ");
    scanf("%s", ticker);

    for (i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            found = true;
            numStocks--;
            if (i == numStocks) {
                printf("Stock with ticker symbol %s deleted successfully.\n", ticker);
                break;
            } else {
                strcpy(stocks[i].ticker, stocks[numStocks].ticker);
                stocks[i].price = stocks[numStocks].price;
                printf("Stock with ticker symbol %s deleted successfully.\n", ticker);
                break;
            }
        }
    }

    if (!found) {
        printf("Stock with ticker symbol %s not found.\n", ticker);
    }
}

void listStocks() {
    int i;

    if (numStocks == 0) {
        printf("\nNo stocks to show.\n");
        return;
    }

    printf("\n%-10s%-10s\n", "Ticker", "Price");
    printf("------------------\n");
    for (i = 0; i < numStocks; i++) {
        printf("%-10s%-10.2f\n", stocks[i].ticker, stocks[i].price);
    }
}

void searchStocks() {
    char ticker[10];
    bool found = false;
    int i;

    printf("\nEnter ticker symbol to search: ");
    scanf("%s", ticker);

    for (i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            found = true;
            printf("\n%s stock found.\n", stocks[i].ticker);
            printf("Ticker        : %s\n", stocks[i].ticker);
            printf("Price         : %.2f\n", stocks[i].price);
            break;
        }
    }

    if (!found) {
        printf("Stock with ticker symbol %s not found.\n", ticker);
    }
}

void sortStocksByTicker() {
    int i, j;
    Stock temp;

    if (numStocks == 0) {
        printf("\nNo stocks to show.\n");
        return;
    }

    for (i = 0; i < numStocks - 1; i++) {
        for (j = i + 1; j < numStocks; j++) {
            if (strcmp(stocks[i].ticker, stocks[j].ticker) > 0) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }

    printf("\nStocks sorted by ticker symbol.\n");
}

void sortStocksByPrice() {
    int i, j;
    Stock temp;

    if (numStocks == 0) {
        printf("\nNo stocks to show.\n");
        return;
    }

    for (i = 0; i < numStocks - 1; i++) {
        for (j = i + 1; j < numStocks; j++) {
            if (stocks[i].price > stocks[j].price) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }

    printf("\nStocks sorted by price.\n");
}

void exitProgram() {
    printf("\nThank you for using C STOCK MARKET TRACKER.\n");
    exit(0);
}
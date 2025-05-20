//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char name[20];
    int quantity;
    float price;
    float change;
    float percentChange;
} Stock;

void clearScreen() {
    system("cls||clear");
}

void printMenu() {
    printf("\n Stock Market Tracker\n");
    printf(" -----------------------------\n");
    printf(" 1. Add Stock\n");
    printf(" 2. Remove Stock\n");
    printf(" 3. Update Stock Price\n");
    printf(" 4. Display All Stocks\n");
    printf(" 5. Exit\n");
    printf(" -----------------------------\n");
}

int isValidStock(Stock stocks[], char name[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int getStockIndex(Stock stocks[], char name[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addStock(Stock stocks[], int *count) {
    char name[20];
    int quantity;
    float price;

    if (*count == MAX_STOCKS) {
        printf(" Maximum number of stocks reached\n");
        return;
    }

    printf(" Enter stock name: ");
    scanf("%s", name);

    if (isValidStock(stocks, name)) {
        printf(" Stock already exists\n");
        return;
    }

    printf(" Enter quantity: ");
    scanf("%d", &quantity);

    printf(" Enter price: ");
    scanf("%f", &price);

    strcpy(stocks[*count].name, name);
    stocks[*count].quantity = quantity;
    stocks[*count].price = price;
    stocks[*count].change = 0;
    stocks[*count].percentChange = 0;

    printf(" Stock added successfully\n");

    (*count)++;
}

void removeStock(Stock stocks[], int *count) {
    char name[20];

    printf(" Enter stock name: ");
    scanf("%s", name);

    int index = getStockIndex(stocks, name);

    if (index == -1) {
        printf(" Stock not found\n");
        return;
    }

    for (int i = index; i < *count-1; i++) {
        stocks[i] = stocks[i+1];
    }

    printf(" Stock removed successfully\n");

    (*count)--;
}

void updateStockPrice(Stock stocks[], int count) {
    char name[20];
    float price;

    printf(" Enter stock name: ");
    scanf("%s", name);

    int index = getStockIndex(stocks, name);

    if (index == -1) {
        printf(" Stock not found\n");
        return;
    }

    printf(" Enter new price: ");
    scanf("%f", &price);

    float oldPrice = stocks[index].price;
    stocks[index].price = price;
    stocks[index].change = price - oldPrice;
    stocks[index].percentChange = (price - oldPrice) / oldPrice * 100;

    printf(" Price updated successfully\n");
}

void displayAllStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf(" No stocks added yet\n");
        return;
    }

    printf("\n %-10s %-10s %-10s %-10s %-10s\n", "Name", "Quantity", "Price", "Change", "% Change");

    for (int i = 0; i < count; i++) {
        printf(" %-10s %-10d %-10.2f ", stocks[i].name, stocks[i].quantity, stocks[i].price);

        if (stocks[i].change > 0) {
            printf("+%.2f   ", stocks[i].change);
        } else {
            printf("%.2f   ", stocks[i].change);
        }

        if (stocks[i].percentChange > 0) {
            printf("+%.2f%%\n", stocks[i].percentChange);
        } else {
            printf("%.2f%%\n", stocks[i].percentChange);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice = 0;

    while (choice != 5) {
        clearScreen();
        printMenu();

        printf(" Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                removeStock(stocks, &count);
                break;
            case 3:
                updateStockPrice(stocks, count);
                break;
            case 4:
                displayAllStocks(stocks, count);
                break;
            case 5:
                printf(" Thank you for using the stock market tracker\n");
                break;
            default:
                printf(" Invalid choice\n");
                break;
        }

        printf("\n Press enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int numStocks;
} StockTracker;

void addStock(StockTracker* tracker, char name[], float price) {
    if (tracker->numStocks < MAX_STOCKS) {
        strcpy(tracker->stocks[tracker->numStocks].name, name);
        tracker->stocks[tracker->numStocks].price = price;
        tracker->numStocks++;
        printf("%s stock added\n", name);
    }
    else {
        printf("Maximum number of stocks reached\n");
    }
}

void removeStock(StockTracker* tracker, char name[]) {
    int index = -1;
    for (int i = 0; i < tracker->numStocks; i++) {
        if (strcmp(tracker->stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < tracker->numStocks-1; i++) {
            strcpy(tracker->stocks[i].name, tracker->stocks[i+1].name);
            tracker->stocks[i].price = tracker->stocks[i+1].price;
        }
        tracker->numStocks--;
        printf("%s stock removed\n", name);
    }
    else {
        printf("%s stock not found\n", name);
    }
}

void updatePrice(StockTracker* tracker, char name[], float price) {
    int index = -1;
    for (int i = 0; i < tracker->numStocks; i++) {
        if (strcmp(tracker->stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        tracker->stocks[index].price = price;
        printf("%s price updated to %.2f\n", name, price);
    }
    else {
        printf("%s stock not found\n", name);
    }
}

void displayTracker(StockTracker tracker) {
    printf("Stock Tracker:\n");
    for (int i = 0; i < tracker.numStocks; i++) {
        printf("%s - %.2f\n", tracker.stocks[i].name, tracker.stocks[i].price);
    }
}

int main() {
    StockTracker tracker = {
        .stocks = {},
        .numStocks = 0
    };
    
    printf("Welcome to the Stock Market Tracker\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a stock\n");
        printf("2. Remove a stock\n");
        printf("3. Update a stock price\n");
        printf("4. Display Tracker\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter stock name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            printf("Enter stock price: ");
            float price;
            scanf("%f", &price);
            addStock(&tracker, name, price);
        }
        else if (choice == 2) {
            printf("Enter stock name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            removeStock(&tracker, name);
        }
        else if (choice == 3) {
            printf("Enter stock name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            printf("Enter new price: ");
            float price;
            scanf("%f", &price);
            updatePrice(&tracker, name, price);
        }
        else if (choice == 4) {
            displayTracker(tracker);
        }
        else if (choice == 5) {
            printf("Exiting...");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    
    return 0;
}
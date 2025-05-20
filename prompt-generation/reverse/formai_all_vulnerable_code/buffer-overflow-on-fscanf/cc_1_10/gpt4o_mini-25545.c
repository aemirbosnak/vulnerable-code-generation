//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int volume;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockMarket;

void initializeMarket(StockMarket *market) {
    market->count = 0;
}

void addStock(StockMarket *market, const char *name, float price, int volume) {
    if (market->count >= MAX_STOCKS) {
        printf("Market is full. Cannot add more stocks.\n");
        return;
    }
    strncpy(market->stocks[market->count].name, name, MAX_NAME_LENGTH);
    market->stocks[market->count].price = price;
    market->stocks[market->count].volume = volume;
    market->count++;
}

void updateStockPrice(StockMarket *market, const char *name, float newPrice) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].price = newPrice;
            printf("Updated %s price to %.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void displayStocks(const StockMarket *market) {
    printf("\n--- Stock Market Tracker ---\n");
    printf("Name\t\tPrice\tVolume\n");
    printf("---------------------------------\n");
    for (int i = 0; i < market->count; i++) {
        printf("%-15s %.2f\t%d\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].volume);
    }
    printf("---------------------------------\n");
}

void findStock(const StockMarket *market, const char *name) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            printf("Stock %s found: Price = %.2f, Volume = %d\n", name, market->stocks[i].price, market->stocks[i].volume);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void deleteStock(StockMarket *market, const char *name) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            for (int j = i; j < market->count - 1; j++) {
                market->stocks[j] = market->stocks[j + 1];
            }
            market->count--;
            printf("Deleted stock %s.\n", name);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void saveToFile(const StockMarket *market, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < market->count; i++) {
        fprintf(file, "%s %.2f %d\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].volume);
    }
    fclose(file);
    printf("Market data saved to %s.\n", filename);
}

void loadFromFile(StockMarket *market, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    float price;
    int volume;
    while (fscanf(file, "%s %f %d", name, &price, &volume) != EOF) {
        addStock(market, name, price, volume);
    }
    fclose(file);
    printf("Market data loaded from %s.\n", filename);
}

int main() {
    StockMarket market;
    initializeMarket(&market);

    int choice;
    char name[MAX_NAME_LENGTH];
    float price;
    int volume;
    const char *filename = "stocks.txt";

    while (1) {
        printf("\n1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stocks\n");
        printf("4. Find Stock\n");
        printf("5. Delete Stock\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock volume: ");
                scanf("%d", &volume);
                addStock(&market, name, price, volume);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStockPrice(&market, name, price);
                break;
            case 3:
                displayStocks(&market);
                break;
            case 4:
                printf("Enter stock name to find: ");
                scanf("%s", name);
                findStock(&market, name);
                break;
            case 5:
                printf("Enter stock name to delete: ");
                scanf("%s", name);
                deleteStock(&market, name);
                break;
            case 6:
                saveToFile(&market, filename);
                break;
            case 7:
                loadFromFile(&market, filename);
                break;
            case 8:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
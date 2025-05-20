//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    float price;
    float change;
    float volume;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockMarket;

void initializeMarket(StockMarket *market) {
    market->count = 0;
}

void addStock(StockMarket *market, const char *name, float price, float change, float volume) {
    if (market->count < MAX_STOCKS) {
        strncpy(market->stocks[market->count].name, name, NAME_LEN);
        market->stocks[market->count].price = price;
        market->stocks[market->count].change = change;
        market->stocks[market->count].volume = volume;
        market->count++;
    } else {
        printf("Market is full, cannot add more stocks.\n");
    }
}

void displayMarket(const StockMarket *market) {
    printf("\nStock Market Tracker:\n");
    printf("-------------------------------\n");
    printf("%-30s %-10s %-10s %-10s\n", "Stock Name", "Price", "Change", "Volume");
    printf("-------------------------------\n");
    for (int i = 0; i < market->count; i++) {
        printf("%-30s %-10.2f %-10.2f %-10.0f\n",
               market->stocks[i].name,
               market->stocks[i].price,
               market->stocks[i].change,
               market->stocks[i].volume);
    }
    printf("-------------------------------\n");
}

void readStockData(StockMarket *market) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    char name[NAME_LEN];
    float price, change, volume;

    while (fscanf(file, "%s %f %f %f", name, &price, &change, &volume) == 4) {
        addStock(market, name, price, change, volume);
    }
    
    fclose(file);
}

void updateStock(StockMarket *market, const char *name, float price, float change, float volume) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].price = price;
            market->stocks[i].change = change;
            market->stocks[i].volume = volume;
            printf("Updated stock: %s\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void simulateMarketChanges(StockMarket *market) {
    for (int i = 0; i < market->count; i++) {
        market->stocks[i].price += ((float)rand() / RAND_MAX - 0.5) * 5; // Random change
        market->stocks[i].change = (float)rand() / RAND_MAX * 10 - 5; // Random change percentage
        market->stocks[i].volume += rand() % 1000; // Random volume increase
    }
}

int main() {
    StockMarket market;
    initializeMarket(&market);
    readStockData(&market);

    int option;
    char stockName[NAME_LEN];
    float price, change, volume;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Display Market\n");
        printf("2. Update Stock\n");
        printf("3. Simulate Market Changes\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayMarket(&market);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", stockName);
                printf("Enter new price: ");
                scanf("%f", &price);
                printf("Enter new change: ");
                scanf("%f", &change);
                printf("Enter new volume: ");
                scanf("%f", &volume);
                updateStock(&market, stockName, price, change, volume);
                break;
            case 3:
                simulateMarketChanges(&market);
                printf("Market changes simulated.\n");
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
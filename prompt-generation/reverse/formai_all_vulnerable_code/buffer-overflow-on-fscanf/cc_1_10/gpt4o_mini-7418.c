//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
    float previous_price;
} Company;

typedef struct {
    Company companies[MAX_COMPANIES];
    int count;
} StockMarket;

void initializeMarket(StockMarket *market) {
    market->count = 0;
}

void addCompany(StockMarket *market, const char *name, float current_price) {
    if (market->count < MAX_COMPANIES) {
        strcpy(market->companies[market->count].name, name);
        market->companies[market->count].current_price = current_price;
        market->companies[market->count].previous_price = current_price; // Set initially equal
        market->count++;
    } else {
        printf("Error: Maximum number of companies reached.\n");
    }
}

void updatePrice(StockMarket *market, const char *name, float new_price) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->companies[i].name, name) == 0) {
            market->companies[i].previous_price = market->companies[i].current_price;
            market->companies[i].current_price = new_price;
            printf("Updated %s - New Price: %.2f (Previous Price: %.2f)\n", name, new_price, market->companies[i].previous_price);
            return;
        }
    }
    printf("Error: Company %s not found.\n", name);
}

void displayMarket(const StockMarket *market) {
    printf("\nStock Market Tracker:\n");
    printf("---------------------\n");
    for (int i = 0; i < market->count; i++) {
        float change = market->companies[i].current_price - market->companies[i].previous_price;
        char *status = (change > 0) ? "↑" : (change < 0) ? "↓" : "→";
        printf("%s: Current Price: %.2f | Change: %.2f %s\n",
               market->companies[i].name,
               market->companies[i].current_price,
               change,
               status);
    }
    printf("---------------------\n");
}

void displayCompanyInfo(const StockMarket *market, const char *name) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->companies[i].name, name) == 0) {
            printf("\nCompany: %s\n", market->companies[i].name);
            printf("Current Price: %.2f\n", market->companies[i].current_price);
            printf("Previous Price: %.2f\n", market->companies[i].previous_price);
            float change = market->companies[i].current_price - market->companies[i].previous_price;
            printf("Change: %.2f (%s)\n",
                   change,
                   (change > 0) ? "Increased" : (change < 0) ? "Decreased" : "No Change");
            return;
        }
    }
    printf("Error: Company %s not found.\n", name);
}

void loadCompaniesFromFile(StockMarket *market, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char name[MAX_NAME_LENGTH];
    float current_price;

    while (fscanf(file, "%49s %f", name, &current_price) == 2) {
        addCompany(market, name, current_price);
    }

    fclose(file);
}

int main() {
    StockMarket market;
    initializeMarket(&market);

    loadCompaniesFromFile(&market, "companies.txt");
    displayMarket(&market);

    updatePrice(&market, "CompanyA", 150.75);
    updatePrice(&market, "CompanyB", 200.50);
    
    displayMarket(&market);

    displayCompanyInfo(&market, "CompanyA");
    displayCompanyInfo(&market, "CompanyC"); // Example error case

    return 0;
}
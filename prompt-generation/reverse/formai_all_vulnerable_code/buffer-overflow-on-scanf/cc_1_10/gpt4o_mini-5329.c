//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float currentPrice;
    float previousPrice;
} Company;

void initializeMarket(Company companies[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of company %d: ", i + 1);
        fgets(companies[i].name, MAX_NAME_LENGTH, stdin);
        companies[i].name[strcspn(companies[i].name, "\n")] = 0;  // Remove newline

        printf("Enter the current price of %s: ", companies[i].name);
        scanf("%f", &companies[i].currentPrice);
        companies[i].previousPrice = companies[i].currentPrice;  // Initial set
        getchar();  // Consume leftover newline
    }
}

void updatePrices(Company companies[], int count) {
    for (int i = 0; i < count; i++) {
        float change = (rand() % 2000 - 1000) / 100.0; // Random change between -10.00 and +10.00
        companies[i].previousPrice = companies[i].currentPrice;
        companies[i].currentPrice += change;
    }
}

void displayMarket(Company companies[], int count) {
    printf("\n--- Stock Market Tracker ---\n");
    printf("%-30s %-15s %-15s %-15s\n", "Company Name", "Previous Price", "Current Price", "Price Change");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        float priceChange = companies[i].currentPrice - companies[i].previousPrice;
        printf("%-30s %-15.2f %-15.2f %-15.2f\n", 
               companies[i].name, 
               companies[i].previousPrice, 
               companies[i].currentPrice, 
               priceChange);
    }
}

float calculateMarketIndex(Company companies[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += companies[i].currentPrice;
    }
    return total / count;  // Return average price
}

void simulateMarket(Company companies[], int count, int days) {
    for (int day = 1; day <= days; day++) {
        printf("\n--- Day %d ---\n", day);
        updatePrices(companies, count);
        displayMarket(companies, count);
        float marketIndex = calculateMarketIndex(companies, count);
        printf("Market Index: %.2f\n", marketIndex);
    }
}

int main() {
    Company companies[MAX_COMPANIES];
    int numCompanies;

    printf("Enter the number of companies (max %d): ", MAX_COMPANIES);
    scanf("%d", &numCompanies);
    getchar();  // Consume leftover newline

    if (numCompanies > MAX_COMPANIES || numCompanies <= 0) {
        printf("Invalid number of companies. Please restart the program.\n");
        return 1;
    }

    initializeMarket(companies, numCompanies);
    
    int simulationDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &simulationDays);

    simulateMarket(companies, numCompanies, simulationDays);

    return 0;
}
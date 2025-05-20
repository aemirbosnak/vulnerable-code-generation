//FormAI DATASET v1.0 Category: Stock market tracker ; Style: introspective
/* 
 * TITLE: Stock Market Tracker
 * DESCRIPTION: This program tracks the stock market prices for a given set of companies and displays them in real time.
 * AUTHOR: [Your Name]
 * DATE: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 10
#define MAX_NAME_LENGTH 20

struct Company {
    char name[MAX_NAME_LENGTH];
    int price;
};

struct PriceHistory {
    int prices[24];
    int currentHour;
};

// Function prototypes
void displayMenu();
void displayCompanyPrices(struct Company companies[], int numCompanies);
void trackPrices(struct Company companies[], int numCompanies);
void updatePriceHistory(struct PriceHistory *priceHistory, int price);
void displayPriceHistory(struct PriceHistory priceHistory);

int main() {
    int choice, numCompanies = 0, i;
    struct Company companies[MAX_COMPANIES];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Display the main menu
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Add Company
                if(numCompanies >= MAX_COMPANIES) {
                    printf("You have reached the maximum number of companies!\n");
                } else {
                    printf("Enter name of company: ");
                    scanf("%s", companies[numCompanies].name);
                    companies[numCompanies].price = rand() % 100 + 1;
                    numCompanies++;
                }
                break;
            case 2: // Display Company Prices
                displayCompanyPrices(companies, numCompanies);
                break;
            case 3: // Track Prices
                trackPrices(companies, numCompanies);
                break;
            case 4: // Quit
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}

// Display the main menu
void displayMenu() {
    printf("\n------------ Stock Market Tracker ------------\n");
    printf("1. Add Company\n");
    printf("2. Display Company Prices\n");
    printf("3. Track Prices\n");
    printf("4. Quit\n");
    printf("----------------------------------------------\n");
    printf("Enter your choice: ");
}

// Display the prices for all companies
void displayCompanyPrices(struct Company companies[], int numCompanies) {
    int i;
    
    printf("\n------- Company Prices -------\n");
    for(i = 0; i < numCompanies; i++) {
        printf("%d. %s: $%d\n", i+1, companies[i].name, companies[i].price);
    }
    printf("-----------------------------\n");
}

// Track the prices for all companies
void trackPrices(struct Company companies[], int numCompanies) {
    int i, price;
    struct PriceHistory priceHistories[numCompanies];
    
    // Initialize the price histories
    for(i = 0; i < numCompanies; i++) {
        priceHistories[i].currentHour = 0;
        updatePriceHistory(&priceHistories[i], companies[i].price);
    }
    
    // Start tracking
    printf("\n------------ Tracking Prices ------------\n");
    while(1) {
        // Update prices for all companies
        for(i = 0; i < numCompanies; i++) {
            companies[i].price += rand() % 10 - 5;
            updatePriceHistory(&priceHistories[i], companies[i].price);
        }
        
        // Display the prices and price histories
        displayCompanyPrices(companies, numCompanies);
        printf("\n------ Price Histories ------\n");
        for(i = 0; i < numCompanies; i++) {
            printf("%s:\n", companies[i].name);
            displayPriceHistory(priceHistories[i]);
            printf("\n");
        }
        printf("-----------------------------\n");
        
        // Wait for 5 seconds before updating prices again
        printf("Press enter to continue...");
        getchar();
        getchar();
    }
}

// Update the price history with a new price
void updatePriceHistory(struct PriceHistory *priceHistory, int price) {
    priceHistory->prices[priceHistory->currentHour++] = price;
    if(priceHistory->currentHour >= 24) {
        priceHistory->currentHour = 0;
    }
}

// Display the price history
void displayPriceHistory(struct PriceHistory priceHistory) {
    int i, hourOfDay;
    for(i = 0; i < 24; i++) {
        hourOfDay = (i + 9) % 24; // Convert from UTC to US Pacific Time
        printf("%d:00: $%d\n", hourOfDay, priceHistory.prices[i]);
    }
}
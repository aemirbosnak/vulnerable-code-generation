//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float stockPrice;
} Company;

Company companies[MAX_COMPANIES];
int companyCount = 0;

void addCompany() {
    if (companyCount >= MAX_COMPANIES) {
        printf("Maximum company limit reached.\n");
        return;
    }
    printf("Enter company name: ");
    scanf("%s", companies[companyCount].name);
    printf("Enter stock price: ");
    scanf("%f", &companies[companyCount].stockPrice);
    companyCount++;
    printf("Company added successfully.\n");
    addCompany(); // Recursive call
}

void displayCompanies(int index) {
    if (index >= companyCount) {
        return; // Base case: all companies displayed
    }
    printf("Company: %s, Stock Price: %.2f\n", companies[index].name, companies[index].stockPrice);
    displayCompanies(index + 1); // Recursive call
}

void updateStockPrice(int index) {
    if (index >= companyCount) {
        printf("Invalid company index.\n");
        return; // Base case: invalid index
    }
    
    float newPrice;
    printf("Enter new stock price for %s: ", companies[index].name);
    scanf("%f", &newPrice);
    companies[index].stockPrice = newPrice;
    printf("Stock price updated for %s.\n", companies[index].name);
    updateStockPrice(index + 1); // Recursive call
}

void viewStockPrices() {
    printf("Stock Prices of Companies:\n");
    displayCompanies(0); // Start displaying from the first company
}

int main() {
    int choice;
    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add Company\n");
        printf("2. View Stock Prices\n");
        printf("3. Update Stock Price\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCompany();
                break;
            case 2:
                viewStockPrices();
                break;
            case 3:
                printf("Enter the company index to update (0 to %d): ", companyCount - 1);
                int index;
                scanf("%d", &index);
                updateStockPrice(index);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
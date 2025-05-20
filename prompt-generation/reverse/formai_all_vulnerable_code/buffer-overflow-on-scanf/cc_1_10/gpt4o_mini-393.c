//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[5];
    float price;
    float change;  // Change in price
} Company;

void displayMenu();
void addCompany(Company companies[], int *count);
void updatePrice(Company companies[], int count);
void displayCompanies(const Company companies[], int count);
float calculateAveragePrice(const Company companies[], int count);
void saveToFile(const Company companies[], int count);

int main() {
    Company companies[MAX_COMPANIES];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCompany(companies, &count);
                break;
            case 2:
                updatePrice(companies, count);
                break;
            case 3:
                displayCompanies(companies, count);
                break;
            case 4:
                {
                    float avgPrice = calculateAveragePrice(companies, count);
                    printf("Average Price of Stocks: %.2f\n", avgPrice);
                }
                break;
            case 5:
                saveToFile(companies, count);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Company\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Companies\n");
    printf("4. Calculate Average Stock Price\n");
    printf("5. Save Data to File\n");
    printf("6. Exit\n");
}

void addCompany(Company companies[], int *count) {
    if (*count >= MAX_COMPANIES) {
        printf("Cannot add more companies, maximum reached.\n");
        return;
    }

    Company newCompany;
    printf("Enter the company name: ");
    scanf("%s", newCompany.name);
    printf("Enter the stock symbol: ");
    scanf("%s", newCompany.symbol);
    printf("Enter the stock price: ");
    scanf("%f", &newCompany.price);
    newCompany.change = 0.0; // Initial change is 0
    
    companies[*count] = newCompany;
    (*count)++;
    printf("Company added successfully!\n");
}

void updatePrice(Company companies[], int count) {
    if (count == 0) {
        printf("No companies to update.\n");
        return;
    }

    char symbol[5];
    printf("Enter the stock symbol to update: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(companies[i].symbol, symbol) == 0) {
            float newPrice;
            printf("Enter the new price for %s: ", companies[i].name);
            scanf("%f", &newPrice);
            companies[i].change = newPrice - companies[i].price;
            companies[i].price = newPrice;
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Company with symbol %s not found.\n", symbol);
}

void displayCompanies(const Company companies[], int count) {
    if (count == 0) {
        printf("No companies available.\n");
        return;
    }

    printf("\nList of Companies:\n");
    printf("Name\t\tSymbol\tPrice\tChange\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-5s %.2f %.2f\n", companies[i].name, companies[i].symbol, companies[i].price, companies[i].change);
    }
}

float calculateAveragePrice(const Company companies[], int count) {
    if (count == 0) {
        return 0.0;
    }

    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += companies[i].price;
    }
    return total / count;
}

void saveToFile(const Company companies[], int count) {
    FILE *file = fopen("stocks_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f %.2f\n", companies[i].name, companies[i].symbol, companies[i].price, companies[i].change);
    }
    fclose(file);
    printf("Data saved to stocks_data.txt successfully!\n");
}
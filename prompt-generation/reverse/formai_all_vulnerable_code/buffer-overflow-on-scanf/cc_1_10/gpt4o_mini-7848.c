//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Company;

void addCompany(Company companies[], int *count);
void updatePrices(Company companies[], int count);
void displayCompanies(const Company companies[], int count);
void searchCompany(const Company companies[], int count);
void shopkeeperNarrative();

int main() {
    Company companies[MAX_COMPANIES];
    int count = 0;
    int choice;

    shopkeeperNarrative();

    while (1) {
        printf("\n1. Add a new company\n");
        printf("2. Update stock prices\n");
        printf("3. Display all companies\n");
        printf("4. Search for a company\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCompany(companies, &count);
                break;
            case 2:
                updatePrices(companies, count);
                break;
            case 3:
                displayCompanies(companies, count);
                break;
            case 4:
                searchCompany(companies, count);
                break;
            case 5:
                printf("Farewell! Until we meet again.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addCompany(Company companies[], int *count) {
    if (*count >= MAX_COMPANIES) {
        printf("Cannot add more companies.\n");
        return;
    }
    
    printf("Enter company name: ");
    scanf("%s", companies[*count].name);
    printf("Enter current stock price: ");
    scanf("%f", &companies[*count].price);
    companies[*count].change = 0; // Initialize change as 0
    (*count)++;
    printf("Company %s added successfully.\n", companies[*count - 1].name);
}

void updatePrices(Company companies[], int count) {
    if (count == 0) {
        printf("No companies available to update.\n");
        return;
    }

    printf("Updating prices...\n");
    for (int i = 0; i < count; i++) {
        float oldPrice = companies[i].price;
        companies[i].price += ((rand() % 10) - 5); // Simulating price fluctuations
        companies[i].change = companies[i].price - oldPrice;
        printf("Updated %s: New price: %.2f, Change: %.2f\n", 
               companies[i].name, companies[i].price, companies[i].change);
    }
}

void displayCompanies(const Company companies[], int count) {
    if (count == 0) {
        printf("No companies recorded.\n");
        return;
    }

    printf("\nCompanies and their stock prices:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Price: %.2f | Change: %.2f\n", 
               companies[i].name, companies[i].price, companies[i].change);
    }
}

void searchCompany(const Company companies[], int count) {
    if (count == 0) {
        printf("No companies to search through!\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the company name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(companies[i].name, searchName) == 0) {
            printf("Found %s | Price: %.2f | Change: %.2f\n", 
                   companies[i].name, companies[i].price, companies[i].change);
            return;
        }
    }
    printf("Company %s not found.\n", searchName);
}

void shopkeeperNarrative() {
    printf("In a quaint little shop on Baker Street, ");
    printf("Sherlock Holmes and Dr. Watson were intrigued by the world of finance.\n");
    printf("Holmes glanced at the morning newspaper, ");
    printf("its stock market section filled with the erratic dance of numbers.\n");
    printf("“Watson,” he mused, “money holds secrets, but we shall unravel them.”\n");
    printf("Thus began their adventure to track the currents of the stock market...\n");
}
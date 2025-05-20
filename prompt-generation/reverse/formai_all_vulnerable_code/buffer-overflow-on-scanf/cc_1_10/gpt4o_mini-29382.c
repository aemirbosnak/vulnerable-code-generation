//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
    float previous_price;
} Company;

void initialize_companies(Company companies[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(companies[i].name, MAX_NAME_LENGTH, "Company_%d", i + 1);
        companies[i].current_price = (float)(rand() % 100 + 1); // Random price between 1 and 100
        companies[i].previous_price = companies[i].current_price; // Initial previous price
    }
}

void update_prices(Company companies[], int count) {
    for (int i = 0; i < count; i++) {
        companies[i].previous_price = companies[i].current_price;
        companies[i].current_price += (float)(rand() % 21 - 10); // Random change between -10 and 10
        if (companies[i].current_price < 0) {
            companies[i].current_price = 0; // Ensure price doesn't go negative
        }
    }
}

void display_prices(const Company companies[], int count) {
    printf("Stock Market Tracker\n");
    printf("====================================\n");
    printf("%-20s | Current Price | Change\n", "Company Name");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        float change = companies[i].current_price - companies[i].previous_price;
        printf("%-20s | $%.2f         | %+0.2f\n", companies[i].name, companies[i].current_price, change);
    }
    printf("====================================\n");
}

void sort_companies_by_price(Company companies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (companies[j].current_price > companies[j + 1].current_price) {
                Company temp = companies[j];
                companies[j] = companies[j + 1];
                companies[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Company companies[MAX_COMPANIES];
    int num_companies;

    printf("Enter the number of companies (1-%d): ", MAX_COMPANIES);
    scanf("%d", &num_companies);
    while (num_companies < 1 || num_companies > MAX_COMPANIES) {
        printf("Invalid input! Please enter a number between 1 and %d: ", MAX_COMPANIES);
        scanf("%d", &num_companies);
    }

    initialize_companies(companies, num_companies);

    char choice;
    do {
        printf("\n");
        display_prices(companies, num_companies);
        
        printf("Do you want to update prices? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            update_prices(companies, num_companies);
            sort_companies_by_price(companies, num_companies);
        }
        
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Stock Market Tracker!\n");
    return 0;
}
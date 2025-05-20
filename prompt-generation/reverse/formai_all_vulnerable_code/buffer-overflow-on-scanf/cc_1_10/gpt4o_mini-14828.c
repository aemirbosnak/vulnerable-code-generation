//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 10
#define NAME_LENGTH 30

// Structure for Company
typedef struct {
    char name[NAME_LENGTH];
    float stockValue;
} Company;

// Function prototypes
void displayMarket(Company companies[], int count);
void updatePrices(Company companies[], int count);
void displayMenu();
void viewCompanyStocks(Company companies[], int count);
void sortStocksByValue(Company companies[], int count);
void investInCompany(Company companies[], int count);

// The Grand Market of Stocks
int main() {
    Company companies[MAX_COMPANIES] = {
        {"The Iron Forge", 100.50},
        {"The Silver Mine", 200.75},
        {"The Golden Fields", 150.00},
        {"Royal Shipwrights", 175.25},
        {"Valiant Knights", 120.00},
        {"Mystic Herbalists", 95.40},
        {"Enchanted Woods", 230.60},
        {"Gallant Stonemasons", 85.30},
        {"Majestic Weavers", 150.80},
        {"Noble Scribes", 99.99}
    };
    
    int choice;
    srand(time(NULL)); // Seed the random number generator
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMarket(companies, MAX_COMPANIES);
                break;
            case 2:
                updatePrices(companies, MAX_COMPANIES);
                break;
            case 3:
                investInCompany(companies, MAX_COMPANIES);
                break;
            case 4:
                viewCompanyStocks(companies, MAX_COMPANIES);
                break;
            case 5:
                sortStocksByValue(companies, MAX_COMPANIES);
                break;
            case 6:
                printf("Farewell, brave investor!\n");
                break;
            default:
                printf("Alas! That is not a valid choice.\n");
        }
        
    } while (choice != 6);
    
    return 0;
}

// Displays the known market of stocks
void displayMarket(Company companies[], int count) {
    printf("\n--- The Grand Market of Stocks ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %.2f gold coins\n", i + 1, companies[i].name, companies[i].stockValue);
    }
    printf("----------------------------------\n");
}

// Updates the stock prices at random
void updatePrices(Company companies[], int count) {
    printf("\n- The Royal Herald announces the price updates! -\n");
    for (int i = 0; i < count; i++) {
        float change = ((rand() % 100) - 50) / 10.0; // Change in price can be [-5.0, 4.9]
        companies[i].stockValue += change;
        printf("%s's new stock value: %.2f gold coins\n", companies[i].name, companies[i].stockValue);
    }
    printf("-------------------------------------------------\n");
}

// Show the options available to the investors
void displayMenu() {
    printf("\n- The Grand Council of Merchants -\n");
    printf("1. View the Market\n");
    printf("2. Update Stock Prices\n");
    printf("3. Invest in a Company\n");
    printf("4. View Specific Company Stocks\n");
    printf("5. Sort Stocks by Value\n");
    printf("6. Exit the Market\n");
    printf("Choose thy fate (1-6): ");
}

// View stocks of a specific company
void viewCompanyStocks(Company companies[], int count) {
    int index;
    printf("Enter the number of the company (1-%d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("That company does not exist!\n");
    } else {
        printf("%s's stock value is: %.2f gold coins\n", companies[index - 1].name, companies[index - 1].stockValue);
    }
}

// Sorts the companies by stock value in descending order
void sortStocksByValue(Company companies[], int count) {
    for (int i = 0; i < count-1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (companies[i].stockValue < companies[j].stockValue) {
                Company temp = companies[i];
                companies[i] = companies[j];
                companies[j] = temp;
            }
        }
    }

    printf("\nThe companies have been sorted by their stock values!\n");
}

// Allows the noble investors to invest in a company
void investInCompany(Company companies[], int count) {
    int index;
    float amount;

    printf("Which company dost thou wish to invest in (1-%d)? ", count);
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("That company does not exist, brave investor!\n");
    } else {
        printf("How many gold coins dost thou wish to invest into %s? ", companies[index - 1].name);
        scanf("%f", &amount);
        
        if (amount <= 0) {
            printf("A noble investment must be more than zero gold coins!\n");
        } else {
            printf("Thou hast invested %.2f gold coins into %s.\n", amount, companies[index - 1].name);
            companies[index - 1].stockValue += amount / 10; // Increase stock value based on investment
        }
    }
}
//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int sharesOutstanding;
} Company;

Company companies[MAX_COMPANIES];
int companyCount = 0;

// Function prototypes
void addCompany();
void updateStockPrice();
void viewCompanyInfo();
void listAllCompanies();
float getRandomPrice(float basePrice);

int main() {
    int choice;

    while (1) {
        printf("Welcome to the Stock Market Tracker!\n");
        printf("1. Add a Company\n");
        printf("2. Update Stock Price\n");
        printf("3. View Company Information\n");
        printf("4. List All Companies\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);
        getchar();  // Clear newline from buffer

        switch (choice) {
            case 1:
                addCompany();
                break;
            case 2:
                updateStockPrice();
                break;
            case 3:
                viewCompanyInfo();
                break;
            case 4:
                listAllCompanies();
                break;
            case 5:
                printf("Thank you for using the Stock Market Tracker! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addCompany() {
    if (companyCount >= MAX_COMPANIES) {
        printf("Maximum companies reached, unable to add more!\n");
        return;
    }
    printf("Enter company name: ");
    fgets(companies[companyCount].name, NAME_LENGTH, stdin);
    companies[companyCount].name[strcspn(companies[companyCount].name, "\n")] = '\0';  // Remove newline

    printf("Enter initial stock price: ");
    scanf("%f", &companies[companyCount].price);
    
    printf("Enter shares outstanding: ");
    scanf("%d", &companies[companyCount].sharesOutstanding);
    
    companyCount++;
    printf("Company '%s' added successfully!\n", companies[companyCount - 1].name);
}

void updateStockPrice() {
    char name[NAME_LENGTH];
    float newPrice;
    int found = 0;

    printf("Enter the company name to update price: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < companyCount; i++) {
        if (strcmp(companies[i].name, name) == 0) {
            found = 1;
            newPrice = getRandomPrice(companies[i].price);
            companies[i].price = newPrice;
            printf("Updated '%s' stock price to $%.2f\n", companies[i].name, companies[i].price);
            break;
        }
    }
    
    if (!found) {
        printf("Company '%s' not found!\n", name);
    }
}

float getRandomPrice(float basePrice) {
    srand(time(NULL));
    float fluctuation = (rand() % 1000 - 500) / 100.0f;  // Random fluctuation from -5.00 to +5.00
    return basePrice + fluctuation;
}

void viewCompanyInfo() {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter the company name to view information: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < companyCount; i++) {
        if (strcmp(companies[i].name, name) == 0) {
            found = 1;
            printf("Company: %s\n", companies[i].name);
            printf("Current Stock Price: $%.2f\n", companies[i].price);
            printf("Shares Outstanding: %d\n", companies[i].sharesOutstanding);
            break;
        }
    }
    
    if (!found) {
        printf("Company '%s' not found!\n", name);
    }
}

void listAllCompanies() {
    printf("List of Companies:\n");
    for (int i = 0; i < companyCount; i++) {
        printf("%d. %s - Current Price: $%.2f\n", i + 1, companies[i].name, companies[i].price);
    }
    if (companyCount == 0) {
        printf("No companies have been added yet!\n");
    }
}
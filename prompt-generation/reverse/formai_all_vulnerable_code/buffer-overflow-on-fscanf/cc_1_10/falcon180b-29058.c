//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50
#define MAX_TICKER_LENGTH 10

// Define the structure of a company
typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_TICKER_LENGTH];
    double price;
} Company;

// Function to read the company data from a file
void read_companies(Company companies[], FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %s %lf\n", companies[i].name, companies[i].ticker, &companies[i].price) == 3) {
        i++;
        if (i >= MAX_COMPANIES) {
            break;
        }
    }
}

// Function to print the company data
void print_companies(Company companies[], int num_companies) {
    for (int i = 0; i < num_companies; i++) {
        printf("%s (%s) - $%.2f\n", companies[i].name, companies[i].ticker, companies[i].price);
    }
}

// Function to update the prices of the companies
void update_prices(Company companies[], int num_companies) {
    for (int i = 0; i < num_companies; i++) {
        companies[i].price += (rand() % 100) / 100.0;
    }
}

int main() {
    // Initialize the companies
    Company companies[MAX_COMPANIES];
    int num_companies = 0;

    // Read the company data from a file
    FILE *fp = fopen("companies.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    read_companies(companies, fp);
    fclose(fp);

    // Print the initial company data
    printf("Initial company data:\n");
    print_companies(companies, num_companies);

    // Update the prices of the companies
    update_prices(companies, num_companies);

    // Print the updated company data
    printf("\nUpdated company data:\n");
    print_companies(companies, num_companies);

    return 0;
}
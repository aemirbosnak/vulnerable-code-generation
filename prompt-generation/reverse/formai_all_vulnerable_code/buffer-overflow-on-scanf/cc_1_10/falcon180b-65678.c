//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_PRICE_HISTORY 1000

typedef struct {
    char name[50];
    char symbol[10];
    double current_price;
    double price_history[MAX_STOCK_PRICE_HISTORY];
    int history_index;
} Company;

void initialize_company(Company *company) {
    strcpy(company->name, "");
    strcpy(company->symbol, "");
    company->current_price = 0.0;
    company->history_index = 0;
}

void add_price_history(Company *company, double price) {
    if (company->history_index >= MAX_STOCK_PRICE_HISTORY) {
        printf("Error: Price history is full.\n");
        return;
    }
    company->price_history[company->history_index++] = price;
}

void print_price_history(Company *company) {
    int i;
    printf("Price history for %s:\n", company->name);
    for (i = 0; i < company->history_index; i++) {
        printf("%s: $%.2f\n", ctime(&(company->price_history[i])), company->price_history[i]);
    }
}

int main() {
    int num_companies;
    Company companies[MAX_COMPANIES];

    printf("Enter the number of companies to track: ");
    scanf("%d", &num_companies);

    for (int i = 0; i < num_companies; i++) {
        printf("Enter company %d name: ", i+1);
        scanf("%s", companies[i].name);
        printf("Enter company %d symbol: ", i+1);
        scanf("%s", companies[i].symbol);
        initialize_company(&companies[i]);
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");
        for (int i = 0; i < num_companies; i++) {
            printf("%s (%s): $%.2f\n", companies[i].name, companies[i].symbol, companies[i].current_price);
        }
        printf("\nEnter a company symbol to view price history: ");
        char symbol[10];
        scanf("%s", symbol);
        int found = 0;
        for (int i = 0; i < num_companies; i++) {
            if (strcmp(symbol, companies[i].symbol) == 0) {
                found = 1;
                print_price_history(&companies[i]);
                break;
            }
        }
        if (!found) {
            printf("Company not found.\n");
        }
        printf("\nPress enter to continue... ");
        getchar();
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_HISTORY 30

typedef struct {
    char name[50];
    float price;
    int history[MAX_STOCK_HISTORY];
    int history_index;
} Company;

void init_company(Company *company) {
    strcpy(company->name, "");
    company->price = 0;
    memset(company->history, 0, sizeof(company->history));
    company->history_index = 0;
}

void add_stock_history(Company *company, float price) {
    company->history[company->history_index++] = price;
    if (company->history_index >= MAX_STOCK_HISTORY) {
        company->history_index = 0;
    }
}

int main() {
    Company companies[MAX_COMPANIES];
    int num_companies = 0;

    init_company(&companies[num_companies]);
    num_companies++;

    while (1) {
        printf("Enter company name: ");
        scanf("%s", companies[num_companies - 1].name);

        if (strcmp(companies[num_companies - 1].name, "") == 0) {
            printf("Invalid company name.\n");
            num_companies--;
        } else {
            break;
        }
    }

    while (1) {
        printf("Enter stock price: ");
        scanf("%f", &companies[num_companies - 1].price);

        add_stock_history(&companies[num_companies - 1], companies[num_companies - 1].price);

        printf("Enter another stock price? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    while (1) {
        printf("Enter company name to view stock history: ");
        scanf("%s", companies[num_companies - 1].name);

        if (strcmp(companies[num_companies - 1].name, "") == 0) {
            printf("Invalid company name.\n");
        } else {
            printf("Stock history for %s:\n", companies[num_companies - 1].name);
            for (int i = 0; i < MAX_STOCK_HISTORY; i++) {
                if (companies[num_companies - 1].history[i]!= 0) {
                    printf("%f\n", companies[num_companies - 1].history[i]);
                }
            }
            break;
        }
    }

    return 0;
}
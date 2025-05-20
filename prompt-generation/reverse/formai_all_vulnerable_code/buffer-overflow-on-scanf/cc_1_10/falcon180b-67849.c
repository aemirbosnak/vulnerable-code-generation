//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int is_active;
} company;

int main() {
    int num_companies;
    printf("Enter the number of companies to track: ");
    scanf("%d", &num_companies);

    company* companies = (company*)malloc(num_companies * sizeof(company));

    for (int i = 0; i < num_companies; i++) {
        printf("Enter the name of company %d: ", i+1);
        scanf("%s", companies[i].name);

        printf("Enter the starting price of %s: ", companies[i].name);
        scanf("%f", &companies[i].price);

        printf("Is %s currently active? (y/n): ", companies[i].name);
        char choice;
        scanf(" %c", &choice);
        companies[i].is_active = (choice == 'y' || choice == 'Y');
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");
        printf("=====================\n");

        for (int i = 0; i < num_companies; i++) {
            if (companies[i].is_active) {
                printf("%-20s $%-9.2f\n", companies[i].name, companies[i].price);
            }
        }

        printf("\nPress any key to update prices...");
        getchar();

        for (int i = 0; i < num_companies; i++) {
            if (companies[i].is_active) {
                printf("Updating price for %s...\n", companies[i].name);
                companies[i].price += rand() % 10 - 5;
            }
        }
    }

    return 0;
}
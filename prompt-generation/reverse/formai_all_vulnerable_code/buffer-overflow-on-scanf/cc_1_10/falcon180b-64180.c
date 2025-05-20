//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    float price;
    int volume;
} company_t;

company_t companies[MAX_COMPANIES];
int num_companies = 0;

void add_company(char* name, char* symbol, float price, int volume) {
    if (num_companies >= MAX_COMPANIES) {
        printf("Error: maximum number of companies reached.\n");
        return;
    }

    strcpy(companies[num_companies].name, name);
    strcpy(companies[num_companies].symbol, symbol);
    companies[num_companies].price = price;
    companies[num_companies].volume = volume;

    num_companies++;
}

void remove_company(char* symbol) {
    int i;

    for (i = 0; i < num_companies; i++) {
        if (strcmp(companies[i].symbol, symbol) == 0) {
            memmove(&companies[i], &companies[i+1], (num_companies - i - 1) * sizeof(company_t));
            num_companies--;
            break;
        }
    }
}

void update_company(char* symbol, float price, int volume) {
    int i;

    for (i = 0; i < num_companies; i++) {
        if (strcmp(companies[i].symbol, symbol) == 0) {
            companies[i].price = price;
            companies[i].volume = volume;
            break;
        }
    }
}

void print_companies() {
    int i;

    for (i = 0; i < num_companies; i++) {
        printf("%-50s %-10s $%.2f %10d\n", companies[i].name, companies[i].symbol, companies[i].price, companies[i].volume);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN], symbol[MAX_SYMBOL_LEN];
    float price;
    int volume;

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    while (1) {
        printf("\n");
        printf("1. Add company\n");
        printf("2. Remove company\n");
        printf("3. Update company\n");
        printf("4. Print companies\n");
        printf("5. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter company name: ");
            scanf("%s", name);

            printf("Enter company symbol: ");
            scanf("%s", symbol);

            printf("Enter company price: ");
            scanf("%f", &price);

            printf("Enter company volume: ");
            scanf("%d", &volume);

            add_company(name, symbol, price, volume);
            break;

        case 2:
            printf("Enter company symbol to remove: ");
            scanf("%s", symbol);

            remove_company(symbol);
            break;

        case 3:
            printf("Enter company symbol to update: ");
            scanf("%s", symbol);

            printf("Enter new company price: ");
            scanf("%f", &price);

            printf("Enter new company volume: ");
            scanf("%d", &volume);

            update_company(symbol, price, volume);
            break;

        case 4:
            printf("\n");
            print_companies();
            break;

        case 5:
            printf("\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
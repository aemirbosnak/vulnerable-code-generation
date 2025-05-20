//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Company;

void readCompanies(Company companies[], int numCompanies) {
    FILE *file = fopen("companies.txt", "r");

    if (file == NULL) {
        printf("Error: could not open companies file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %lf\n", companies[i].name, companies[i].symbol, &companies[i].price)!= EOF) {
        i++;
        if (i == numCompanies) {
            break;
        }
    }

    fclose(file);
}

void printCompanies(Company companies[], int numCompanies) {
    printf("Company Name\tSymbol\tPrice\n");

    for (int i = 0; i < numCompanies; i++) {
        printf("%-20s\t%-10s\t$%.2f\n", companies[i].name, companies[i].symbol, companies[i].price);
    }
}

int main() {
    Company companies[MAX_COMPANIES];
    int numCompanies = 0;

    readCompanies(companies, MAX_COMPANIES);
    numCompanies = MAX_COMPANIES;

    char choice;
    while (1) {
        printf("1. Print companies\n2. Search for a company\n3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printCompanies(companies, numCompanies);
                break;
            case '2':
                printf("Enter company name: ");
                char searchName[MAX_NAME_LENGTH];
                scanf("%s", searchName);

                int found = 0;
                for (int i = 0; i < numCompanies; i++) {
                    if (strcmp(companies[i].name, searchName) == 0) {
                        printf("Company found:\n");
                        printf("Name: %s\nSymbol: %s\nPrice: $%.2f\n", companies[i].name, companies[i].symbol, companies[i].price);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Company not found.\n");
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
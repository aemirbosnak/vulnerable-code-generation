//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMPANIES 10
#define MAX_STOCK_NAME_LENGTH 50

// Company structure
typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[10];
    double current_price;
    double previous_price;
    int change;
    int change_percentage;
} Company;

// Function prototypes
void read_companies_from_file(char* filename, Company* companies);
void print_header();
void print_company(Company* company);
int main() {
    Company companies[MAX_COMPANIES];
    char filename[100];
    printf("Enter the name of the file containing company information: ");
    scanf("%s", filename);
    read_companies_from_file(filename, companies);
    print_header();
    for (int i = 0; i < MAX_COMPANIES; i++) {
        if (strcmp(companies[i].name, "")!= 0) {
            print_company(&companies[i]);
        }
    }
    return 0;
}

// Read companies from file
void read_companies_from_file(char* filename, Company* companies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %s %lf %lf %d %d\n", companies[count].name, companies[count].symbol, &companies[count].current_price, &companies[count].previous_price, &companies[count].change, &companies[count].change_percentage)!= EOF) {
        count++;
        if (count >= MAX_COMPANIES) {
            break;
        }
    }
    fclose(file);
}

// Print header
void print_header() {
    printf("Company Name\tSymbol\tCurrent Price\tPrevious Price\tChange\tChange %\n");
}

// Print company information
void print_company(Company* company) {
    printf("%-50s\t%-10s\t%.2lf\t%.2lf\t%.2lf\t%.2lf %%\n", company->name, company->symbol, company->current_price, company->previous_price, company->change, company->change_percentage);
}
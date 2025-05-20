//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10
#define MAX_SHARES 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int shares;
    double price;
} company_t;

void print_header(void) {
    printf("Company Name\tSymbol\tShares\tPrice\n");
}

void print_company(company_t *company) {
    printf("%-50s\t%s\t%d\t$%.2f\n", company->name, company->symbol, company->shares, company->price);
}

int compare_companies(const void *a, const void *b) {
    const company_t *company_a = a;
    const company_t *company_b = b;

    return strcmp(company_a->symbol, company_b->symbol);
}

int main(int argc, char *argv[]) {
    company_t companies[MAX_COMPANIES];
    int num_companies = 0;
    char line[256];
    FILE *input_file;

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        if (num_companies >= MAX_COMPANIES) {
            printf("Maximum number of companies reached.\n");
            break;
        }

        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int shares = atoi(strtok(NULL, ","));
        double price = atof(strtok(NULL, ","));

        strcpy(companies[num_companies].name, name);
        strcpy(companies[num_companies].symbol, symbol);
        companies[num_companies].shares = shares;
        companies[num_companies].price = price;

        num_companies++;
    }

    fclose(input_file);

    qsort(companies, num_companies, sizeof(company_t), compare_companies);

    print_header();
    for (int i = 0; i < num_companies; i++) {
        print_company(&companies[i]);
    }

    return 0;
}
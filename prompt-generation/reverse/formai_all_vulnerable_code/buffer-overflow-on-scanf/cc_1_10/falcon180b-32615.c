//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 50
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_SHARES 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int shares;
} company_t;

void print_header(FILE *fp) {
    fprintf(fp, "Company Name\tSymbol\tPrice\tShares\n");
}

void print_company(company_t *c, FILE *fp) {
    fprintf(fp, "%-20s\t%-10s\t$%.2f\t%d\n", c->name, c->symbol, c->price, c->shares);
}

int main() {
    FILE *fp;
    fp = fopen("stock_market.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    print_header(fp);

    company_t companies[MAX_COMPANIES];
    int num_companies = 0;

    while (num_companies < MAX_COMPANIES) {
        printf("Enter company name (max %d characters): ", MAX_NAME_LEN - 1);
        scanf("%s", companies[num_companies].name);

        printf("Enter company symbol (max %d characters): ", MAX_SYMBOL_LEN - 1);
        scanf("%s", companies[num_companies].symbol);

        printf("Enter initial price: ");
        scanf("%lf", &companies[num_companies].price);

        printf("Enter initial number of shares: ");
        scanf("%d", &companies[num_companies].shares);

        print_company(&companies[num_companies], fp);
        num_companies++;
    }

    fclose(fp);

    return 0;
}
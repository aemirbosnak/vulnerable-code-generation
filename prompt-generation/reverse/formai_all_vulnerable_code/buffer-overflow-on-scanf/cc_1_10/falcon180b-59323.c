//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10
#define MAX_CHANGE_LENGTH 10
#define MAX_PERCENT_CHANGE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char volume[MAX_VOLUME_LENGTH];
    char change[MAX_CHANGE_LENGTH];
    char percent_change[MAX_PERCENT_CHANGE_LENGTH];
} company_t;

void read_companies(company_t companies[], int num_companies) {
    FILE *file = fopen("companies.txt", "r");
    if (file == NULL) {
        printf("Error: could not open companies.txt\n");
        exit(1);
    }
    int i = 0;
    while (i < num_companies && fscanf(file, "%s %s %s %s %s %s\n", companies[i].name, companies[i].symbol, companies[i].price, companies[i].volume, companies[i].change, companies[i].percent_change) == 6) {
        i++;
    }
    fclose(file);
}

void display_companies(company_t companies[], int num_companies) {
    printf("Name\tSymbol\tPrice\tVolume\tChange\t% Change\n");
    for (int i = 0; i < num_companies; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", companies[i].name, companies[i].symbol, companies[i].price, companies[i].volume, companies[i].change, companies[i].percent_change);
    }
}

int main() {
    company_t companies[MAX_COMPANIES];
    int num_companies = 0;
    char input[MAX_NAME_LENGTH + MAX_SYMBOL_LENGTH + 2];
    printf("Enter the number of companies you want to track (up to %d): ", MAX_COMPANIES - 1);
    scanf("%d", &num_companies);
    for (int i = 0; i < num_companies; i++) {
        printf("Enter the name and symbol of company %d (e.g. Microsoft MSFT): ", i + 1);
        scanf("%s", input);
        strcpy(companies[i].name, input);
        strcpy(companies[i].symbol, input + strlen(companies[i].name) + 1);
    }
    read_companies(companies, num_companies);
    display_companies(companies, num_companies);
    return 0;
}
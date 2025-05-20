//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMPANIES 50
#define MAX_SYMBOL_LEN 10
#define FILE_NAME "stock_prices.txt"

// Structure to store company information
typedef struct {
    char symbol[MAX_SYMBOL_LEN];
    char name[50];
    float current_price;
    float previous_close;
    float change_percent;
} Company;

// Function to read stock prices from file and store in Company struct
void load_prices(Company companies[], int num_companies) {
    int i;
    FILE *file = fopen(FILE_NAME, "r");
    char line[100];

    if (file == NULL) {
        printf("Error: Unable to open stock prices file.\n");
        exit(1);
    }

    for (i = 0; i < num_companies; i++) {
        fgets(line, sizeof(line), file); // Read line
        sscanf(line, "%s%s%f%f%f", companies[i].symbol, companies[i].name,
               &companies[i].previous_close, &companies[i].current_price,
               &companies[i].change_percent);
    }

    fclose(file);
}

// Function to print Company information in an exciting way
void print_company_info(Company company) {
    printf("\n==============\n");
    printf("| %-10s|\n", company.symbol);
    printf("| %-50s|\n", company.name);
    printf("| Current Price: $%.2f |\n", company.current_price);
    printf("| Previous Close: $%.2f |\n", company.previous_close);
    printf("| Change: $%.2f (%.2f%%) |\n", company.current_price - company.previous_close,
           company.change_percent);
    printf("==============\n");
}

int main() {
    Company companies[MAX_COMPANIES];
    int num_companies = 5;

    load_prices(companies, num_companies);

    printf("\n-------------------------------------------\n");
    printf("| Welcome to StockRocket - The Exciting Stock|\n");
    printf("| Tracker!                                |\n");
    printf("-------------------------------------------\n");

    int i;
    for (i = 0; i < num_companies; i++) {
        print_company_info(companies[i]);
    }

    return 0;
}
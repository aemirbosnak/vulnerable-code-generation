//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMPANIES 50
#define LINE_LENGTH 256

typedef struct {
    char name[LINE_LENGTH];
    float current_price;
    float previous_close;
    float change_percent;
} Company;

Company companies[MAX_COMPANIES];

void initialize_companies() {
    FILE *file = fopen("companies.txt", "r");
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open companies file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %f %f", companies[i].name, &companies[i].previous_close, &companies[i].current_price) != EOF) {
        i++;
    }

    fclose(file);
}

void print_companies() {
    int i;

    printf("\n%-20s %-10s %-10s %-10s\n", "Company Name", "Previous Close", "Current Price", "Change Percentage");
    printf("----------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 50; i++) {
        printf("%-20s %-10.2f %-10.2f %-10.2f%%\n", companies[i].name, companies[i].previous_close, companies[i].current_price, companies[i].change_percent);
    }
}

void calculate_change_percentage(int index) {
    companies[index].change_percent = ((companies[index].current_price - companies[index].previous_close) / companies[index].previous_close) * 100;
}

void update_companies() {
    FILE *file = fopen("stock_prices.txt", "r");
    int i;

    if (file == NULL) {
        printf("Error: Unable to open stock prices file.\n");
        exit(1);
    }

    for (i = 0; i < 50; i++) {
        char company_name[LINE_LENGTH];
        float new_price;

        fscanf(file, "%s %f", company_name, &new_price);

        for (int j = 0; j < 50; j++) {
            if (strcmp(companies[j].name, company_name) == 0) {
                companies[j].current_price = new_price;
                calculate_change_percentage(j);
                break;
            }
        }
    }

    fclose(file);
}

int main() {
    initialize_companies();
    update_companies();
    print_companies();

    while (1) {
        update_companies();
        print_companies();
        sleep(300); // Sleep for 5 minutes
    }

    return 0;
}
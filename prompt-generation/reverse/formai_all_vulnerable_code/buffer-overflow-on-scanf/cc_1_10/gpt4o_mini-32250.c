//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float stock_price;
} Company;

Company companies[MAX_COMPANIES];
int company_count = 0;

void add_company(const char *name, float price) {
    if (company_count < MAX_COMPANIES) {
        strcpy(companies[company_count].name, name);
        companies[company_count].stock_price = price;
        company_count++;
        printf("Added %s with stock price %.2f\n", name, price);
    } else {
        printf("Company list is full.\n");
    }
}

void update_stock_price(const char *name, float new_price) {
    for (int i = 0; i < company_count; i++) {
        if (strcmp(companies[i].name, name) == 0) {
            companies[i].stock_price = new_price;
            printf("Updated %s to new stock price %.2f\n", name, new_price);
            return;
        }
    }
    printf("Company %s not found.\n", name);
}

void display_all_companies() {
    printf("\n--- Company Stock Prices ---\n");
    for (int i = 0; i < company_count; i++) {
        printf("%s: $%.2f\n", companies[i].name, companies[i].stock_price);
    }
    printf("------------------------------\n");
}

int find_company_index(const char *name) {
    for (int i = 0; i < company_count; i++) {
        if (strcmp(companies[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void remove_company(const char *name) {
    int index = find_company_index(name);
    if (index != -1) {
        for (int i = index; i < company_count - 1; i++) {
            companies[i] = companies[i + 1];
        }
        company_count--;
        printf("Removed %s from the list.\n", name);
    } else {
        printf("Company %s not found.\n", name);
    }
}

void menu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Company\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Companies\n");
    printf("4. Remove Company\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char company_name[MAX_NAME_LENGTH];
    float stock_price;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter company name: ");
                scanf("%s", company_name);
                printf("Enter stock price: ");
                scanf("%f", &stock_price);
                add_company(company_name, stock_price);
                break;

            case 2:
                printf("Enter company name to update: ");
                scanf("%s", company_name);
                printf("Enter new stock price: ");
                scanf("%f", &stock_price);
                update_stock_price(company_name, stock_price);
                break;

            case 3:
                display_all_companies();
                break;

            case 4:
                printf("Enter company name to remove: ");
                scanf("%s", company_name);
                remove_company(company_name);
                break;

            case 5:
                printf("Exiting the Stock Market Tracker. Have a peaceful day!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
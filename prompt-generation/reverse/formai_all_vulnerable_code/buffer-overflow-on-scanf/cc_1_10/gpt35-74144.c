//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANY_NAME_LEN 30
#define MAX_NUM_COMPANIES 10
#define MAX_DAY_PRICE 25

typedef struct {
    char name[MAX_COMPANY_NAME_LEN];
    int prices[MAX_DAY_PRICE];
    int num_prices;
} Company;

int num_companies;
Company companies[MAX_NUM_COMPANIES];

/* function prototypes */
void add_company();
void list_companies();
void add_price();
void display_prices();
void display_high_low();

int main() {
    char choice;

    printf("Welcome to Scientific Stock Market Tracker!\n");

    /* loop until user chooses to exit */
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a new company\n");
        printf("2. List all companies\n");
        printf("3. Add stock price for a company\n");
        printf("4. Display prices of a company\n");
        printf("5. Display highest and lowest price of a company\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_company();
                break;

            case '2':
                list_companies();
                break;

            case '3':
                add_price();
                break;

            case '4':
                display_prices();
                break;

            case '5':
                display_high_low();
                break;

            case '6':
                printf("\nThank you for using Scientific Stock Market Tracker. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != '6');

    return 0;
}

void add_company() {
    /* create new company object */
    Company new_company;

    /* get company name */
    printf("\nEnter name of the company: ");
    scanf("%s", new_company.name);

    /* set number of prices to 0 */
    new_company.num_prices = 0;

    /* add company object to array */
    companies[num_companies++] = new_company;

    printf("Company added successfully.\n");
}

void list_companies() {
    int i;

    printf("\nList of companies:\n");

    /* loop through array and print company names */
    for(i = 0; i < num_companies; i++) {
        printf("%d. %s\n", i+1, companies[i].name);
    }

    if(num_companies == 0) {
        printf("No companies added yet!\n");
    }
}

void add_price() {
    int i, company_index, new_price;

    /* get company index */
    printf("\nEnter the index of the company: ");
    scanf("%d", &company_index);
    company_index--;

    /* check if company index is valid */
    if(company_index >= 0 && company_index < num_companies) {
        /* get new price */
        printf("Enter new stock price: ");
        scanf("%d", &new_price);

        /* add new price to company's array */
        companies[company_index].prices[companies[company_index].num_prices++] = new_price;

        printf("Price added successfully!\n");
    } else {
        printf("Invalid company index!\n");
    }
}

void display_prices() {
    int i, company_index;

    /* get company index */
    printf("\nEnter the index of the company: ");
    scanf("%d", &company_index);
    company_index--;

    /* check if company index is valid */
    if(company_index >= 0 && company_index < num_companies) {
        printf("\n%s's stock prices:\n", companies[company_index].name);

        /* loop through array and print prices */
        for(i = 0; i < companies[company_index].num_prices; i++) {
            printf("%d. %d\n", i+1, companies[company_index].prices[i]);
        }

        if(companies[company_index].num_prices == 0) {
            printf("No prices added yet!\n");
        }
    } else {
        printf("Invalid company index!\n");
    }
}

void display_high_low() {
    int i, company_index, max_price, min_price;

    /* get company index */
    printf("\nEnter the index of the company: ");
    scanf("%d", &company_index);
    company_index--;

    /* check if company index is valid */
    if(company_index >= 0 && company_index < num_companies) {
        /* set initial max and min prices to first price */
        max_price = companies[company_index].prices[0];
        min_price = companies[company_index].prices[0];

        /* loop through array and find max and min prices */
        for(i = 1; i < companies[company_index].num_prices; i++) {
            if(companies[company_index].prices[i] > max_price) {
                max_price = companies[company_index].prices[i];
            }

            if(companies[company_index].prices[i] < min_price) {
                min_price = companies[company_index].prices[i];
            }
        }

        printf("\n%s's highest price: %d\n", companies[company_index].name, max_price);
        printf("%s's lowest price: %d\n", companies[company_index].name, min_price);
    } else {
        printf("Invalid company index!\n");
    }
}
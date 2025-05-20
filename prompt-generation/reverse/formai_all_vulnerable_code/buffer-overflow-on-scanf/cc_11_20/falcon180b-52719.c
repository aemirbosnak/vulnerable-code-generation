//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_SHARES 1000

struct company {
    char name[20];
    float price;
    int shares;
};

int main() {
    int num_companies, i, j;
    scanf("%d", &num_companies);
    struct company companies[MAX_COMPANIES];

    for (i = 0; i < num_companies; i++) {
        scanf("%s", companies[i].name);
        scanf("%f", &companies[i].price);
        companies[i].shares = 0;
    }

    int num_shares;
    float total_value = 0;
    while (1) {
        printf("\nEnter the number of shares you want to buy/sell: ");
        scanf("%d", &num_shares);

        if (num_shares <= 0) {
            printf("Invalid input.\n");
            continue;
        }

        printf("Enter the company name: ");
        char company_name[20];
        scanf("%s", company_name);

        for (i = 0; i < num_companies; i++) {
            if (strcmp(company_name, companies[i].name) == 0) {
                break;
            }
        }

        if (i == num_companies) {
            printf("Company not found.\n");
            continue;
        }

        printf("Enter buy/sell: ");
        char operation[10];
        scanf("%s", operation);

        if (strcmp(operation, "buy") == 0) {
            if (companies[i].shares >= num_shares) {
                total_value += companies[i].price * num_shares;
                companies[i].shares -= num_shares;
            } else {
                printf("Not enough shares available.\n");
            }
        } else if (strcmp(operation, "sell") == 0) {
            if (companies[i].shares + num_shares <= MAX_SHARES) {
                total_value -= companies[i].price * num_shares;
                companies[i].shares += num_shares;
            } else {
                printf("Cannot exceed maximum shares.\n");
            }
        } else {
            printf("Invalid operation.\n");
        }
    }

    return 0;
}
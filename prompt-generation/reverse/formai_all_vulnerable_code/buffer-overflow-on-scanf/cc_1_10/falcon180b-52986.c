//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 10
#define MAX_SHARES 1000

struct company {
    char name[50];
    int shares;
    double price;
};

void main() {
    int numCompanies, i;
    struct company companies[MAX_COMPANIES];

    printf("Enter the number of companies: ");
    scanf("%d", &numCompanies);

    for (i = 0; i < numCompanies; i++) {
        printf("Enter the name of company %d: ", i+1);
        scanf("%s", companies[i].name);

        printf("Enter the number of shares for %s: ", companies[i].name);
        scanf("%d", &companies[i].shares);

        printf("Enter the current price per share for %s: ", companies[i].name);
        scanf("%lf", &companies[i].price);
    }

    char choice;
    do {
        printf("\nStock Market Tracker\n");
        printf("1. Buy shares\n");
        printf("2. Sell shares\n");
        printf("3. View portfolio\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the company: ");
                scanf("%s", companies[0].name);
                printf("Enter the number of shares to buy: ");
                scanf("%d", &companies[0].shares);
                printf("The current price per share for %s is $%.2lf.\n", companies[0].name, companies[0].price);
                break;
            case '2':
                printf("Enter the name of the company: ");
                scanf("%s", companies[0].name);
                printf("Enter the number of shares to sell: ");
                scanf("%d", &companies[0].shares);
                printf("The current price per share for %s is $%.2lf.\n", companies[0].name, companies[0].price);
                break;
            case '3':
                printf("\nYour Portfolio:\n");
                for (i = 0; i < numCompanies; i++) {
                    printf("%s: %d shares at $%.2lf\n", companies[i].name, companies[i].shares, companies[i].price);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');
}
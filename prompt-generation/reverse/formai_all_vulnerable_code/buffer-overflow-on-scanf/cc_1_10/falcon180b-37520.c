//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_SHARES 1000000

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    int shares;
    double price;
} company_t;

void print_menu() {
    printf("\n");
    printf("----- Romeo and Juliet's Stock Market Tracker -----\n");
    printf("1. Add a new company\n");
    printf("2. Buy shares\n");
    printf("3. Sell shares\n");
    printf("4. Check portfolio\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    int choice;
    int num_companies = 0;
    company_t companies[MAX_COMPANIES];

    printf("Welcome to Romeo and Juliet's Stock Market Tracker!\n");
    printf("Please choose an option from the menu:\n");

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_companies >= MAX_COMPANIES) {
                    printf("You have reached the maximum number of companies.\n");
                } else {
                    printf("Enter the name of the new company (up to %d characters): ", MAX_STOCK_NAME_LENGTH - 1);
                    scanf("%s", companies[num_companies].name);
                    companies[num_companies].shares = 0;
                    companies[num_companies].price = 0;
                    num_companies++;
                }
                break;
            case 2:
                printf("Enter the name of the company you want to buy shares from: ");
                scanf("%s", companies[0].name);
                printf("Enter the number of shares you want to buy: ");
                scanf("%d", &companies[0].shares);
                break;
            case 3:
                printf("Enter the name of the company you want to sell shares from: ");
                scanf("%s", companies[0].name);
                printf("Enter the number of shares you want to sell: ");
                scanf("%d", &companies[0].shares);
                break;
            case 4:
                printf("Your portfolio:\n");
                for (int i = 0; i < num_companies; i++) {
                    printf("%s: %d shares at $%.2f\n", companies[i].name, companies[i].shares, companies[i].price);
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
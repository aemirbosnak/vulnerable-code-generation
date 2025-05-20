//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_SHARES 1000

typedef struct {
    char name[50];
    int shares;
    double price;
} company_t;

void print_menu() {
    printf("\n");
    printf("Sherlock Holmes' Stock Market Tracker\n");
    printf("1. Add a company\n");
    printf("2. Buy shares\n");
    printf("3. Sell shares\n");
    printf("4. View portfolio\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    int choice, i;
    company_t companies[MAX_COMPANIES];
    memset(companies, 0, sizeof(companies));

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter company name: ");
                scanf("%s", companies[0].name);
                printf("Enter number of shares: ");
                scanf("%d", &companies[0].shares);
                printf("Enter initial price per share: ");
                scanf("%lf", &companies[0].price);
                break;
            case 2:
                printf("Enter company name: ");
                scanf("%s", companies[0].name);
                printf("Enter number of shares to buy: ");
                scanf("%d", &companies[0].shares);
                break;
            case 3:
                printf("Enter company name: ");
                scanf("%s", companies[0].name);
                printf("Enter number of shares to sell: ");
                scanf("%d", &companies[0].shares);
                break;
            case 4:
                printf("\n");
                for(i=0; i<MAX_COMPANIES; i++) {
                    if(companies[i].shares > 0) {
                        printf("Company: %s\n", companies[i].name);
                        printf("Shares: %d\n", companies[i].shares);
                        printf("Price per share: $%.2lf\n", companies[i].price);
                        printf("\n");
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
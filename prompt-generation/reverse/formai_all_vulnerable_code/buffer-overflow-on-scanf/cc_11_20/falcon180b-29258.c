//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_SHARES 1000

typedef struct {
    char name[50];
    int shares;
    float price;
} company_t;

int main() {
    int num_companies = 0;
    company_t companies[MAX_COMPANIES];
    char input[100];
    char temp[50];
    int i;
    int choice;

    do {
        printf("\nWelcome to the Stock Market Tracker!\n");
        printf("1. Add a company\n");
        printf("2. Buy shares\n");
        printf("3. Sell shares\n");
        printf("4. View portfolio\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the company: ");
                scanf("%s", temp);
                strcpy(companies[num_companies].name, temp);
                printf("Enter the number of shares: ");
                scanf("%d", &companies[num_companies].shares);
                printf("Enter the current price per share: ");
                scanf("%f", &companies[num_companies].price);
                num_companies++;
                break;
            case 2:
                printf("Enter the name of the company: ");
                scanf("%s", temp);
                for(i=0; i<num_companies; i++) {
                    if(strcmp(temp, companies[i].name) == 0) {
                        printf("Enter the number of shares to buy: ");
                        scanf("%d", &companies[i].shares);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter the name of the company: ");
                scanf("%s", temp);
                for(i=0; i<num_companies; i++) {
                    if(strcmp(temp, companies[i].name) == 0) {
                        printf("Enter the number of shares to sell: ");
                        scanf("%d", &companies[i].shares);
                        break;
                    }
                }
                break;
            case 4:
                printf("Your portfolio:\n");
                for(i=0; i<num_companies; i++) {
                    printf("%s: %d shares at $%.2f\n", companies[i].name, companies[i].shares, companies[i].price);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 5);

    return 0;
}
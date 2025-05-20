//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_COMPANIES 10
#define MAX_SHARES 1000

typedef struct {
    char name[50];
    float price;
    int shares;
} Company;

Company companies[MAX_COMPANIES];

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_COMPANIES; i++) {
        companies[i].price = rand() % 100;
        companies[i].shares = 0;
    }
}

void buy(int companyId, int shares) {
    if (companyId >= 0 && companyId < MAX_COMPANIES) {
        if (shares > 0 && shares <= MAX_SHARES) {
            if (companies[companyId].shares + shares <= MAX_SHARES) {
                companies[companyId].shares += shares;
                printf("You bought %d shares of %s for $%.2f per share.\n", shares, companies[companyId].name, companies[companyId].price);
            } else {
                printf("Sorry, there are not enough shares available.\n");
            }
        } else {
            printf("Invalid number of shares.\n");
        }
    } else {
        printf("Invalid company ID.\n");
    }
}

void sell(int companyId, int shares) {
    if (companyId >= 0 && companyId < MAX_COMPANIES) {
        if (shares > 0 && shares <= companies[companyId].shares) {
            companies[companyId].shares -= shares;
            printf("You sold %d shares of %s for $%.2f per share.\n", shares, companies[companyId].name, companies[companyId].price);
        } else {
            printf("Invalid number of shares or not enough shares owned.\n");
        }
    } else {
        printf("Invalid company ID.\n");
    }
}

void updatePrices() {
    for (int i = 0; i < MAX_COMPANIES; i++) {
        companies[i].price = rand() % 100;
    }
}

int main() {
    init();

    while (true) {
        system("clear");
        printf("Welcome to the Stock Market!\n");
        for (int i = 0; i < MAX_COMPANIES; i++) {
            printf("%d. %s - $%.2f (%d shares)\n", i + 1, companies[i].name, companies[i].price, companies[i].shares);
        }
        printf("\n");

        int choice;
        printf("Enter your choice:\n");
        printf("1. Buy\n");
        printf("2. Sell\n");
        printf("3. Update prices\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                int companyId, shares;
                printf("Enter company ID:\n");
                scanf("%d", &companyId);
                printf("Enter number of shares:\n");
                scanf("%d", &shares);
                buy(companyId, shares);
                break;
            }
        case 2:
            {
                int companyId, shares;
                printf("Enter company ID:\n");
                scanf("%d", &companyId);
                printf("Enter number of shares:\n");
                scanf("%d", &shares);
                sell(companyId, shares);
                break;
            }
        case 3:
            updatePrices();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
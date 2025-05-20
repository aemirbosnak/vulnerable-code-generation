//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMPANIES 10
#define MAX_SHARES 1000

struct {
    char name[50];
    float price;
    int shares;
} companies[MAX_COMPANIES];

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_COMPANIES; i++) {
        companies[i].name[0] = '\0';
        companies[i].price = rand() % 1000;
        companies[i].shares = rand() % MAX_SHARES;
    }
}

void print_companies() {
    printf("COMPANY\tPRICE\tSHARES\n");
    for (int i = 0; i < MAX_COMPANIES; i++) {
        if (companies[i].name[0]!= '\0') {
            printf("%s\t%.2f\t%d\n", companies[i].name, companies[i].price, companies[i].shares);
        }
    }
}

int main() {
    init();
    int choice;

    while (1) {
        printf("\n");
        printf("1. Buy Shares\n");
        printf("2. Sell Shares\n");
        printf("3. View Portfolio\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter company name: ");
            scanf("%s", companies[0].name);
            printf("Enter number of shares: ");
            scanf("%d", &companies[0].shares);
            break;

        case 2:
            printf("Enter company name: ");
            scanf("%s", companies[0].name);
            printf("Enter number of shares: ");
            scanf("%d", &companies[0].shares);
            break;

        case 3:
            print_companies();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
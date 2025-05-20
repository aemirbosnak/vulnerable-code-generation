//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define MAX_COMPANIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    double price;
} company;

company companies[MAX_COMPANIES];
int num_companies = 0;
int current_day = 1;
double total_worth = 0;

void add_company() {
    printf("Enter the name of the company:\n");
    scanf("%s", companies[num_companies].name);
    printf("Enter the current stock price:\n");
    scanf("%lf", &companies[num_companies].price);
    num_companies++;
}

void print_companies() {
    printf("\nCurrent Companies:\n");
    for (int i = 0; i < num_companies; i++) {
        printf("%s: $%.2lf\n", companies[i].name, companies[i].price);
    }
}

void main_menu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add a company\n");
    printf("2. View companies\n");
    printf("3. Exit\n");
}

int main() {
    setlocale(LC_ALL, "English");
    srand(time(NULL));

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        main_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_company();
                break;
            case 2:
                print_companies();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
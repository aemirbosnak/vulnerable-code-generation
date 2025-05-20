//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 100
#define NAME_LENGTH 50

struct Company {
    char name[NAME_LENGTH];
    double price;
    int shares;
};

void display_menu() {
    printf("Stock Market Tracker\n");
    printf("1. Add Company\n");
    printf("2. Update Price\n");
    printf("3. Display Companies\n");
    printf("4. Exit\n");
}

int add_company(struct Company companies[], int count) {
    if (count >= MAX_COMPANIES) {
        printf("Cannot add more companies!\n");
        return count;
    }
    printf("Enter company name: ");
    scanf("%s", companies[count].name);
    printf("Enter company price: ");
    scanf("%lf", &companies[count].price);
    printf("Enter number of shares: ");
    scanf("%d", &companies[count].shares);
    printf("Company added...\n");
    return count + 1;
}

void update_price(struct Company companies[], int count) {
    char name[NAME_LENGTH];
    printf("Enter the company name whose price you want to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(companies[i].name, name) == 0) {
            printf("Current price of %s: %.2lf\n", companies[i].name, companies[i].price);
            printf("Enter new price: ");
            scanf("%lf", &companies[i].price);
            printf("Price updated!\n");
            return;
        }
    }
    printf("Company not found!\n");
}

void display_companies(struct Company companies[], int count) {
    printf("List of Companies:\n");
    for (int i = 0; i < count; i++) {
        printf("Company: %s | Price: %.2lf | Shares: %d\n", companies[i].name, companies[i].price, companies[i].shares);
    }
}

int main() {
    struct Company companies[MAX_COMPANIES];
    int count = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                count = add_company(companies, count);
                break;
            case 2:
                update_price(companies, count);
                break;
            case 3:
                display_companies(companies, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
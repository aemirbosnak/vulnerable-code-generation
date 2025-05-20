//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LENGTH 50

struct company {
    char name[MAX_NAME_LENGTH];
    int stock_price;
    int age;
};

struct market {
    struct company companies[MAX_COMPANIES];
    int num_companies;
};

void add_company(struct market *m) {
    if (m->num_companies == MAX_COMPANIES) {
        printf("Cannot add more companies to the market.\n");
        return;
    }

    printf("Enter company name: ");
    scanf("%s", m->companies[m->num_companies].name);

    printf("Enter company stock price: ");
    scanf("%d", &m->companies[m->num_companies].stock_price);

    printf("Enter company age: ");
    scanf("%d", &m->companies[m->num_companies].age);

    m->num_companies++;
}

void remove_company(struct market *m) {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;

    printf("Enter name of company to remove: ");
    scanf("%s", name);

    for (i = 0; i < m->num_companies; i++) {
        if (strcmp(name, m->companies[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Company not found.\n");
        return;
    }

    for (; i < m->num_companies - 1; i++) {
        strcpy(m->companies[i].name, m->companies[i+1].name);
        m->companies[i].stock_price = m->companies[i+1].stock_price;
        m->companies[i].age = m->companies[i+1].age;
    }

    m->num_companies--;

    printf("Company removed.\n");
}

void display_companies(struct market *m) {
    int i;

    printf("COMPANIES IN THE MARKET:\n");
    for (i = 0; i < m->num_companies; i++) {
        printf("  Company name: %s\n", m->companies[i].name);
        printf("  Stock price: %d\n", m->companies[i].stock_price);
        printf("  Age: %d\n\n", m->companies[i].age);
    }
}

void display_menu() {
    printf("OPTIONS:\n");
    printf("  1: Add company\n");
    printf("  2: Remove company\n");
    printf("  3: Display companies\n");
    printf("  4: Quit\n");
}

int main() {
    struct market m = {0};
    int choice;

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_company(&m);
                break;
            case 2:
                remove_company(&m);
                break;
            case 3:
                display_companies(&m);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
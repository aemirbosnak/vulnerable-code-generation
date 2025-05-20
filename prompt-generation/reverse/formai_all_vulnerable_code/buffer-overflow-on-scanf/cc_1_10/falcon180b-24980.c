//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct expense {
    char category[50];
    char description[100];
    double amount;
    char date[20];
};

void add_expense(struct expense *expenses, int num_expenses, char *category, char *description, double amount, char *date) {
    int i;
    for (i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            expenses[i].amount += amount;
            return;
        }
    }
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);
    num_expenses++;
}

void display_expenses(struct expense *expenses, int num_expenses) {
    int i;
    printf("Category\tDescription\tAmount\tDate\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\t%s\n", expenses[i].category, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    int num_expenses = 0;
    struct expense expenses[100];
    char category[50];
    char description[100];
    double amount;
    char date[20];
    char choice;

    do {
        printf("Enter expense category (or 'Q' to quit): ");
        scanf("%s", category);
        if (tolower(category[0])!= 'q') {
            printf("Enter expense description: ");
            scanf("%s", description);
            printf("Enter expense amount: ");
            scanf("%lf", &amount);
            printf("Enter expense date (YYYY-MM-DD): ");
            scanf("%s", date);
            add_expense(expenses, num_expenses, category, description, amount, date);
            num_expenses++;
        } else {
            printf("Exiting program...\n");
        }
    } while (tolower(category[0])!= 'q');

    printf("Expenses:\n");
    display_expenses(expenses, num_expenses);

    return 0;
}
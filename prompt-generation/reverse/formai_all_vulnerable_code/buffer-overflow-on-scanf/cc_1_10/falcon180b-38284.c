//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[50];
    char description[100];
    float amount;
    char date[20];
};

void add_expense(struct expense* expenses, int num_expenses, char category[50], char description[100], float amount, char date[20]) {
    if (num_expenses >= 100) {
        printf("Sorry, you can only track up to 100 expenses. ");
        return;
    }
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);
    num_expenses++;
}

void display_expenses(struct expense* expenses, int num_expenses) {
    printf("Expense Tracker\n");
    printf("=================\n");
    printf("Category\tDescription\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\t%s\n", expenses[i].category, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    struct expense expenses[100];
    int num_expenses = 0;
    char category[50];
    char description[100];
    float amount;
    char date[20];

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your expenses one by one.\n");

    while (1) {
        printf("Enter expense category (e.g. Food, Entertainment, etc.): ");
        scanf("%s", category);

        printf("Enter expense description (e.g. Dinner at McDonald's, Movie ticket, etc.): ");
        scanf("%[^\n]", description);

        printf("Enter expense amount: ");
        scanf("%f", &amount);

        printf("Enter expense date (YYYY-MM-DD): ");
        scanf("%s", date);

        add_expense(expenses, num_expenses, category, description, amount, date);
        num_expenses++;

        char choice;
        printf("Do you want to add another expense? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    display_expenses(expenses, num_expenses);

    return 0;
}
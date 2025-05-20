//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct expense {
    char description[80];
    double amount;
    time_t date;
};

struct expense expenses[100];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= 100) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: $");
    if (scanf("%lf", &expenses[num_expenses].amount)!= 1) {
        printf("Error: Invalid input.\n");
        return;
    }

    time_t now = time(NULL);
    strftime(expenses[num_expenses].date, 80, "%Y-%m-%d %H:%M:%S", localtime(&now));

    num_expenses++;
    printf("Expense added successfully.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Expense Date       Description        Amount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s %s $%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
    }
}

void search_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    char search_term[80];
    printf("Enter search term: ");
    scanf("%s", search_term);

    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, search_term)!= NULL) {
            printf("%s %s $%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expenses\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expenses();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
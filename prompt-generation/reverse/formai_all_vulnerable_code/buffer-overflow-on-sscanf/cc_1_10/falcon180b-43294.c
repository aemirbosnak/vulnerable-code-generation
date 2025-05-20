//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
} expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

int main() {
    int num_categories = 0;
    category categories[MAX_CATEGORIES];
    char input[100];

    while (1) {
        printf("Enter a category name (or 'q' to quit):\n");
        fgets(input, 100, stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        strcpy(categories[num_categories].name, input);
        categories[num_categories].num_expenses = 0;
        num_categories++;
    }

    int curr_category = 0;
    while (curr_category < num_categories) {
        printf("Enter an expense for %s (or 'n' to go to next category):\n", categories[curr_category].name);
        fgets(input, 100, stdin);

        if (strcmp(input, "n") == 0) {
            curr_category++;
        } else {
            expense new_expense;
            strcpy(new_expense.name, input);
            sscanf(input, "%s $%lf", new_expense.name, &new_expense.amount);

            if (categories[curr_category].num_expenses >= MAX_EXPENSES) {
                printf("Error: Category '%s' has reached maximum number of expenses.\n", categories[curr_category].name);
            } else {
                categories[curr_category].expenses[categories[curr_category].num_expenses++] = new_expense;
            }
        }
    }

    printf("Expenses by category:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (int j = 0; j < categories[i].num_expenses; j++) {
            printf("  %s: $%.2lf\n", categories[i].expenses[j].name, categories[i].expenses[j].amount);
        }
    }

    return 0;
}
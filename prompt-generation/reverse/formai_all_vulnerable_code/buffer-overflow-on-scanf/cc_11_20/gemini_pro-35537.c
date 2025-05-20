//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    double amount;
} expense_t;

typedef struct {
    char name[50];
    double total;
} category_t;

int main() {
    expense_t expenses[MAX_EXPENSES];
    category_t categories[MAX_CATEGORIES];
    int num_expenses = 0;
    int num_categories = 0;
    char input[100];
    double total_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1) Add an expense\n");
        printf("2) Add a category\n");
        printf("3) Print expenses\n");
        printf("4) Print categories\n");
        printf("5) Quit\n");

        fgets(input, sizeof(input), stdin);

        switch (input[0]) {
            case '1':
                if (num_expenses == MAX_EXPENSES) {
                    printf("Error: Maximum number of expenses reached.\n");
                } else {
                    printf("Enter the name of the expense: ");
                    fgets(expenses[num_expenses].name, sizeof(expenses[num_expenses].name), stdin);
                    printf("Enter the amount of the expense: ");
                    scanf("%lf", &expenses[num_expenses].amount);
                    total_expenses += expenses[num_expenses].amount;
                    num_expenses++;
                }
                break;
            case '2':
                if (num_categories == MAX_CATEGORIES) {
                    printf("Error: Maximum number of categories reached.\n");
                } else {
                    printf("Enter the name of the category: ");
                    fgets(categories[num_categories].name, sizeof(categories[num_categories].name), stdin);
                    categories[num_categories].total = 0;
                    num_categories++;
                }
                break;
            case '3':
                printf("\nExpenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s $%.2f\n", expenses[i].name, expenses[i].amount);
                }
                printf("Total expenses: $%.2f\n", total_expenses);
                break;
            case '4':
                printf("\nCategories:\n");
                for (int i = 0; i < num_categories; i++) {
                    printf("%s $%.2f\n", categories[i].name, categories[i].total);
                }
                break;
            case '5':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct expense {
    int day;
    int month;
    int year;
    float amount;
    char category[20];
};

void add_expense(struct expense *expenses, int *num_expenses)
{
    printf("Enter the day (1-31): ");
    scanf("%d", &expenses[*num_expenses].day);
    printf("Enter the month (1-12): ");
    scanf("%d", &expenses[*num_expenses].month);
    printf("Enter the year (2000-2021): ");
    scanf("%d", &expenses[*num_expenses].year);
    printf("Enter the amount (e.g., 10.99): ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter the category (e.g., groceries): ");
    scanf("%s", expenses[*num_expenses].category);
    (*num_expenses)++;
    printf("Expense added!\n\n");
}

void print_expenses(struct expense *expenses, int num_expenses)
{
    printf("Expenses:\n");
    printf("Day     Month   Year    Amount  Category\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-7d%-8d%-8d%-8.2f%s\n",
            expenses[i].day, expenses[i].month, expenses[i].year,
            expenses[i].amount, expenses[i].category);
    }
    printf("\n");
}

int main()
{
    struct expense *expenses = NULL;
    int num_expenses = 0;
    char action;

    while (1) {
        printf("Add expense (a), print expenses (p), or quit (q): ");
        scanf(" %c", &action);
        switch (action) {
            case 'a':
                add_expense(expenses, &num_expenses);
                expenses = realloc(expenses, (num_expenses + 1) * sizeof(struct expense));
                break;
            case 'p':
                print_expenses(expenses, num_expenses);
                break;
            case 'q':
                printf("Goodbye!\n");
                free(expenses);
                return 0;
            default:
                printf("Invalid action!\n");
        }
    }
}
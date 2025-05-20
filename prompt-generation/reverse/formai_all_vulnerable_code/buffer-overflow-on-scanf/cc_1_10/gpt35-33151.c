//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 20

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char description[50];
    float amount;
    Date date;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0;

    printf("Welcome to Expense Tracker!\n\n");

    while (1) {
        char choice;

        printf("Choose an option:\n");
        printf("A) Add an expense\n");
        printf("B) View all expenses\n");
        printf("C) See total expenses\n");
        printf("Q) Quit\n");
        printf(">>> ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A': {
                Expense expense;
                printf("\nEnter Expense Details:\n");
                printf("Description: ");
                scanf(" %s", expense.description);
                printf("Amount: ");
                scanf("%f", &expense.amount);
                printf("Date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &expense.date.day, &expense.date.month, &expense.date.year);
                expenses[numExpenses++] = expense;
                totalExpenses += expense.amount;
                printf("\nExpense added successfully!\n\n");
                break;
            }
            case 'B': {
                printf("\nAll Expenses:\n\n");
                printf("Description\tAmount\tDate\n");
                for (int i = 0; i < numExpenses; i++) {
                    printf("%s\t%.2f\t%d/%d/%d\n", expenses[i].description, expenses[i].amount, expenses[i].date.day, expenses[i].date.month, expenses[i].date.year);
                }
                printf("\n");
                break;
            }
            case 'C': {
                printf("\nTotal Expenses: %.2f\n\n", totalExpenses);
                break;
            }
            case 'Q': {
                printf("\nGoodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Try again.\n\n");
                break;
            }
        }
    }

    return 0;
}
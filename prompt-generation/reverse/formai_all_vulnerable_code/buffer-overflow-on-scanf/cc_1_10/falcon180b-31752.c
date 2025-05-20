//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char category[50];
    char date[20];
} expense;

void add_expense(expense* expenses, int* num_expenses) {
    char input[100];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[*num_expenses].name, input);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);
    strcpy(expenses[*num_expenses].category, input);

    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%s", expenses[*num_expenses].date);

    (*num_expenses)++;
}

void display_expenses(expense* expenses, int num_expenses) {
    printf("Name\tAmount\tCategory\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2lf\t%s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void filter_expenses(expense* expenses, int num_expenses, char* category) {
    int filtered_num_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%s\t%.2lf\t%s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
            filtered_num_expenses++;
        }
    }
    printf("\nTotal expenses in %s category: %d\n", category, filtered_num_expenses);
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        char choice;
        printf("\nDo you want to add an expense? (y/n): ");
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_expense(expenses, &num_expenses);
        } else if (choice == 'f' || choice == 'F') {
            char category[50];
            printf("Enter expense category to filter by: ");
            scanf("%s", category);
            filter_expenses(expenses, num_expenses, category);
        } else if (choice == 'q' || choice == 'Q') {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
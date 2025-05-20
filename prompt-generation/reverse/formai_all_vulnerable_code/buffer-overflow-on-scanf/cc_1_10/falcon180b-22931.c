//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    float amount;
    time_t date;
} Expense;

void add_expense(Expense* expenses, int num_expenses) {
    char category[50];
    char description[100];
    float amount;
    time_t date;

    printf("Enter expense category: ");
    scanf("%s", category);

    printf("Enter expense description: ");
    scanf("%s", description);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    date = time(NULL);

    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("\nExpense Report\n");
    printf("Category\tDescription\tAmount\tDate\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\t%s\n", expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (num_expenses < MAX_EXPENSES) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
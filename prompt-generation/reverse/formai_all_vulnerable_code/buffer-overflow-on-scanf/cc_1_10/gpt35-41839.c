//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_header();
void add_expense();
void view_all_expenses();
void view_expense_by_category();
void view_expense_by_date();
void view_expense_by_amount();

struct Expense {
    char date[20];
    char category[20];
    float amount;
} expense;

int main() {
    int choice;
    do {
        print_header();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_all_expenses();
                break;
            case 3:
                view_expense_by_category();
                break;
            case 4:
                view_expense_by_date();
                break;
            case 5:
                view_expense_by_amount();
                break;
            case 6:
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void print_header() {
    system("clear");
    printf("*******************************************\n");
    printf("*          WELCOME TO EXPENSE TRACKER      *\n");
    printf("*******************************************\n\n");
    printf("1. Add Expense\n");
    printf("2. View all Expenses\n");
    printf("3. View Expense by Category\n");
    printf("4. View Expense by Date\n");
    printf("5. View Expense by Amount\n");
    printf("6. Exit\n");
}

void add_expense() {
    printf("\nEnter expense date (dd/mm/yyyy): ");
    scanf("%s", expense.date);
    printf("\nEnter expense category: ");
    scanf("%s", expense.category);
    printf("\nEnter expense amount: ");
    scanf("%f", &expense.amount);

    FILE *file = fopen("expenses.txt", "a+");
    fprintf(file, "%s %s %.2f\n", expense.date, expense.category, expense.amount);
    fclose(file);

    printf("\nExpense added successfully!\n");
}

void view_all_expenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("\nNo expenses found!\n");
    } else {
        printf("\nExpense Date\tCategory\tAmount\n");
        printf("--------------------------------------------------\n");
        while (!feof(file)) {
            fscanf(file, "%s %s %f", expense.date, expense.category, &expense.amount);
            printf("%s\t%s\t%.2f\n", expense.date, expense.category, expense.amount);
        }
        fclose(file);
    }
}

void view_expense_by_category() {
    char category[20];
    printf("\nEnter category: ");
    scanf("%s", category);

    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("\nNo expenses found!\n");
    } else {
        printf("\nExpense Date\tCategory\tAmount\n");
        printf("--------------------------------------------------\n");
        while (!feof(file)) {
            fscanf(file, "%s %s %f", expense.date, expense.category, &expense.amount);
            if (strcmp(expense.category, category) == 0) {
                printf("%s\t%s\t%.2f\n", expense.date, expense.category, expense.amount);
            }
        }
        fclose(file);
    }
}

void view_expense_by_date() {
    char date[20];
    printf("\nEnter date (dd/mm/yyyy): ");
    scanf("%s", date);

    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("\nNo expenses found!\n");
    } else {
        printf("\nExpense Date\tCategory\tAmount\n");
        printf("--------------------------------------------------\n");
        while (!feof(file)) {
            fscanf(file, "%s %s %f", expense.date, expense.category, &expense.amount);
            if (strcmp(expense.date, date) == 0) {
                printf("%s\t%s\t%.2f\n", expense.date, expense.category, expense.amount);
            }
        }
        fclose(file);
    }
}

void view_expense_by_amount() {
    float amount;
    printf("\nEnter amount: ");
    scanf("%f", &amount);

    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("\nNo expenses found!\n");
    } else {
        printf("\nExpense Date\tCategory\tAmount\n");
        printf("--------------------------------------------------\n");
        while (!feof(file)) {
            fscanf(file, "%s %s %f", expense.date, expense.category, &expense.amount);
            if (expense.amount == amount) {
                printf("%s\t%s\t%.2f\n", expense.date, expense.category, expense.amount);
            }
        }
        fclose(file);
    }
}
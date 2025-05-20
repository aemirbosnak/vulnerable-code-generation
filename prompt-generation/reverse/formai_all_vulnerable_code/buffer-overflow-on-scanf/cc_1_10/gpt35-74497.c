//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char name[50];
    float amount;
    char category[20];
    int day;
    int month;
    int year;
};

void print_menu();
void add_expense(struct expense expenses[], int *num_expenses);
void show_expenses(struct expense expenses[], int num_expenses);
void find_expense_by_name(struct expense expenses[], int num_expenses, char search_name[]);
void find_expense_by_category(struct expense expenses[], int num_expenses, char search_category[]);
void find_expense_by_date(struct expense expenses[], int num_expenses, int search_day, int search_month, int search_year);

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    int option;

    do {
        print_menu();
        printf("Enter an option: ");
        scanf("%d", &option);
        printf("\n");

        switch(option) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                show_expenses(expenses, num_expenses);
                break;
            case 3:
                find_expense_by_name(expenses, num_expenses, "Name");
                break;
            case 4:
                find_expense_by_category(expenses, num_expenses, "Category");
                break;
            case 5:
                printf("Enter search date (dd-mm-yyyy): ");
                int search_day, search_month, search_year;
                scanf("%d-%d-%d", &search_day, &search_month, &search_year);
                find_expense_by_date(expenses, num_expenses, search_day, search_month, search_year);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }

        printf("\n");
    } while (option != 0);

    return 0;
}

void print_menu() {
    printf("Expense Tracker\n");
    printf("----------------\n");
    printf("1. Add expense\n");
    printf("2. Show all expenses\n");
    printf("3. Find expense by name\n");
    printf("4. Find expense by category\n");
    printf("5. Find expense by date\n");
    printf("0. Exit\n");
}

void add_expense(struct expense expenses[], int *num_expenses) {
    if (*num_expenses == MAX_EXPENSES) {
        printf("Max number of expenses reached.\n");
        return;
    }

    struct expense new_expense;

    printf("Enter expense name: ");
    scanf("%s", new_expense.name);

    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    printf("Enter expense category: ");
    scanf("%s", new_expense.category);

    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &new_expense.day, &new_expense.month, &new_expense.year);

    expenses[*num_expenses] = new_expense;
    (*num_expenses)++;

    printf("Expense added successfully.\n");
}

void show_expenses(struct expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("All expenses:\n");
    printf("%-20s %-20s %-10s %-10s %-10s\n", "Name", "Category", "Amount", "Day", "Month", "Year");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s %-20s %-10.2f %-10d %-10d %-10d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
    }
}

void find_expense_by_name(struct expense expenses[], int num_expenses, char search_name[]) {
    int count = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("%-20s %-20s %-10.2f %-10d %-10d %-10d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
            count++;
        }
    }

    if (count == 0) {
        printf("No expenses found with name '%s'.\n", search_name);
    }
}

void find_expense_by_category(struct expense expenses[], int num_expenses, char search_category[]) {
    int count = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, search_category) == 0) {
            printf("%-20s %-20s %-10.2f %-10d %-10d %-10d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
            count++;
        }
    }

    if (count == 0) {
        printf("No expenses found with category '%s'.\n", search_category);
    }
}

void find_expense_by_date(struct expense expenses[], int num_expenses, int search_day, int search_month, int search_year) {
    int count = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].day == search_day && expenses[i].month == search_month && expenses[i].year == search_year) {
            printf("%-20s %-20s %-10.2f %-10d %-10d %-10d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
            count++;
        }
    }

    if (count == 0) {
        printf("No expenses found on %d/%d/%d.\n", search_day, search_month, search_year);
    }
}
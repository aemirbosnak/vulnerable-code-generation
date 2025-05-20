//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    int day;
    int month;
    int year;
    double amount;
    char category[20];
};

int get_choice();
void add_expense();
void display_expenses();
void save_expenses();
void load_expenses();

struct Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

int main() {
    int choice;

    load_expenses();
    
    do {
        choice = get_choice();

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                save_expenses();
                break;
            case 4:
                load_expenses();
                break;
            case 5:
                printf("Exiting expense tracker.\n");
                break;
            default:
                printf("Invalid choice. Enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

int get_choice() {
    int choice;

    printf("\nExpense Tracker Menu:\n");
    printf("1. Add expense\n");
    printf("2. Display expenses\n");
    printf("3. Save expenses to file\n");
    printf("4. Load expenses from file\n");
    printf("5. Quit\n\n");

    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    return choice;
}

void add_expense() {
    struct Expense expense;

    printf("\nEnter expense details:\n");
    printf("Day (1-31): ");
    scanf("%d", &expense.day);

    printf("Month (1-12): ");
    scanf("%d", &expense.month);

    printf("Year: ");
    scanf("%d", &expense.year);

    printf("Amount: $");
    scanf("%lf", &expense.amount);

    printf("Category: ");
    scanf("%s", expense.category);

    expenses[num_expenses++] = expense;

    printf("\nExpense added successfully.\n");
}

void display_expenses() {
    int i;

    if (num_expenses == 0) {
        printf("\nNo expenses added yet.\n");
    } else {
        printf("\nExpenses:\n");
        printf("Day\tMonth\tYear\tAmount\tCategory\n");

        for (i = 0; i < num_expenses; i++) {
            printf("%d\t%d\t%d\t%.2lf\t%s\n", expenses[i].day, expenses[i].month,
                   expenses[i].year, expenses[i].amount, expenses[i].category);
        }
    }
}

void save_expenses() {
    FILE *file;
    int i;
    char filename[50];

    printf("\nEnter a filename to save your expenses to: ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        for (i = 0; i < num_expenses; i++) {
            fprintf(file, "%d,%d,%d,%.2lf,%s\n", expenses[i].day, expenses[i].month,
                    expenses[i].year, expenses[i].amount, expenses[i].category);
        }

        fclose(file);

        printf("\nExpenses saved to %s.\n", filename);
    }
}

void load_expenses() {
    FILE *file;
    int i;
    char filename[50];
    struct Expense expense;
    
    printf("\nEnter a filename to load your expenses from: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        num_expenses = 0;

        while (fscanf(file, "%d,%d,%d,%lf,%s", &expense.day, &expense.month,
                &expense.year, &expense.amount, expense.category) == 5) {
            expenses[num_expenses++] = expense;
        }

        fclose(file);

        printf("\nExpenses loaded from %s.\n", filename);
    }
}
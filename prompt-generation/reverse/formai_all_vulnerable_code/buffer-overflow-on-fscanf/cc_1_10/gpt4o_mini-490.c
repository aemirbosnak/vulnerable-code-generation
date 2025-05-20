//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    char date[11];  // Format: YYYY-MM-DD
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }
    
    Expense new_expense;

    printf("Enter name of the expense: ");
    scanf("%s", new_expense.name);
    
    printf("Enter category of the expense: ");
    scanf("%s", new_expense.category);

    printf("Enter amount of the expense: ");
    scanf("%f", &new_expense.amount);

    printf("Enter date of the expense (YYYY-MM-DD): ");
    scanf("%s", new_expense.date);

    expenses[expense_count] = new_expense;
    expense_count++;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    printf("\nExpenses:\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Category", "Amount", "Date");
    
    for (int i = 0; i < expense_count; i++) {
        printf("%-20s %-20s %-10.2f %-10s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void save_expenses() {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error saving expenses!\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s,%s,%.2f,%s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    fclose(file);
    printf("Expenses saved successfully!\n");
}

void load_expenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No saved expenses found.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%29[^,],%f,%10s\n", expenses[expense_count].name, expenses[expense_count].category, &expenses[expense_count].amount, expenses[expense_count].date) == 4) {
        expense_count++;
        if (expense_count >= MAX_EXPENSES) {
            printf("Expense list reached maximum capacity while loading.\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void display_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Load Expenses\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;

    load_expenses();

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                save_expenses();
                break;
            case 4:
                load_expenses();
                break;
            case 5:
                save_expenses();
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char category[50];
    float amount;
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseList;

void init_expense_list(ExpenseList *list) {
    list->count = 0;
}

void add_expense(ExpenseList *list) {
    if (list->count >= MAX_ENTRIES) {
        printf("\nExpense list is full! Cannot add more entries.\n");
        return;
    }

    Expense expense;

    printf("\nEnter expense category: ");
    scanf("%s", expense.category);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);

    list->entries[list->count] = expense;
    list->count++;
    printf("Expense added successfully!\n");
}

void view_expenses(ExpenseList *list) {
    if (list->count == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    printf("\nExpense List:\n");
    printf("%-20s %s\n", "Category", "Amount");
    printf("==================== ==========\n");
    for (int i = 0; i < list->count; i++) {
        printf("%-20s $%.2f\n", list->entries[i].category, list->entries[i].amount);
    }
}

void calculate_total(ExpenseList *list) {
    float total = 0;
    for (int i = 0; i < list->count; i++) {
        total += list->entries[i].amount;
    }
    printf("\nTotal Expenses: $%.2f\n", total);
}

void save_expenses(ExpenseList *list) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("\nError opening file for saving expenses.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s %.2f\n", list->entries[i].category, list->entries[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void load_expenses(ExpenseList *list) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("\nNo saved expenses found.\n");
        return;
    }

    while (fscanf(file, "%s %f", list->entries[list->count].category, &list->entries[list->count].amount) != EOF) {
        list->count++;
        if (list->count >= MAX_ENTRIES) {
            printf("Expense list full. Cannot load more entries.\n");
            break;
        }
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("========================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("========================\n");
}

int main() {
    ExpenseList myExpenses;
    init_expense_list(&myExpenses);
    load_expenses(&myExpenses);

    int choice;
    do {
        display_menu();
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&myExpenses);
                break;
            case 2:
                view_expenses(&myExpenses);
                break;
            case 3:
                calculate_total(&myExpenses);
                break;
            case 4:
                save_expenses(&myExpenses);
                break;
            case 5:
                load_expenses(&myExpenses);
                break;
            case 6:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_SIZE 20
#define DESCRIPTION_SIZE 100

typedef struct {
    char category[CATEGORY_SIZE];
    char description[DESCRIPTION_SIZE];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense new_expense;
    printf("Enter Expense Category: ");
    scanf("%s", new_expense.category);
    printf("Enter Expense Description: ");
    scanf(" %[^\n]", new_expense.description);
    printf("Enter Expense Amount: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count] = new_expense;
    expense_count++;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n%-20s %-30s %s\n", "Category", "Description", "Amount");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%-20s %-30s %.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void total_expenses() {
    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void save_expenses_to_file() {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s\t%s\t%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to 'expenses.txt'.\n");
}

void load_expenses_from_file() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No saved expenses found or error opening file.\n");
        return;
    }

    while (fscanf(file, "%s\t%s\t%f\n", expenses[expense_count].category, expenses[expense_count].description, &expenses[expense_count].amount) != EOF) {
        expense_count++;
        if (expense_count >= MAX_EXPENSES) {
            printf("Maximum expense count reached, some entries may not be loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded successfully.\n");
}

void menu() {
    int choice;
    do {
        printf("\n=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                total_expenses();
                break;
            case 4:
                save_expenses_to_file();
                break;
            case 5:
                load_expenses_from_file();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_COMMENT_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
    char comment[MAX_COMMENT_LEN];
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        fprintf(stderr, "Warning: Maximum expense limit reached! Can't add more.\n");
        return;
    }

    Expense new_expense;

    printf("Enter the name of the expense: ");
    if (fgets(new_expense.name, MAX_NAME_LEN, stdin) == NULL) {
        fprintf(stderr, "Warning: Invalid input encountered while entering the name of the expense.\n");
        return;
    }
    new_expense.name[strcspn(new_expense.name, "\n")] = 0; // Remove newline character

    char amount_str[20];
    printf("Enter the amount of the expense: ");
    if (fgets(amount_str, sizeof(amount_str), stdin) == NULL) {
        fprintf(stderr, "Warning: Invalid input encountered while entering the amount.\n");
        return;
    }
    if (sscanf(amount_str, "%f", &new_expense.amount) != 1 || new_expense.amount < 0) {
        fprintf(stderr, "Warning: Amount must be a non-negative number! Input ignored.\n");
        return;
    }

    printf("Enter a comment for the expense (optional): ");
    if (fgets(new_expense.comment, MAX_COMMENT_LEN, stdin) != NULL) {
        new_expense.comment[strcspn(new_expense.comment, "\n")] = 0; // Remove newline character
    } else {
        fprintf(stderr, "Warning: Invalid input encountered while entering the comment.\n");
        return;
    }

    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void list_expenses() {
    if (expense_count == 0) {
        fprintf(stderr, "Warning: No expenses recorded yet! List is empty.\n");
        return;
    }

    printf("Listing all expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense #%d: %s - $%.2f, Comment: %s\n", 
               i + 1, expenses[i].name, expenses[i].amount, expenses[i].comment);
    }
}

void delete_expense() {
    if (expense_count == 0) {
        fprintf(stderr, "Warning: No expenses to delete! Operation aborted.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1 to %d): ", expense_count);
    char index_str[10];
    if (fgets(index_str, sizeof(index_str), stdin) == NULL ||
        sscanf(index_str, "%d", &index) != 1 || index < 1 || index > expense_count) {
        fprintf(stderr, "Warning: Invalid index input! Deletion operation canceled.\n");
        return;
    }

    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    printf("Expense #%d deleted successfully!\n", index);
}

void save_to_file() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        fprintf(stderr, "Warning: Could not open file for writing! Check permissions.\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s|%.2f|%s\n", expenses[i].name, expenses[i].amount, expenses[i].comment);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        fprintf(stderr, "Warning: Could not open file for reading! File may not exist.\n");
        return;
    }

    while (fscanf(file, "%[^|]|%f|%[^|\n]\n", 
                  expenses[expense_count].name,
                  &expenses[expense_count].amount,
                  expenses[expense_count].comment) == 3) {
        expense_count++;
        if (expense_count >= MAX_EXPENSES) break;
    }
    fclose(file);
    printf("Expenses loaded successfully! %d expenses added.\n", expense_count);
}

void show_menu() {
    while (1) {
        printf("\nExpense Tracker:\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Save Expenses\n");
        printf("5. Load Expenses\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        char choice_str[10];
        if (fgets(choice_str, sizeof(choice_str), stdin) == NULL) {
            fprintf(stderr, "Warning: Invalid input for menu choice!\n");
            continue;
        }

        int choice;
        if (sscanf(choice_str, "%d", &choice) != 1 || choice < 1 || choice > 6) {
            fprintf(stderr, "Warning: Choice must be between 1 and 6! Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1: add_expense(); break;
            case 2: list_expenses(); break;
            case 3: delete_expense(); break;
            case 4: save_to_file(); break;
            case 5: load_from_file(); break;
            case 6: printf("Exiting... Stay safe!\n"); return;
        }
    }
}

int main() {
    printf("Welcome to the Paranoid Expense Tracker! Guard your finances zealously!\n");
    show_menu();
    return 0;
}
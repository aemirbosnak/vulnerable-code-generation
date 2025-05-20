//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void load_expenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        return; // No file to load, simply exit
    }
    while (fscanf(file, "%49[^,],%f\n", expenses[expense_count].description, &expenses[expense_count].amount) != EOF) {
        expense_count++;
    }
    fclose(file);
}

void save_expenses() {
    FILE *file = fopen("expenses.txt", "w");
    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s,%.2f\n", expenses[i].description, expenses[i].amount);
    }
    fclose(file);
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }
    printf("Enter expense description: ");
    scanf("%s", expenses[expense_count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);
    expense_count++;
    save_expenses();
    printf("Expense added successfully!\n");
}

void view_expenses() {
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("--------------------\n");
}

void delete_expense() {
    int index;
    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > expense_count) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    save_expenses();
    printf("Expense deleted successfully!\n");
}

void calculate_total() {
    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

int main() {
    load_expenses();
    int choice;
    
    while (1) {
        printf("\n---- Expense Tracker Menu ----\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Calculate Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                calculate_total();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
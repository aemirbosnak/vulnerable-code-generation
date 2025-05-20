//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define CATEGORY_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    double amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initialize(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void add_expense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Expense tracker is full!\n");
        return;
    }
    Expense new_expense;
    
    printf("Enter expense name: ");
    scanf(" %[^\n]%*c", new_expense.name);
    
    printf("Enter category: ");
    scanf(" %[^\n]%*c", new_expense.category);
    
    printf("Enter amount: ");
    scanf("%lf", &new_expense.amount);
    
    tracker->expenses[tracker->count++] = new_expense;
    printf("Expense added successfully!\n");
}

void display_expenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Name: %s | Category: %s | Amount: %.2f\n",
            tracker->expenses[i].name,
            tracker->expenses[i].category,
            tracker->expenses[i].amount);
    }
}

void calculate_total(const ExpenseTracker *tracker) {
    double total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void save_to_file(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%s,%.2f\n", tracker->expenses[i].name,
                tracker->expenses[i].category,
                tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void load_from_file(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No saved expenses found.\n");
        return;
    }
    
    while (tracker->count < MAX_ENTRIES && !feof(file)) {
        Expense exp;
        fscanf(file, " %49[^,],%29[^,],%lf\n", exp.name, exp.category, &exp.amount);
        tracker->expenses[tracker->count++] = exp;
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void display_menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initialize(&tracker);
    load_from_file(&tracker);
    
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                display_expenses(&tracker);
                break;
            case 3:
                calculate_total(&tracker);
                break;
            case 4:
                save_to_file(&tracker);
                break;
            case 5:
                load_from_file(&tracker);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
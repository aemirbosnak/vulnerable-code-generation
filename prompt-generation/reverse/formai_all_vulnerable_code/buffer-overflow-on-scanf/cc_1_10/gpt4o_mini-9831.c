//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char category[50];
    float amount;
} Expense;

typedef struct {
    float income;
    float total_expenses;
    float savings;
    Expense expenses[MAX_ENTRIES];
    int expense_count;
} PersonalFinance;

void initialize_finance(PersonalFinance *finance) {
    finance->income = 0.0;
    finance->total_expenses = 0.0;
    finance->savings = 0.0;
    finance->expense_count = 0;
}

void input_income(PersonalFinance *finance) {
    printf("Enter your monthly income: ");
    scanf("%f", &(finance->income));
}

void add_expense(PersonalFinance *finance) {
    if (finance->expense_count >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    Expense new_expense;
    printf("Enter expense category: ");
    scanf("%s", new_expense.category);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    
    finance->expenses[finance->expense_count] = new_expense;
    finance->total_expenses += new_expense.amount;
    finance->expense_count++;
}

void display_expenses(PersonalFinance *finance) {
    printf("\n=== Expenses ===\n");
    for (int i = 0; i < finance->expense_count; i++) {
        printf("Category: %s | Amount: %.2f\n", finance->expenses[i].category, finance->expenses[i].amount);
    }
    printf("Total Expenses: %.2f\n", finance->total_expenses);
}

void calculate_savings(PersonalFinance *finance) {
    finance->savings = finance->income - finance->total_expenses;
    printf("Your savings for this month: %.2f\n", finance->savings);
}

void display_summary(PersonalFinance *finance) {
    printf("\n=== Summary ===\n");
    printf("Monthly Income: %.2f\n", finance->income);
    display_expenses(finance);
    calculate_savings(finance);
}

void save_to_file(PersonalFinance *finance) {
    FILE *file = fopen("finance_summary.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fprintf(file, "Monthly Income: %.2f\n", finance->income);
    fprintf(file, "Total Expenses: %.2f\n", finance->total_expenses);
    fprintf(file, "Savings: %.2f\n", finance->savings);
    fprintf(file, "=== Expenses ===\n");
    
    for (int i = 0; i < finance->expense_count; i++) {
        fprintf(file, "Category: %s | Amount: %.2f\n", finance->expenses[i].category, finance->expenses[i].amount);
    }
    
    fclose(file);
    printf("Summary saved to finance_summary.txt\n");
}

int main() {
    PersonalFinance finance;
    int choice;

    initialize_finance(&finance);
    
    while (1) {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Input Monthly Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Expenses\n");
        printf("4. Display Summary\n");
        printf("5. Save Summary to File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_income(&finance);
                break;
            case 2:
                add_expense(&finance);
                break;
            case 3:
                display_expenses(&finance);
                break;
            case 4:
                display_summary(&finance);
                break;
            case 5:
                save_to_file(&finance);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
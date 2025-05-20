//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    int year;
    int month;
    float amount;
    char category[50];
};

void addExpense(struct Expense* expense, int* expense_count) {
    printf("Add Expense:\n");
    printf("Year: ");
    scanf("%d", &expense[*expense_count].year);
    printf("Month: ");
    scanf("%d", &expense[*expense_count].month);
    printf("Amount: ");
    scanf("%f", &expense[*expense_count].amount);
    printf("Category: ");
    scanf("%s", &expense[*expense_count].category);
    (*expense_count)++;
}

void displayExpenses(struct Expense* expense, int expense_count) {
    printf("Expenses:\n");
    printf("%-10s%-10s%-15s%-50s\n", "Year", "Month", "Amount", "Category");
    for(int i=0; i<expense_count; i++) {
        printf("%-10d%-10d%-15.2f%-50s\n", expense[i].year, expense[i].month, expense[i].amount, expense[i].category);
    }
}

void totalExpenses(struct Expense* expense, int expense_count) {
    float total_expenses = 0;
    for(int i=0; i<expense_count; i++) {
        total_expenses += expense[i].amount;
    }
    printf("Total Expenses: %.2f\n", total_expenses);
}

void searchExpense(struct Expense* expense, int expense_count) {
    int year, month;
    float min_amount, max_amount;
    char category[50];
    int results[expense_count], result_count = 0;
    printf("Search Expense:\n");
    printf("Year: ");
    scanf("%d", &year);
    printf("Month: ");
    scanf("%d", &month);
    printf("Minimum Amount: ");
    scanf("%f", &min_amount);
    printf("Maximum Amount: ");
    scanf("%f", &max_amount);
    printf("Category: ");
    scanf("%s", &category);
    for(int i=0; i<expense_count; i++) {
        if(expense[i].year == year && expense[i].month == month && expense[i].amount >= min_amount && expense[i].amount <= max_amount && strcmp(expense[i].category, category) == 0) {
            results[result_count] = i;
            result_count++;
        }
    }
    printf("%-10s%-10s%-15s%-50s\n", "Year", "Month", "Amount", "Category");
    for(int i=0; i<result_count; i++) {
        printf("%-10d%-10d%-15.2f%-50s\n", expense[results[i]].year, expense[results[i]].month, expense[results[i]].amount, expense[results[i]].category);
    }
}

int main() {
    struct Expense expenses[100];
    int expense_count = 0;
    int choice;
    while(1) {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Search Expense\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenses, &expense_count);
                break;
            case 2:
                displayExpenses(expenses, expense_count);
                break;
            case 3:
                totalExpenses(expenses, expense_count);
                break;
            case 4:
                searchExpense(expenses, expense_count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}